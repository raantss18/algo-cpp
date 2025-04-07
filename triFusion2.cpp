#include <iostream>

using namespace std;

// Définition de la structure d'un nœud
struct Noeud {
    int donnee;
    Noeud* suivant;

    Noeud(int valeur) : donnee(valeur), suivant(nullptr) {}
};

// Fonction pour trouver le milieu de la liste
Noeud* trouverMilieu(Noeud* tete) {
    if (tete == nullptr || tete->suivant == nullptr)
        return tete;

    Noeud* lent = tete;
    Noeud* rapide = tete->suivant;

    while (rapide != nullptr && rapide->suivant != nullptr) {
        lent = lent->suivant;
        rapide = rapide->suivant->suivant;
    }

    return lent;
}

// Fonction pour ajouter un élément à la fin de la liste
void ajouterElement(Noeud*& tete, int valeur) {
    if (tete == nullptr) {
        tete = new Noeud(valeur);
        return;
    }

    Noeud* temp = tete;
    while (temp->suivant != nullptr) {
        temp = temp->suivant;
    }

    temp->suivant = new Noeud(valeur);
}

// Fonction pour afficher la liste
void afficherListe(Noeud* tete) {
    Noeud* temp = tete;
    while (temp != nullptr) {
        cout << temp->donnee << " -> ";
        temp = temp->suivant;
    }
    cout << "NULL" << endl;
}

// Fonction pour fusionner deux listes triées en une seule liste triée
Noeud* fusionner(Noeud* gauche, Noeud* droite) {
    if (!gauche) return droite;
    if (!droite) return gauche;

    if (gauche->donnee < droite->donnee) {
        gauche->suivant = fusionner(gauche->suivant, droite);
        return gauche;
    } else {
        droite->suivant = fusionner(gauche, droite->suivant);
        return droite;
    }
}

// Fonction de tri fusion pour la liste chaînée
Noeud* triFusion(Noeud* tete) {
    if (!tete || !tete->suivant) return tete;

    Noeud* milieu = trouverMilieu(tete);
    Noeud* secondePartie = milieu->suivant;
    milieu->suivant = nullptr;

    Noeud* gauche = triFusion(tete);
    Noeud* droite = triFusion(secondePartie);

    return fusionner(gauche, droite);
}

// Fonction principale
int main() {
    Noeud* tete = nullptr;

    // Ajout des éléments dans la liste chaînée
    ajouterElement(tete, 4);
    ajouterElement(tete, 2);
    ajouterElement(tete, 8);
    ajouterElement(tete, 5);
    ajouterElement(tete, 1);
    ajouterElement(tete, 3);

    cout << "Liste avant tri :" << endl;
    afficherListe(tete);

    tete = triFusion(tete);

    cout << "Liste apres tri :" << endl;
    afficherListe(tete);

    return 0;
}
