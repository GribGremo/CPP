/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grib <grib@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 17:20:44 by sylabbe           #+#    #+#             */
/*   Updated: 2025/10/31 09:24:30 by grib             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main(int argc, char** argv){
    RPN cal;
(void)argv;
    if (argc != 2)
    {
        std::cerr << "Error: Invalid number of arguments" <<std::endl; 
        return (1);
    }

    cal = RPN(argv[1]);
    cal.printResult();

    return (0);
}

/*
"8"                 → 8
"0"                 → 0
"9"                 → 9
"3 4 +"             → 7
"5 2 -"             → 3
"2 3 *"             → 6
"8 2 /"             → 4
"1 2 + 3 +"         → 6
"9 3 / 2 -"         → 1
"5 1 2 + 4 * + 3 -" → 14
"7 7 * 7 -"         → 42
"9 8 * 7 * 6 *"     → 3024
"4 2 / 2 *"         → 4
"0 5 +"             → 5
"9 1 -"             → 8
```

## Exemples RPN invalides ✗
```
"3 4"               → Erreur: 2 éléments dans la stack (pas d'opérateur)
"+ 3 4"             → Erreur: opérateur avant d'avoir 2 nombres
"3 +"               → Erreur: pas assez d'opérandes (besoin de 2)
"3 4 + +"           → Erreur: trop d'opérateurs
""                  → Erreur: vide
"3  4 +"            → Erreur: double espace
"3 4+"              → Erreur: pas d'espace avant l'opérateur
"3 4 + 5"           → Erreur: 2 éléments restants dans la stack
"10 2 +"            → Erreur: 10 n'est pas un chiffre unique (0-9)
"3 4 5 + *"         → Valide! → 27
"3 4 5 * +"         → Valide! → 23
"5 0 /"             → Erreur: division par zéro
"-3 4 +"            → Erreur: nombre négatif en input
"3.5 2 +"           → Erreur: pas un entier
"3 4 &"             → Erreur: opérateur non autorisé
"a b +"             → Erreur: pas des chiffres
"3 4 + "            → Attention: espace final (selon ton parsing)
" 3 4 +"            → Attention: espace initial (selon ton parsing)
*/