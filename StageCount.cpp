#include <iostream>
#include <climits>
using namespace std;
#define N 4
#define INF INT_MAX
void stagesAndVertices(int cost[N][N])
{
    int k=1;
    cout<<k<<" has 1 vertex "<<endl;
    k++;
    int node=0;
    while(node!=N-1)
    {
        int c=0;
        for(int j=node+1;j<N;j++)
        {
            
            if(cost[node][j]!=INF)
            {
                c++;
            }
        }
        cout<<k<<" has "<<c<<" vertices "<<endl;
        for(int j=node+1;j<N;j++)
        {
            if(cost[node][j]!=INF)
            {
                node=j;
                k++;
                break;
            }
        }
    }
    cout<<"Total stages: "<<k-1<<endl;
}
int main()
{
    int cost[N][N]=
    {
        {INF,2,3,INF},
        {INF,INF,INF,6},
        {INF,INF,INF,7},
        {INF,INF,INF,INF}
    };
    stagesAndVertices(cost);
return 0;
}