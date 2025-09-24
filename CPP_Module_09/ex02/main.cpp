/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylabbe <sylabbe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 17:20:55 by sylabbe           #+#    #+#             */
/*   Updated: 2025/09/24 15:40:05 by sylabbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <list>
#include <time.h>

//temp
#include <unistd.h>
#include <iomanip>
#include <sys/time.h>


template <typename T>

struct result{
    T sorted;
    T unsorted;
    double execTime;


    Result(const Container& sorted, const Container& unsorted, double time)
        : sorted(sorted), unsorted(unsorted), execTime(time) {}
};

long time_diff_microseconds(const timeval& start, const timeval& end) {
    return (end.tv_sec - start.tv_sec) * 1000000L + (end.tv_usec - start.tv_usec);
}


template <typename T >

T& sortFJ(T container){
    (void)container;

    return(temp);
}

void printFJ(){
    
}


template <typename T >

T timeSort(T container, double& time){
    timeval start;
    timeval end;
    
    gettimeofday(&start,NULL);

    parseArgs(container);
    sortFJ();

    gettimeofday(&end,NULL);
    time = (end.tv_sec - start.tv_sec) *1000000L + (end.tv_usec - start.tv_usec);
    return (container);
}

int main(int argc, char **argv){
    (void)argv;
    result rVec(std::vector<int> sorted, std::vector<int> unsorted, double d);
    std::vector<int> vec;
    std::list<int> lst;
    double timeVec = 0.0;
    double timeLst = 0.0;

    timeSort(vec, timeVec);
    timeSort(lst, timeLst);



    // printFJ();

    
}

/*Ford-Johnson algorithm 
-
-
-
-
-


-Jacobsthal:0,1,n= n-1 + 2(n-2)(1 + (2*0)= 1), (1 + (2*1) = 3, (3+(2*1) = 5),(5+(2*3) = 11));
array[0] = 0;
array[1] = 1;


for (int i = 2; i < lim ; i++)
array[i] = array(i - 1) + (2 * array[i - 2]);

For calculate Jnum at index i: J[i] = (2expi - (-1)expi) / 3; pour i =5 array[5] = 2exp5(32) - (-1)exp5(-1) = 33 / 3 = 11;

<pair>
*/

/*

Okay quelle est la difference entre definir a quoi correspond un template a l'aide des arguments ou a l'aide de <>?

Très bonne question, et elle touche à une distinction essentielle en programmation C++ avec les templates.

Tu demandes quelle est la différence entre :

Définir un template "à l’aide des arguments" → comme dans une fonction qui prend des paramètres

Définir un template "à l’aide de <>" → comme dans une spécialisation explicite ou un appel de fonction template

🧠 Commençons par clarifier :

Il y a deux façons principales de spécifier ou laisser déduire les types templates :

🔹 1. Spécification explicite avec <>

Tu dis au compilateur exactement quel type utiliser pour le template.

🔧 Exemple :

template <typename T>
void afficher(T val) {
    std::cout << val << "\n";
}

int main() {
    afficher<int>(42);         // <- Tu spécifies T = int avec <>
    afficher<std::string>("ok"); // <- Tu spécifies T = std::string
}
Tu forces T à être un int, un std::string, etc.
C’est clair, précis… et parfois nécessaire (on va voir quand).

🔹 2. Déduction automatique depuis les arguments

Le compilateur devine le type en fonction des arguments que tu passes à la fonction.

🔧 Exemple :
afficher(42);        // <- Le compilateur déduit T = int
afficher("salut");   // <- T = const char* (ou std::string si besoin)
🎯 Différence principale
Forme	Ce que tu fais	Quand l'utiliser
afficher<int>(42)	Tu imposes le type	Quand tu veux forcer un type précis
afficher(42)	Le compilateur déduit le type	Plus concis et flexible
✅ Cas des structures / classes templates

Pour les structures ou classes, tu dois toujours spécifier <>, car il n'y a pas d'arguments de fonction permettant la déduction.

🔧 Exemple :
template <typename T>
struct MaBoite {
    T contenu;
};

int main() {
    MaBoite<int> b;       // <- Obligatoire : tu dois spécifier le type
    b.contenu = 42;
}
Pas possible de faire :
MaBoite b(42);  // ❌ C++ ne peut pas deviner T ici (sauf avec C++17 et deduction guides)
✅ Cas des fonctions : déduction automatique possible
template <typename T>
void afficher(T valeur);

afficher(42);        // ✅ T est déduit automatiquement
afficher<int>(42);   // ✅ T est spécifié manuellement
🛠 Quand utiliser <> explicitement ?

Quand la déduction automatique échoue (ex : types ambigus)

Quand tu veux forcer un type différent de celui des arguments

Quand tu veux être très explicite pour des raisons de lisibilité ou sécurité

🧪 Exemple concret dans ton cas

Tu as une fonction comme ça :
template <typename Container>
Result<Container> makeResultFromArgs(int argc, char* argv[]);
Tu peux l’appeler de deux façons :

1. 🔍 Avec <> — tu spécifies le type :
Result<std::vector<int> > res = makeResultFromArgs<std::vector<int> >(argc, argv);
Tu dis toi-même : « Je veux un Result<std::vector<int>> ».

2. 🚫 Sans <> — le compilateur ne peut pas déduire tout seul ici :
makeResultFromArgs(argc, argv); // ❌ Erreur : il ne peut pas deviner Container
Pourquoi ? Parce que Container n’apparaît pas dans les paramètres — le compilateur ne peut rien deviner.

Donc ici, tu dois obligatoirement utiliser <std::vector<int>>.

✅ Résumé final
Situation	Peut-on éviter <> ?	Pourquoi
Fonctions	✅ Oui (grâce à déduction automatique)	Si les types sont clairs
Classes / Structs	❌ Non	Le compilateur n’a pas d'arguments pour déduire
Templates complexes	✅ / ❌ Parfois il faut aider le compilateur	Quand il ne peut pas deviner les types
*/