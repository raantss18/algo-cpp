#include <iostream>
#include <vector>
#include <climits>
using namespace std;

// Structure pour représenter un nœud de l'arbre
struct Noeud {
    int key;
    Noeud *gauche, *droite;
    Noeud(int k) : key(k), gauche(nullptr), droite(nullptr) {}
};

// Fonction pour calculer le coût optimal d'un ABRO
vector<vector<int>> calculer_ABRO(const vector<int> &cles, const vector<int> &frequences, vector<vector<int>> &matrice_racine) {
    int n = cles.size();
    vector<vector<int>> cout(n, vector<int>(n, 0));
    vector<vector<int>> somme_frequences(n, vector<int>(n, 0));

    // Pré-calculer la somme des fréquences
    for (int i = 0; i < n; i++) {
        somme_frequences[i][i] = frequences[i];
        for (int j = i + 1; j < n; j++)
            somme_frequences[i][j] = somme_frequences[i][j - 1] + frequences[j];
    }

    // Remplir la matrice de coût
    for (int longueur = 1; longueur <= n; longueur++) {
        for (int i = 0; i <= n - longueur; i++) {
            int j = i + longueur - 1;
            cout[i][j] = INT_MAX;

            for (int r = i; r <= j; r++) {
                int cout_gauche = (r > i) ? cout[i][r - 1] : 0;
                int cout_droit = (r < j) ? cout[r + 1][j] : 0;
                int cout_total = cout_gauche + cout_droit + somme_frequences[i][j];

                if (cout_total < cout[i][j]) {
                    cout[i][j] = cout_total;
                    matrice_racine[i][j] = r;
                }
            }
        }
    }
    return cout;
}

// Fonction pour construire l'ABRO à partir de la matrice des racines
Noeud* construire_Arbre(const vector<int> &cles, const vector<vector<int>> &matrice_racine, int i, int j) {
    if (i > j) return nullptr;

    int r = matrice_racine[i][j];
    Noeud* noeud = new Noeud(cles[r]);

    noeud->gauche = construire_Arbre(cles, matrice_racine, i, r - 1);
    noeud->droite = construire_Arbre(cles, matrice_racine, r + 1, j);

    return noeud;
}

// Fonction pour afficher l'ABRO sous forme hiérarchique
void afficher_Arbre(Noeud* racine, int espace = 0, int augmentation_espace = 5) {
    if (racine == nullptr) return;

    espace += augmentation_espace;
    afficher_Arbre(racine->droite, espace);

    cout << endl;
    for (int i = augmentation_espace; i < espace; i++)
        cout << " ";
    cout << racine->key << endl;

    afficher_Arbre(racine->gauche, espace);
}

int main() {
    int N;
    cout << "Entrez le nombre de clés : ";
    cin >> N;

    vector<int> cles(N);
    vector<int> frequences(N);

    cout << "Entrez les clés triées : ";
    for (int i = 0; i < N; i++) cin >> cles[i];

    cout << "Entrez les fréquences d'accès : ";
    for (int i = 0; i < N; i++) cin >> frequences[i];

    vector<vector<int>> matrice_racine(N, vector<int>(N, -1));
    vector<vector<int>> cout_minimal = calculer_ABRO(cles, frequences, matrice_racine);

    cout << "Coût minimal de l'ABRO : " << cout_minimal[0][N - 1] << endl;

    Noeud* racine = construire_Arbre(cles, matrice_racine, 0, N - 1);

    cout << "Arbre Binaire de Recherche Optimal :" << endl;
    afficher_Arbre(racine, 0);

    return 0;
}
