#include <iostream>
#include <vector>
#include <cmath>
#include <limits>

using namespace std;

// Structure représentant un point
struct Point {
    double x, y;
};

// Fonction pour calculer la distance euclidienne entre deux points
double distanceEuclidienne(const Point& p1, const Point& p2) {
    return sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
}

// Fonction pour trouver la paire de points la plus proche (Approche naïve)
double plusProcheNaif(const vector<Point>& points) {
    int n = points.size();
    double minDistance = numeric_limits<double>::infinity();

    for (int i = 0; i < n - 1; ++i) {
        for (int j = i + 1; j < n; ++j) {
            double d = distanceEuclidienne(points[i], points[j]);
            if (d < minDistance) {
                minDistance = d;
            }
        }
    }
    return minDistance;
}

int main() {
    int n;
    cout << "Entrez le nombre de points : ";
    cin >> n;

    vector<Point> points(n);
    cout << "Entrez les coordonnées (x y) des points :\n";
    for (int i = 0; i < n; ++i) {
        cin >> points[i].x >> points[i].y;
    }

    double resultat = plusProcheNaif(points);
    cout << "La distance minimale est : " << resultat << endl;

    return 0;
}
