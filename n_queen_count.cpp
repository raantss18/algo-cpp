#include <iostream>
#include <cmath>

using namespace std;

// Structure pour un nœud de la liste chaînée (stocke la position d'une dame)
struct Noeud {
    int ligne, colonne;
    Noeud* suivant;

    Noeud(int l, int c) : ligne(l), colonne(c), suivant(nullptr) {}
};

// Classe ListeDames pour stocker les placements des dames
class ListeDames {
public:
    Noeud* tete;

    ListeDames() : tete(nullptr) {}

    // Ajouter une dame à la liste
    void ajouterDame(int ligne, int colonne) {
        Noeud* nouveauNoeud = new Noeud(ligne, colonne);
        nouveauNoeud->suivant = tete;
        tete = nouveauNoeud;
    }

    // Retirer la dernière dame ajoutée (étape de retour en arrière)
    void retirerDame() {
        if (tete) {
            Noeud* temp = tete;
            tete = tete->suivant;
            delete temp;
        }
    }

    // Vérifier si une dame peut être placée en (ligne, colonne) sans conflit
    bool estSecurise(int ligne, int colonne) {
        Noeud* actuel = tete;
        while (actuel) {
            if (actuel->colonne == colonne || abs(actuel->ligne - ligne) == abs(actuel->colonne - colonne)) {
                return false;  // Conflit détecté (même colonne ou même diagonale)
            }
            actuel = actuel->suivant;
        }
        return true;
    }
};

// Fonction récursive de retour en arrière pour résoudre N-Dames et compter les solutions
void resoudreNDames(ListeDames& dames, int ligne, int N, int& compteur) {
    if (ligne == N) {  // Une solution est trouvée
        compteur++;
        return;
    }

    for (int colonne = 0; colonne < N; colonne++) {
        if (dames.estSecurise(ligne, colonne)) {  // Vérifier si le placement est valide
            dames.ajouterDame(ligne, colonne);  // Placer la dame
            resoudreNDames(dames, ligne + 1, N, compteur);  // Récursion pour la ligne suivante
            dames.retirerDame();  // Retour en arrière
        }
    }
}

// Fonction principale
int main() {
    int N;
    cout << "Entrez la valeur de N (taille de l'échiquier) : ";
    cin >> N;

    ListeDames dames;  // Création de la liste chaînée pour stocker les dames
    int compteur = 0;
    resoudreNDames(dames, 0, N, compteur);  // Commencer la résolution depuis la ligne 0

    cout << "Nombre de solutions pour N=" << N << " : " << compteur << endl;
    return 0;
}
