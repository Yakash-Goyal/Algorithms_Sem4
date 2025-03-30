#include <iostream>
#include <climits>
#define MAX 100
#define INF INT_MAX
using namespace std;

void MGP(int n, int G[MAX][MAX])
{
    int fdist[n], d[n];
    fdist[n - 1] = 0;
    int temp = INF, r;
    for (int j = n - 2; j >= 0; j--)
    {
        temp = INF;
        for (r = j + 1; r <= n - 1; r++)
        {
            if ((G[j][r] > 0 && G[j][r] != INF))
            {
                if(temp > fdist[r]){
                temp = G[j][r] + fdist[r];
                d[j] = r;
                }
            
            }
        }
            fdist[j] = temp;
    }
    cout << "The path is" << endl;
    for(int i = 0 ; i < n;i++)
    {
        cout << d[i] << " ";
    }
    cout << "Minimum distance is " << fdist[0];
}

int StageCount(int n, int G[MAX][MAX])
{
    int i = 0, count = 0;
    for (int j = 0; j < n; j++)
    {
        if (G[i][j] > 0 && G[i][j] != INF)
        {
            count++;
            i = j;
        }
    }
    return count + 1;
}

int main()
{
    int n, G[MAX][MAX];
    cout << "Enter the number of vertices in the graph" << endl;
    cin >> n;
    cout << "Enter the Elements adjacency Matrix" << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> G[i][j];
            if (G[i][j] == -1)
            {
                G[i][j] = INF;
            }
            if (i == j)
            {
                G[i][j] = 0;
            }
            if (j < i)
            {
                G[i][j] = INF;
            }
        }
    }
    int Stages = StageCount(n, G);
    cout << Stages;
    MGP(n,G);

    // for(int i=0;i < n;i++){
    //     for(int j= 0;j < n;j++){
    //         cout << G[i][j] << " ";
    //     }
    //     cout << endl;
    // }
}