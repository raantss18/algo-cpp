#include <iostream>
#include <vector>
using namespace std;

static bool foundConfigNo2x2 = false; // Deviendra true si on trouve une config SANS aucun 2x2 vide

int n;                 // Taille de l'échiquier
vector<int> col;       // col[i] = colonne de la tour sur la ligne i
vector<bool> used;     // used[c] = true si la colonne c est déjà utilisée

// Vérifie si, dans la configuration courante (col[0..n-1]),
// il existe au moins un carré 2x2 vide.
// Si NON, alors la config n'a aucun 2x2 vide.
bool pasDeCarre2x2Vide() {
    // On parcourt tous les sous-carrés 2x2 potentiels
    // Un sous-carré (r,c) à (r+1,c+1) est vide si
    // col[r] n'est ni c ni c+1, et col[r+1] n'est ni c ni c+1.
    for(int r = 0; r < n - 1; r++) {
        for(int c = 0; c < n - 1; c++) {
            bool vide =
            (col[r]   != c && col[r]   != c+1) &&
            (col[r+1] != c && col[r+1] != c+1);
            if(vide) {
                // On a trouvé un 2x2 vide, donc la config EN possède un.
                // => la config N'EST PAS dépourvue de 2x2 vide
                return false;
            }
        }
    }
    // On n'a trouvé aucun 2x2 vide => la config n'en a pas.
    return true;
}

// Backtracking : place la tour de la ligne i
void placerTour(int i) {
    // Si on a déjà trouvé une config sans 2x2 vide,
    // on peut arrêter (optimisation) car on sait que k=1.
    if(foundConfigNo2x2) return;

    // Si i == n, on a placé toutes les tours
    if(i == n) {
        // Vérifier si cette configuration n'a aucun 2x2 vide
        if(pasDeCarre2x2Vide()) {
            foundConfigNo2x2 = true;
        }
        return;
    }

    // Essayer toutes les colonnes possibles
    for(int c = 0; c < n; c++) {
        if(!used[c]) {          // colonne non encore utilisée
            used[c] = true;
            col[i] = c;

            placerTour(i+1);

            used[c] = false;    // backtrack
            if(foundConfigNo2x2) return; // on peut couper
        }
    }
}

int main(){
    cin >> n;
    // Cas trivial si n < 2, la question n'a pas de sens :
    // on suppose n>=2 d'après l'énoncé.
    if(n < 2){
        cout << "k=0 (pas de sens pour n<2)" << endl;
        return 0;
    }

    // Initialisations
    col.resize(n);
    used.assign(n, false);

    // Lancement du backtracking
    placerTour(0);

    // foundConfigNo2x2 == true => on a trouvé au moins une config
    // sans 2x2 vide => On ne peut pas garantir k>=2 => k=1
    // Sinon => en théorie, ça voudrait dire qu'on peut garantir 2x2 vide
    // mais mathématiquement, on sait que pour n>=2, on trouvera always
    // une config sans 2x2 vide (ex: diagonale), donc on s'attend
    // forcément à foundConfigNo2x2 == true.
    int k = (foundConfigNo2x2 ? 1 : 2);

    cout << "Le plus grand k garanti pour chaque configuration de " << n
    << " tours est : " << k << endl;

    return 0;
}
