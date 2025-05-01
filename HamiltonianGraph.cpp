#include <iostream>
#include <vector>
using namespace std;
#define V 20
int graph[V][V];
int path[V];
int totalVertices;

bool isSafe(int v, int pos) {
    if (graph[path[pos - 1]][v] == 0)
        return false;
    for (int i = 0; i < pos; i++)
        if (path[i] == v)
            return false;
    return true;
}
bool hamiltonianCycleUtil(int pos) {
    if (pos == totalVertices) {
        return graph[path[pos - 1]][path[0]] == 1;
    }
    for (int v = 1; v < totalVertices; v++) {
        if (isSafe(v, pos)) {
            path[pos] = v;
            if (hamiltonianCycleUtil(pos + 1))
                return true;
            path[pos] = -1;
        }
    }
    return false;
}
bool findHamiltonianCycle() {
    for (int i = 0; i < totalVertices; i++)
        path[i] = -1;
    path[0] = 0;
    if (!hamiltonianCycleUtil(1)) {
        cout << "No Hamiltonian cycle exists.\n";
        return false;
    }
    cout << "Hamiltonian cycle found:\n";
    for (int i = 0; i < totalVertices; i++)
        cout << path[i] << " ";
    cout << path[0] << endl;
    return true;
}
int main() {
    cout << "Enter the number of vertices: ";
    cin >> totalVertices;
    cout << "Enter the adjacency matrix (0 or 1):\n";
    for (int i = 0; i < totalVertices; i++)
        for (int j = 0; j < totalVertices; j++)
            cin >> graph[i][j];
    findHamiltonianCycle();
    return 0;
}
