#include <iostream>
#include <vector>

using namespace std;

vector<int> rendreMonnaieVorace(const vector<int>& pieces, int somme) {
    vector<int> resultat;
    int restant = somme;

    for (int piece : pieces) {
        while (restant >= piece) {
            resultat.push_back(piece);
            restant -= piece;
        }
    }

    return resultat;
}

void afficherSolution(const vector<int>& solution) {
    cout << "Solution vorace : ";
    for (int piece : solution) {
        cout << piece << " ";
    }
    cout << "(Total : " << solution.size() << " pièces)" << endl;
}

int main() {
    vector<int> pieces1 = {25, 10, 5, 1};
    int somme1 = 18;
    vector<int> solution1 = rendreMonnaieVorace(pieces1, somme1);
    afficherSolution(solution1);

    vector<int> pieces2 = {4, 3, 1};
    int somme2 = 10;
    vector<int> solution2 = rendreMonnaieVorace(pieces2, somme2);
    afficherSolution(solution2);

    return 0;
}
