/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylabbe <sylabbe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 16:00:12 by sylabbe           #+#    #+#             */
/*   Updated: 2025/01/21 17:01:02 by sylabbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

template<typename T>
void easyfind(T t, int n){
    for (T::iterator it = std::find(t.begin()); i < t.size() ; i++){ // A VOIR size end ou autre
        if (t[i] == n)
        {
            std::cout << "Find occurence of " << n << "at index " << i << std::endl; 
            return ;
        }
    }
    std::cout << "No occurence of " << n << "found in container" << std::endl;
     
}

/*
Pour créer une fonction easyfind capable de rechercher une valeur dans un conteneur quelconque, vous devez utiliser des itérateurs au lieu d'accéder directement aux éléments par index. Tous les conteneurs STL (comme std::vector, std::list, std::set, etc.) supportent les itérateurs, mais seuls certains (comme std::vector) permettent l'accès par index.

Voici une version générique et corrigée de easyfind qui fonctionne avec n'importe quel conteneur compatible avec les itérateurs :

Solution avec itérateurs
cpp
Copy
Edit
#include <iostream>
#include <algorithm> // Pour std::find
#include <vector>
#include <list>

template<typename T>
void easyfind(T& container, int value) {
    // Utilisation de std::find pour rechercher la valeur
    typename T::iterator it = std::find(container.begin(), container.end(), value);

    if (it != container.end()) {
        std::cout << "Found occurrence of " << value 
                  << " at index " << std::distance(container.begin(), it) << std::endl;
    } else {
        std::cout << "No occurrence of " << value << " found in container" << std::endl;
    }
}

int main() {
    std::vector<int> vec = {1, 2, 3, 4, 5};
    easyfind(vec, 3); // Trouve 3

    std::list<int> lst = {10, 20, 30, 40};
    easyfind(lst, 25); // Ne trouve pas 25

    return 0;
}
Explication du code
std::find :

La fonction std::find est une fonction standard de la STL.
Elle parcourt un conteneur à l'aide d'itérateurs et retourne un itérateur pointant vers la première occurrence de l'élément recherché, ou container.end() si l'élément n'est pas trouvé.
Utilisation des itérateurs :

Pour garantir la compatibilité avec tout type de conteneur, on utilise typename T::iterator.
Cela permet à la fonction de travailler avec des types comme std::vector, std::list, ou même std::deque.
Calcul de l'index :

La fonction std::distance est utilisée pour calculer la distance entre container.begin() et l'itérateur renvoyé par std::find. Cela donne l'index de l'élément trouvé.
Notez que l'index n'a pas de sens dans un conteneur comme std::list, mais cela reste une manière de décrire la position relative.
Conteneurs compatibles :

Cette version fonctionne avec tout conteneur qui supporte les itérateurs (par exemple, std::vector, std::list, std::deque, etc.).
Avantages de cette approche
Compatible avec tous les conteneurs STL.
Utilise les outils standard de la STL (std::find), rendant le code clair et concis.
Ne dépend pas de l'accès par index ([]), ce qui le rend générique.
Note
Si vous travaillez uniquement avec des conteneurs spécifiques qui supportent l'accès par index (std::vector, std::deque), votre approche initiale pourrait fonctionner, mais elle serait limitée et non générique.
*/