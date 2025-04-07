#include <iostream>
#include <vector>
#include <climits>

using namespace std;

vector<int> renduDynamique(const vector<int>& pieces, int somme) {
    vector<int> dp(somme + 1, INT_MAX);
    vector<int> choix(somme + 1, -1);

    dp[0] = 0;

    for (int i = 1; i <= somme; ++i) {
        for (int piece : pieces) {
            if (i >= piece && dp[i - piece] != INT_MAX && dp[i - piece] + 1 < dp[i]) {
                dp[i] = dp[i - piece] + 1;
                choix[i] = piece;
            }
        }
    }

    vector<int> resultat;

    if (dp[somme] == INT_MAX) {
        return resultat;
    }

    int restant = somme;
    while (restant > 0) {
        resultat.push_back(choix[restant]);
        restant -= choix[restant];
    }

    return resultat;
}

void afficherResultat(const vector<int>& resultat) {
    if (resultat.empty()) {
        cout << "Aucune solution possible." << endl;
        return;
    }

    int somme = 0;
    cout << "Pièces utilisées : ";
    for (int piece : resultat) {
        cout << piece << " ";
        somme += piece;
    }
    cout << "\nSomme totale : " << somme;
    cout << "\nNombre total de pièces : " << resultat.size() << endl;
}

int main() {
    vector<pair<vector<int>, int>> tests = {
        {{1, 3, 4}, 6},
        {{1, 5, 10, 25}, 63},
        {{12, 7, 3, 1}, 14}
    };

    for (auto& test : tests) {
        cout << "Test pour la somme " << test.second << ":\n";
        vector<int> resultat = renduDynamique(test.first, test.second);
        afficherResultat(resultat);
        cout << "----------------------------" << endl;
    }

    return 0;
}
