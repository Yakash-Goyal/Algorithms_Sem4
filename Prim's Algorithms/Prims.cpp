#include <iostream>
#include <climits>
using namespace std;
#define INF INT_MAX
#define MAX 100
pair<int, int> minimumWeightWhole(int n, int graph[MAX][MAX]) {
    int min = INF;
    pair<int, int> edge = {-1, -1};

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (graph[i][j] < min && graph[i][j] > 0) {
                min = graph[i][j];
                edge = {i, j};
            }
        }
    }
    return edge;
}

void primMST(int n, int graph[MAX][MAX]) {
    int parent[MAX],key[MAX];
    bool inMST[MAX];
    for (int i = 0; i < n; i++) {
        key[i] = INF;
        inMST[i] = false;
    }
    pair<int, int> edge = minimumWeightWhole(n, graph);
    int start = edge.first;
    key[start] = 0;
    parent[start] = -1;
    for (int count = 0; count < n - 1; count++){
        int u = -1, minKey = INF;
        for (int v = 0; v < n; v++) {
            if (!inMST[v] && key[v] < minKey){
                minKey = key[v];
                u = v;
            }
        }
        inMST[u] = true;
        for (int v = 0; v < n; v++) {
            if (graph[u][v] && !inMST[v] && graph[u][v] < key[v]) {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }

    cout << "Minimum Spanning Tree Edges:\n";
    for (int i = 1; i < n; i++) {
        cout << parent[i] << " - " << i << " : " << graph[i][parent[i]] << endl;
    }
}

int main() {
    int n;
    cout << "Enter the number of vertices in the graph: ";
    cin >> n;
    int graph[MAX][MAX];
    cout << "Enter the adjacency matrix (-1 for no edge):\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> graph[i][j];
            if (graph[i][j] == -1)
                graph[i][j] = INF;
            if (i == j)
                graph[i][j] = 0;
        }
    }
    primMST(n, graph);
}
