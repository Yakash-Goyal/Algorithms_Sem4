#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <algorithm>

using namespace std;

struct Point {
    int x, y;
};

int crossProduct(Point a, Point b, Point c) {
    return (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
}

int distance(Point a, Point b, Point c) {
    return abs(crossProduct(a, b, c));
}

void quickHull(vector<Point>& points, Point a, Point b, int side, vector<Point>& hull) {
    int idx = -1, maxDist = 0;
    for (int i = 0; i < points.size(); i++) {
        int temp = crossProduct(a, b, points[i]) * side;
        if (temp > maxDist) {
            idx = i;
            maxDist = temp;
        }
    }

    if (idx == -1) {
        hull.push_back(a);
        hull.push_back(b);
        return;
    }

    quickHull(points, points[idx], a, -crossProduct(points[idx], a, b) < 0 ? -1 : 1, hull);
    quickHull(points, points[idx], b, -crossProduct(points[idx], b, a) < 0 ? -1 : 1, hull);
}

vector<Point> findQuickHull(vector<Point>& points) {
    if (points.size() < 3) return points;
    Point minX = points[0], maxX = points[0];
    for (auto& p : points) {
        if (p.x < minX.x) minX = p;
        if (p.x > maxX.x) maxX = p;
    }
    vector<Point> hull;
    quickHull(points, minX, maxX, 1, hull);
    quickHull(points, minX, maxX, -1, hull);
    sort(hull.begin(), hull.end(), [](Point a, Point b) {
        return a.x < b.x || (a.x == b.x && a.y < b.y);
    });
    hull.erase(unique(hull.begin(), hull.end(), [](Point a, Point b) {
        return a.x == b.x && a.y == b.y;
    }), hull.end());
    return hull;
}

int main() {
    srand(time(0));
    int n;
    cin >> n;
    vector<Point> points(n);
    for (int i = 0; i < n; i++) {
        points[i].x = rand() % 100;
        points[i].y = rand() % 100;
    }

    cout << "Generated Points:\n";
    for (auto& p : points) {
        cout << "(" << p.x << ", " << p.y << ")\n";
    }

    vector<Point> hull = findQuickHull(points);
    cout << "\nConvex Hull:\n";
    for (auto& p : hull) {
        cout << "(" << p.x << ", " << p.y << ")\n";
    }

    return 0;
}
