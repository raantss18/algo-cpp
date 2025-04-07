#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <cfloat>

using namespace std;

class Point {
public:
    int x, y;
};

// Fonction de comparaison pour le tri selon X
int compareX(const void *a, const void *b) {
    Point *p1 = (Point *)a, *p2 = (Point *)b;
    return p1->x - p2->x;
}

// Fonction de comparaison pour le tri selon Y
int compareY(const void *a, const void *b) {
    Point *p1 = (Point *)a, *p2 = (Point *)b;
    return p1->y - p2->y;
}

// Fonction pour calculer la distance entre deux points
float dist(Point p1, Point p2) {
    return sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
}

// Méthode brute force pour trouver la plus petite distance
float bruteForce(vector<Point> &P, int n) {
    float minDist = FLT_MAX;
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            float d = dist(P[i], P[j]);
            if (d < minDist)
                minDist = d;
        }
    }
    return minDist;
}

// Trouver la plus petite distance dans une bande donnée
float stripClosest(vector<Point> &strip, int size, float d) {
    float minDist = d;
    sort(strip.begin(), strip.end(), [](Point a, Point b) { return a.y < b.y; });

    for (int i = 0; i < size; ++i) {
        for (int j = i + 1; j < size && (strip[j].y - strip[i].y) < minDist; ++j) {
            float d = dist(strip[i], strip[j]);
            if (d < minDist)
                minDist = d;
        }
    }
    return minDist;
}

// Fonction récursive principale
float closestUtil(vector<Point> &P, int n) {
    if (n <= 3)
        return bruteForce(P, n);

    int mid = n / 2;
    Point midPoint = P[mid];

    vector<Point> left(P.begin(), P.begin() + mid);
    vector<Point> right(P.begin() + mid, P.end());

    float dl = closestUtil(left, mid);
    float dr = closestUtil(right, n - mid);

    float d = min(dl, dr);

    vector<Point> strip;
    for (int i = 0; i < n; i++) {
        if (abs(P[i].x - midPoint.x) < d)
            strip.push_back(P[i]);
    }

    return min(d, stripClosest(strip, strip.size(), d));
}

// Fonction principale qui trouve la plus petite distance
float closest(vector<Point> &P, int n) {
    sort(P.begin(), P.end(), [](Point a, Point b) { return a.x < b.x; });
    return closestUtil(P, n);
}

// Programme principal
int main() {
    vector<Point> P = {{0, 3}, {2, 30}, {40, 50}, {5, 1}, {12, 10}, {3, 4},{15,-3},{4,8},{-5,12},{-3,-3}};
    int n = P.size();
    cout << "La plus petite distance est " << closest(P, n) << endl;
    return 0;
}
