#!/bin/bash

# Configuration
PROGRAM="./PmergeMe"
LOG_FILE="test_results.log"
ERROR_DIR="errors"
VALGRIND_CMD="valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes "#--verbose

# Couleurs pour l'affichage
RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[1;33m'
BLUE='\033[0;34m'
NC='\033[0m' # No Color

# Compteurs
TOTAL_TESTS=0
PASSED_TESTS=0
FAILED_TESTS=0

# Créer le dossier d'erreurs s'il n'existe pas
mkdir -p "$ERROR_DIR"

# Initialiser le fichier de log
echo "========================================" >> "$LOG_FILE"
echo "Test session: $(date)" >> "$LOG_FILE"
echo "========================================" >> "$LOG_FILE"

# Fonction pour afficher et logger
log_message() {
    echo -e "$1"
    echo -e "$1" | sed 's/\x1b\[[0-9;]*m//g' >> "$LOG_FILE"
}

# Fonction pour tester avec Valgrind en cas d'erreur
run_with_valgrind() {
    local test_name="$1"
    local args="$2"
    local error_file="$ERROR_DIR/error_${test_name}_$(date +%Y%m%d_%H%M%S)"
    
    # Sauvegarder les arguments complets pour pouvoir reproduire
    echo "Test: $test_name" > "${error_file}_args.txt"
    echo "Date: $(date)" >> "${error_file}_args.txt"
    echo "========================================" >> "${error_file}_args.txt"
    echo "" >> "${error_file}_args.txt"
    echo "Complete arguments:" >> "${error_file}_args.txt"
    echo "$args" >> "${error_file}_args.txt"
    echo "" >> "${error_file}_args.txt"
    echo "To reproduce:" >> "${error_file}_args.txt"
    echo "$PROGRAM $args" >> "${error_file}_args.txt"
    
    # Exécuter avec Valgrind
    $VALGRIND_CMD $PROGRAM $args > "${error_file}_valgrind.log" 2>&1
    
    echo -e "  ${RED}→ Error files: ${error_file}_*${NC}"
}

# Fonction de test générique
run_test() {
    local test_name="$1"
    local args="$2"
    local description="$3"
    
    TOTAL_TESTS=$((TOTAL_TESTS + 1))
    
    # Compter le nombre d'éléments
    local num_elements=$(echo "$args" | wc -w)
    
    # Affichage compact
    echo -e "\n${BLUE}[Test #$TOTAL_TESTS]${NC} $description (${num_elements} elements)"
    
    # Exécuter le programme
    output=$($PROGRAM $args 2>&1)
    exit_code=$?
    
    # Vérifier le résultat
    if [ $exit_code -eq 0 ]; then
        # Vérifier que la sortie contient quelque chose
        if [ -n "$output" ]; then
            PASSED_TESTS=$((PASSED_TESTS + 1))
            echo -e "${GREEN}✓ PASS${NC}"
            echo "  Test: $test_name - PASS ($num_elements elements)" >> "$LOG_FILE"
        else
            FAILED_TESTS=$((FAILED_TESTS + 1))
            echo -e "${RED}✗ FAIL${NC} - empty output"
            echo "  Test: $test_name - FAIL (empty output, $num_elements elements)" >> "$LOG_FILE"
            run_with_valgrind "$test_name" "$args"
        fi
    else
        FAILED_TESTS=$((FAILED_TESTS + 1))
        echo -e "${RED}✗ FAIL${NC} - exit code: $exit_code"
        echo "  Test: $test_name - FAIL (exit code: $exit_code, $num_elements elements)" >> "$LOG_FILE"
        
        # Lancer Valgrind sur les échecs
        run_with_valgrind "$test_name" "$args"
    fi
    echo "" >> "$LOG_FILE"
}

# ========================================
# DÉBUT DES TESTS
# ========================================

log_message "\n${BLUE}━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━${NC}"
log_message "${BLUE}    TESTS DE ROBUSTESSE - PmergeMe    ${NC}"
log_message "${BLUE}━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━${NC}"

# 1. TESTS DE CAS LIMITES
log_message "\n${YELLOW}═══ 1. CAS LIMITES ═══${NC}"

run_test "empty" "" "Liste vide"
run_test "single" "42" "Un seul élément"
run_test "two_sorted" "1 2" "Deux éléments (déjà triés)"
run_test "two_reverse" "2 1" "Deux éléments (ordre inverse)"
run_test "three" "3 1 2" "Trois éléments"

# 2. TESTS DE PETITES TAILLES (validité algorithmique)
log_message "\n${YELLOW}═══ 2. PETITES TAILLES ═══${NC}"

for size in 4 5 7 8 15 16 31 32; do
    args=$(shuf -i 1-1000 -n $size | tr "\n" " ")
    run_test "size_$size" "$args" "Taille: $size éléments"
done

# 3. TESTS AVEC DOUBLONS
log_message "\n${YELLOW}═══ 3. DOUBLONS ═══${NC}"

run_test "all_same" "5 5 5 5 5 5 5 5" "Tous identiques"
run_test "many_duplicates" "$(shuf -i 1-10 -n 50 -r | tr '\n' ' ')" "Beaucoup de doublons"
run_test "some_duplicates" "$(shuf -i 1-100 -n 100 -r | tr '\n' ' ')" "Quelques doublons"

# 4. TESTS DÉJÀ TRIÉS / INVERSÉS
log_message "\n${YELLOW}═══ 4. CAS EXTRÊMES D'ORDRE ═══${NC}"

run_test "sorted_100" "$(seq 1 100 | tr '\n' ' ')" "100 éléments déjà triés"
run_test "reverse_100" "$(seq 100 -1 1 | tr '\n' ' ')" "100 éléments en ordre inverse"
run_test "sorted_1000" "$(seq 1 1000 | tr '\n' ' ')" "1000 éléments déjà triés"

# 5. TESTS DE TAILLES PUISSANCES DE 2 (important pour Ford-Johnson)
log_message "\n${YELLOW}═══ 5. PUISSANCES DE 2 ═══${NC}"

for power in 6 7 8 9 10; do
    size=$((2**power))
    args=$(shuf -i 1-100000 -n $size | tr "\n" " ")
    run_test "power2_$size" "$args" "Taille 2^$power = $size éléments"
done

# 6. TESTS DE TAILLES 2^n - 1 (pire cas théorique)
log_message "\n${YELLOW}═══ 6. TAILLES 2^n - 1 ═══${NC}"

for power in 6 7 8 9 10; do
    size=$((2**power - 1))
    args=$(shuf -i 1-100000 -n $size | tr "\n" " ")
    run_test "power2minus1_$size" "$args" "Taille 2^$power - 1 = $size éléments"
done

# 7. TESTS DE TAILLES 2^n + 1
log_message "\n${YELLOW}═══ 7. TAILLES 2^n + 1 ═══${NC}"

for power in 6 7 8 9; do
    size=$((2**power + 1))
    args=$(shuf -i 1-100000 -n $size | tr "\n" " ")
    run_test "power2plus1_$size" "$args" "Taille 2^$power + 1 = $size éléments"
done

# 8. TESTS DE TAILLES JACOBSTHAL
log_message "\n${YELLOW}═══ 8. TAILLES JACOBSTHAL ═══${NC}"

jacobsthal=(1 3 5 11 21 43 85 171 341 683)
for size in "${jacobsthal[@]}"; do
    args=$(shuf -i 1-100000 -n $size | tr "\n" " ")
    run_test "jacobsthal_$size" "$args" "Taille Jacobsthal: $size éléments"
done

# 9. TESTS DE GROSSES TAILLES (performance)
log_message "\n${YELLOW}═══ 9. GROSSES TAILLES ═══${NC}"

for size in 1000 2000 3000 5000; do
    args=$(shuf -i 1-100000 -n $size | tr "\n" " ")
    run_test "large_$size" "$args" "Grande taille: $size éléments"
done

# 10. TESTS AVEC VALEURS EXTRÊMES
log_message "\n${YELLOW}═══ 10. VALEURS EXTRÊMES ═══${NC}"

run_test "max_int" "2147483647 2147483646 1 0" "Valeurs proches INT_MAX"
run_test "large_range" "$(shuf -i 1-2147483647 -n 100 | tr '\n' ' ')" "Large range de valeurs"

# 11. TESTS ALÉATOIRES RÉPÉTÉS
log_message "\n${YELLOW}═══ 11. TESTS ALÉATOIRES MULTIPLES ═══${NC}"

for i in {1..20}; do
    size=$((RANDOM % 1000 + 100))
    args=$(shuf -i 1-100000 -n $size | tr "\n" " ")
    run_test "random_$i" "$args" "Test aléatoire #$i"
done

# ========================================
# RÉSUMÉ FINAL
# ========================================

log_message "\n${BLUE}━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━${NC}"
log_message "${BLUE}         RÉSUMÉ DES TESTS             ${NC}"
log_message "${BLUE}━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━${NC}"

log_message "\nTotal: $TOTAL_TESTS tests"
log_message "${GREEN}Passed: $PASSED_TESTS${NC}"
log_message "${RED}Failed: $FAILED_TESTS${NC}"

if [ $FAILED_TESTS -eq 0 ]; then
    log_message "\n${GREEN}🎉 ALL TESTS PASSED! 🎉${NC}"
    success_rate=100
else
    success_rate=$((PASSED_TESTS * 100 / TOTAL_TESTS))
    log_message "\n${YELLOW}Success rate: ${success_rate}%${NC}"
    log_message "${RED}Check error files in '$ERROR_DIR/' directory${NC}"
fi

echo "" >> "$LOG_FILE"
echo "Summary: $PASSED_TESTS/$TOTAL_TESTS passed ($success_rate%)" >> "$LOG_FILE"
echo "========================================" >> "$LOG_FILE"

# Afficher le chemin du log
log_message "\n${BLUE}Full log saved to: $LOG_FILE${NC}"

exit $FAILED_TESTS