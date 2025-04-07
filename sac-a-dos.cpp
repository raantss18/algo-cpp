#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Fonction récursive pour explorer toutes les combinaisons possibles
int sac_a_dos_backtracking(int index, int poids_actuel, int valeur_actuelle,
                           int capacite_max, const vector<int>& poids,
                           const vector<int>& valeurs, int meilleure_valeur) {
    // Si le poids dépasse la capacité, cette solution est invalide
    if (poids_actuel > capacite_max) {
        return meilleure_valeur;
    }

    // Met à jour la meilleure valeur si la solution actuelle est meilleure
    meilleure_valeur = max(meilleure_valeur, valeur_actuelle);

    // Si tous les objets ont été explorés, on retourne la meilleure valeur trouvée
    if (index == poids.size()) {
        return meilleure_valeur;
    }

    // Cas 1 : Ne pas inclure l'objet actuel
    meilleure_valeur = sac_a_dos_backtracking(index + 1, poids_actuel, valeur_actuelle,
                                              capacite_max, poids, valeurs, meilleure_valeur);

    // Cas 2 : Inclure l'objet actuel (si possible)
    meilleure_valeur = sac_a_dos_backtracking(index + 1, poids_actuel + poids[index],
                                              valeur_actuelle + valeurs[index],
                                              capacite_max, poids, valeurs, meilleure_valeur);

    return meilleure_valeur;
}

// Fonction principale qui initialise la recherche par backtracking
int sac_a_dos_01_backtracking(int capacite_max, const vector<int>& poids, const vector<int>& valeurs) {
    return sac_a_dos_backtracking(0, 0, 0, capacite_max, poids, valeurs, 0);
}

int main() {
    // Définition des objets avec leur poids et valeur
    int capacite_max = 10;
    vector<int> poids = {5, 3, 4, 5};  // Poids des objets
    vector<int> valeurs = {14, 30, 16, 9};  // Valeurs des objets

    // Exécution de l'algorithme
    int meilleure_valeur = sac_a_dos_01_backtracking(capacite_max, poids, valeurs);

    // Affichage du résultat
    cout << "Valeur maximale obtenue (Backtracking) : " << meilleure_valeur << endl;

    return 0;
}
