#!/bin/bash

PROGRAM="./PmergeMe"
TOTAL=0
PASSED=0
FAILED=0

RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[1;33m'
BLUE='\033[0;34m'
NC='\033[0m'

test_case() {
    local name="$1"
    local args="$2"
    
    TOTAL=$((TOTAL + 1))
    
    echo -ne "${BLUE}[Test $TOTAL]${NC} $name ... "
    
    # Exécuter le programme
    output=$($PROGRAM $args 2>&1)
    exit_code=$?
    
    # Vérifier exit code
    if [ $exit_code -ne 0 ]; then
        echo -e "${RED}CRASH (exit $exit_code)${NC}"
        FAILED=$((FAILED + 1))
        echo "$args" > "crash_$TOTAL.txt"
        return
    fi
    
    # Vérifier SORTED: TRUE
    if echo "$output" | grep -q "SORTED: TRUE"; then
        echo -e "${GREEN}PASS${NC}"
        PASSED=$((PASSED + 1))
    else
        echo -e "${RED}FAIL (not sorted)${NC}"
        FAILED=$((FAILED + 1))
        echo "Args: $args" > "fail_$TOTAL.txt"
        echo "$output" >> "fail_$TOTAL.txt"
    fi
}

echo -e "${BLUE}========================================${NC}"
echo -e "${BLUE}   TESTS PMERGEME - Ford-Johnson      ${NC}"
echo -e "${BLUE}========================================${NC}\n"

# CAS LIMITES
echo -e "${YELLOW}=== CAS LIMITES ===${NC}"
test_case "1 élément" "42"
test_case "2 éléments (triés)" "1 2"
test_case "2 éléments (inversés)" "2 1"
test_case "3 éléments" "3 1 2"
test_case "4 éléments" "4 2 3 1"
test_case "5 éléments" "5 3 1 4 2"

# PETITES TAILLES
echo -e "\n${YELLOW}=== PETITES TAILLES ===${NC}"
for size in 6 7 8 10 15 16 20 31 32 50; do
    args=$(shuf -i 1-1000 -n $size | tr '\n' ' ')
    test_case "$size éléments" "$args"
done

# DOUBLONS
echo -e "\n${YELLOW}=== DOUBLONS ===${NC}"
test_case "Tous identiques" "5 5 5 5 5 5 5 5"
test_case "Beaucoup doublons" "$(shuf -i 1-10 -n 50 -r | tr '\n' ' ')"
test_case "Quelques doublons" "$(shuf -i 1-100 -n 100 -r | tr '\n' ' ')"

# DÉJÀ TRIÉS / INVERSÉS
echo -e "\n${YELLOW}=== ORDRE EXTRÊME ===${NC}"
test_case "100 triés" "$(seq 1 100 | tr '\n' ' ')"
test_case "100 inversés" "$(seq 100 -1 1 | tr '\n' ' ')"
test_case "1000 triés" "$(seq 1 1000 | tr '\n' ' ')"

# PUISSANCES DE 2
echo -e "\n${YELLOW}=== PUISSANCES DE 2 ===${NC}"
for power in 6 7 8 9 10; do
    size=$((2**power))
    args=$(shuf -i 1-100000 -n $size | tr '\n' ' ')
    test_case "2^$power ($size)" "$args"
done

# 2^n - 1
echo -e "\n${YELLOW}=== 2^n - 1 ===${NC}"
for power in 6 7 8 9 10; do
    size=$((2**power - 1))
    args=$(shuf -i 1-100000 -n $size | tr '\n' ' ')
    test_case "2^$power-1 ($size)" "$args"
done

# 2^n + 1
echo -e "\n${YELLOW}=== 2^n + 1 ===${NC}"
for power in 6 7 8 9; do
    size=$((2**power + 1))
    args=$(shuf -i 1-100000 -n $size | tr '\n' ' ')
    test_case "2^$power+1 ($size)" "$args"
done

# JACOBSTHAL
echo -e "\n${YELLOW}=== JACOBSTHAL ===${NC}"
for size in 1 3 5 11 21 43 85 171 341 683; do
    args=$(shuf -i 1-100000 -n $size | tr '\n' ' ')
    test_case "J($size)" "$args"
done

# GROSSES TAILLES
echo -e "\n${YELLOW}=== GROSSES TAILLES ===${NC}"
for size in 1000 2000 3000 5000; do
    args=$(shuf -i 1-100000 -n $size | tr '\n' ' ')
    test_case "$size éléments" "$args"
done

# VALEURS EXTRÊMES
echo -e "\n${YELLOW}=== VALEURS EXTRÊMES ===${NC}"
test_case "INT_MAX" "2147483647 2147483646 1 0"
test_case "Large range" "$(shuf -i 1-2147483647 -n 100 | tr '\n' ' ')"

# TESTS ALÉATOIRES
echo -e "\n${YELLOW}=== TESTS ALÉATOIRES ===${NC}"
for i in {1..50}; do
    size=$((RANDOM % 1000 + 100))
    args=$(shuf -i 1-100000 -n $size | tr '\n' ' ')
    test_case "Random #$i ($size)" "$args"
done

# TON TEST
echo -e "\n${YELLOW}=== TEST SPÉCIFIQUE ===${NC}"
test_case "Custom" "11 2 17 0 16 8 6 15 10 3 21 1 18 9 14 19 12 5 4 20 13 7"
test_case "Custom" "5 4 3 2 1"
test_case "Custom" "5 4 3 1 2"
test_case "Custom" "5 4 2 3 1"
test_case "Custom" "5 4 2 1 3"
test_case "Custom" "5 4 1 3 2"
test_case "Custom" "5 4 1 2 3"
test_case "Custom" "5 3 4 2 1"
test_case "Custom" "5 3 4 1 2"
test_case "Custom" "5 3 2 4 1"
test_case "Custom" "5 3 2 1 4"
test_case "Custom" "5 3 1 4 2"
test_case "Custom" "5 3 1 2 4"
test_case "Custom" "5 2 4 3 1"
test_case "Custom" "5 2 4 1 3"
test_case "Custom" "5 2 3 4 1"
test_case "Custom" "5 2 3 1 4"
test_case "Custom" "5 2 1 4 3"
test_case "Custom" "5 2 1 3 4"
test_case "Custom" "5 1 4 3 2"
test_case "Custom" "5 1 4 2 3"
test_case "Custom" "5 1 3 4 2"
test_case "Custom" "5 1 3 2 4"
test_case "Custom" "5 1 2 4 3"
test_case "Custom" "5 1 2 3 4"
test_case "Custom" "4 5 3 2 1"
test_case "Custom" "4 5 3 1 2"
test_case "Custom" "4 5 2 3 1"
test_case "Custom" "4 5 2 1 3"
test_case "Custom" "4 5 1 3 2"
test_case "Custom" "4 5 1 2 3"
test_case "Custom" "4 3 5 2 1"
test_case "Custom" "4 3 5 1 2"
test_case "Custom" "4 3 2 5 1"
test_case "Custom" "4 3 2 1 5"
test_case "Custom" "4 3 1 5 2"
test_case "Custom" "4 3 1 2 5"
test_case "Custom" "4 2 5 3 1"
test_case "Custom" "4 2 5 1 3"
test_case "Custom" "4 2 3 5 1"
test_case "Custom" "4 2 3 1 5"
test_case "Custom" "4 2 1 5 3"
test_case "Custom" "4 2 1 3 5"
test_case "Custom" "4 1 5 3 2"
test_case "Custom" "4 1 5 2 3"
test_case "Custom" "4 1 3 5 2"
test_case "Custom" "4 1 3 2 5"
test_case "Custom" "4 1 2 5 3"
test_case "Custom" "4 1 2 3 5"
test_case "Custom" "3 5 4 2 1"
test_case "Custom" "3 5 4 1 2"
test_case "Custom" "3 5 2 4 1"
test_case "Custom" "3 5 2 1 4"
test_case "Custom" "3 5 1 4 2"
test_case "Custom" "3 5 1 2 4"
test_case "Custom" "3 4 5 2 1"
test_case "Custom" "3 4 5 1 2"
test_case "Custom" "3 4 2 5 1"
test_case "Custom" "3 4 2 1 5"
test_case "Custom" "3 4 1 5 2"
test_case "Custom" "3 4 1 2 5"
test_case "Custom" "3 2 5 4 1"
test_case "Custom" "3 2 5 1 4"
test_case "Custom" "3 2 4 5 1"
test_case "Custom" "3 2 4 1 5"
test_case "Custom" "3 2 1 5 4"
test_case "Custom" "3 2 1 4 5"
test_case "Custom" "3 1 5 4 2"
test_case "Custom" "3 1 5 2 4"
test_case "Custom" "3 1 4 5 2"
test_case "Custom" "3 1 4 2 5"
test_case "Custom" "3 1 2 5 4"
test_case "Custom" "3 1 2 4 5"
test_case "Custom" "2 5 4 3 1"
test_case "Custom" "2 5 4 1 3"
test_case "Custom" "2 5 3 4 1"
test_case "Custom" "2 5 3 1 4"
test_case "Custom" "2 5 1 4 3"
test_case "Custom" "2 5 1 3 4"
test_case "Custom" "2 4 5 3 1"
test_case "Custom" "2 4 5 1 3"
test_case "Custom" "2 4 3 5 1"
test_case "Custom" "2 4 3 1 5"
test_case "Custom" "2 4 1 5 3"
test_case "Custom" "2 4 1 3 5"
test_case "Custom" "2 3 5 4 1"
test_case "Custom" "2 3 5 1 4"
test_case "Custom" "2 3 4 5 1"
test_case "Custom" "2 3 4 1 5"
test_case "Custom" "2 3 1 5 4"
test_case "Custom" "2 3 1 4 5"
test_case "Custom" "2 1 5 4 3"
test_case "Custom" "2 1 5 3 4"
test_case "Custom" "2 1 4 5 3"
test_case "Custom" "2 1 4 3 5"
test_case "Custom" "2 1 3 5 4"
test_case "Custom" "2 1 3 4 5"
test_case "Custom" "1 5 4 3 2"
test_case "Custom" "1 5 4 2 3"
test_case "Custom" "1 5 3 4 2"
test_case "Custom" "1 5 3 2 4"
test_case "Custom" "1 5 2 4 3"
test_case "Custom" "1 5 2 3 4"
test_case "Custom" "1 4 5 3 2"
test_case "Custom" "1 4 5 2 3"
test_case "Custom" "1 4 3 5 2"
test_case "Custom" "1 4 3 2 5"
test_case "Custom" "1 4 2 5 3"
test_case "Custom" "1 4 2 3 5"
test_case "Custom" "1 3 5 4 2"
test_case "Custom" "1 3 5 2 4"
test_case "Custom" "1 3 4 5 2"
test_case "Custom" "1 3 4 2 5"
test_case "Custom" "1 3 2 5 4"
test_case "Custom" "1 3 2 4 5"
test_case "Custom" "1 2 5 4 3"
test_case "Custom" "1 2 5 3 4"
test_case "Custom" "1 2 4 5 3"
test_case "Custom" "1 2 4 3 5"
test_case "Custom" "1 2 3 5 4"
test_case "Custom" "1 2 3 4 5"

# ==== Cas très petits ====
test_case "Custom" "1"
test_case "Custom" "1 2"
test_case "Custom" "2 1"
test_case "Custom" "1 2 3"
test_case "Custom" "3 2 1"
test_case "Custom" "2 1 3"

# ==== Cas de taille moyenne ====
test_case "Custom" "1 2 3 4 5"
test_case "Custom" "5 4 3 2 1"
test_case "Custom" "3 5 1 4 2"
test_case "Custom" "2 4 5 1 3"
test_case "Custom" "1 2 3 4 5 6 7"
test_case "Custom" "7 6 5 4 3 2 1"
test_case "Custom" "4 1 6 3 7 2 5"

# ==== Cas de stress (10 éléments) ====
test_case "Custom" "1 2 3 4 5 6 7 8 9 10"
test_case "Custom" "10 9 8 7 6 5 4 3 2 1"
test_case "Custom" "3 9 1 6 10 4 2 8 5 7"
test_case "Custom" "5 2 9 1 7 10 8 3 6 4"

# ==== Cas pathologiques ====
test_case "Custom" "5 5 5 5 5"
test_case "Custom" "1 2 2 3 4 4 5"

# ==== Cas grande taille (20 éléments) ====
test_case "Custom" "1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20"
test_case "Custom" "20 19 18 17 16 15 14 13 12 11 10 9 8 7 6 5 4 3 2 1"
test_case "Custom" "11 2 17 0 16 8 6 15 10 3 21 1 18 9 14 19 12 5 4 20 13 7"


# RÉSUMÉ
echo -e "\n${BLUE}========================================${NC}"
echo -e "${BLUE}              RÉSUMÉ                    ${NC}"
echo -e "${BLUE}========================================${NC}"
echo -e "Total:  $TOTAL tests"
echo -e "${GREEN}Passed: $PASSED${NC}"
echo -e "${RED}Failed: $FAILED${NC}"

if [ $FAILED -eq 0 ]; then
    echo -e "\n${GREEN}🎉 ALL TESTS PASSED! 🎉${NC}"
else
    echo -e "\n${RED}⚠️  Some tests failed. Check fail_*.txt files${NC}"
fi

exit $FAILED