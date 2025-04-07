#include <iostream>
#include <cstdlib>   // pour rand() et srand()
#include <ctime>     // pour time()
using namespace std;


struct Noeud {
    int valeur;
    Noeud* suivant;
};

// ****************************
// 1) Ajouter un élément
// ****************************
void ajouterElement(Noeud*& tete, int valeur) {
    Noeud* nouveau = new Noeud;
    nouveau->valeur = valeur;
    nouveau->suivant = tete;
    tete = nouveau;
}

// ****************************
// 2) Afficher la liste
// ****************************
void afficherListe(Noeud* tete) {
    Noeud* courant = tete;
    while (courant != nullptr) {
        cout << courant->valeur << " ";
        courant = courant->suivant;
    }
    cout << endl;
}

// ****************************
// 3) Trouver le milieu
// ****************************
Noeud* trouverMilieu(Noeud* tete) {
    if (tete == nullptr || tete->suivant == nullptr) {
        return tete;
    }

    Noeud* lent = tete;
    Noeud* rapide = tete->suivant;
    while (rapide != nullptr && rapide->suivant != nullptr) {
        lent = lent->suivant;
        rapide = rapide->suivant->suivant;
    }
    return lent;
}

// ****************************
// 4) Fusionner deux listes triées
// ****************************
Noeud* fusionner(Noeud* liste1, Noeud* liste2) {
    if (!liste1) return liste2;
    if (!liste2) return liste1;

    Noeud* debut = nullptr;

    if (liste1->valeur < liste2->valeur) {
        debut = liste1;
        liste1 = liste1->suivant;
    } else {
        debut = liste2;
        liste2 = liste2->suivant;
    }

    Noeud* courant = debut;

    while (liste1 && liste2) {
        if (liste1->valeur < liste2->valeur) {
            courant->suivant = liste1;
            liste1 = liste1->suivant;
        } else {
            courant->suivant = liste2;
            liste2 = liste2->suivant;
        }
        courant = courant->suivant;
    }
    if (liste1) {
        courant->suivant = liste1;
    } else {
        courant->suivant = liste2;
    }
    return debut;
}

// ****************************
// 5) TriFusion
// ****************************
Noeud* triFusion(Noeud* tete) {
    if (tete == nullptr || tete->suivant == nullptr) {
        return tete;
    }

    Noeud* milieu = trouverMilieu(tete);
    Noeud* secondePartie = milieu->suivant;
    milieu->suivant = nullptr;

    Noeud* gauche = triFusion(tete);
    Noeud* droite = triFusion(secondePartie);

    Noeud* listeTriee = fusionner(gauche, droite);
    return listeTriee;
}

// ****************************
// Programme principal
// ****************************
int main() {
    Noeud* tete = nullptr;

    // Ajout des éléments (exemple)
    // Initialisation de la graine pour la génération de nombres aléatoires
    srand(static_cast<unsigned int>(time(nullptr)));

    // Pour générer des millions de nombres, changer 1'000'000 => nbre désiré
    for (int i = 0; i < 1'000'000; i++) {
        // Génère un nombre dans l'intervalle [-1,000,000 ; 500,000]
        // La taille de l'intervalle est 1,500,001
        int valeurAleatoire = (rand() % 300'500'001) - 300'000'000;
        // Insère ce nombre dans la liste
        ajouterElement(tete, valeurAleatoire);
    }

    // ... ici tu peux faire d'autres opérations, ex. triFusion(tete), affichage, etc.



    cout << "Liste avant tri : ";
    afficherListe(tete);

    // Tri par fusion
    tete = triFusion(tete);

    cout << "Liste apres tri : ";
    afficherListe(tete);

    // Libération mémoire (optionnel, pour être propre)
    // ...

    return 0;
}
