#include<iostream>
using namespace std;
// void Prim(int e, int cost, int n){}
pair<int,int> minimumWeightWhole(int n,int graph[100][100]){
    int min;
    pair<int,int> edge;
    cout << "The minimum weighted edge is " << endl;
    // min = graph[0][1];
    for(int i = 0;i < n;i++){
        for(int j = 0;j < n;j++){
            if(graph[i][j] < min && graph[i][j] > 0){
                // min = graph[i][j];
                edge.first = i;
                edge.second = j;
            }
        }
    }
    return edge;
}

pair<int,int> minimumWeight(int n,int arr){
    int min;
    pair<int,int> edge;
    // cout << "The minimum weighted edge is " << endl;
    // min = graph[0][1];
    for(int i=0;i<n;i++){
        
    }
    return edge;
}
int main(){
    int n;
    cout << "Enter the number of vertices in the graph" << endl;
    cin >> n;
    int graph[n][n],min;
    for(int i = 0;i < n;i++){
        cout << "Enter the edges weight for " << i << " vertex in order" << endl;
        for(int j = 0;j < n;j++){
            if(i == j)
            {
                graph[i][i] = 0;
                
            }
            else
                cin >> graph[i][j];
                if(graph[i][j] == -1){
                    graph[i][j] = INT64_MAX;
                }
        }
    }
    pair<int,int> edge = minimumWeightWhole(n,graph);
    int near[n];
    for(int i = 0;i < n; i++){
        if(graph[i][edge.first] > graph[i][edge.second])
        {
            near[i] = edge.second;
        }
        else{
            near[i] = edge.first;
        }
    }
    near[edge.first] = 0;
    near[edge.second] = 0;
    min = graph[edge.first][edge.second];
    int result[n][2];
    result[0][0] = edge.first;
    result[0][1] = edge.second;
    for(int j=2;j < n;j++){
        for(int i = 0;i < n;i++){

        }
    }
}