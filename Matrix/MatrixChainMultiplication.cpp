#include<iostream>
#include<stdlib.h>
#include<ctime>
#include<climits>
#define INF INT_MAX
using namespace std;

void PrintMatrix(int n,int **M){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout << M[i][j] << " ";
        }
        cout << endl;
    }
}

void scalarMultiplications(int p[],int n){
    int** M = new int*[n];
    for (int i = 0; i < n; i++) {
        M[i] = new int[n];
    }

    int** S = new int*[n];
    for (int i = 0; i < n; i++) {
        S[i] = new int[n];
    }

    int j,q;
    for(int i=0; i<n; i++){
        for(int j = 0;j < n;j++){
            if(i > j){
                M[i][j] = 0;
                S[i][j] = 0;
            }
            else if(i == j){
                M[i][j] = 0;
                S[i][j] = 0;
            }
            else{
                M[i][j] = INF;
                S[i][j] = INF;
            }
        }   
    }

    for(int l = 2;l <= n;l++){
        for(int i = 0;i < n-l + 1;i++){
            j = i + l - 1;
            M[i][j] = INF;
            for(int k = i;k < j;k++){
                q = M[i][k] + M[k+1][j] + p[i]*p[k+1]*p[j+1];
                if(q < M[i][j]){
                    M[i][j] = q;
                    S[i][j] = k;
                }
            }
        }
    }
    cout << "Minimum number of scalar multiplications is " << M[0][n -1] << endl;
    cout << "The order for its Multiplication is " << endl;
    
    cout << "The Number of possible matrix multiplications in each pair is " << endl;
    PrintMatrix(n,M);
    cout << "S MAtirix" << endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(j > i){
                S[i][j] += 1;
            }
            cout << S[i][j] << " ";
        }
        cout << endl;
    }
}

int main(){
    srand(time(0));
    int n = rand() % 8 + 2;
    int p[n + 1];
    cout << "The number of matrices is " << n << endl;

    cout << "The order of matrices is " << endl;
    for(int i=0; i<=n; i++){
        p[i] = (rand() % 50) + 1;
    }

    for(int i=0;i<n+1;i++){
        cout << p[i] << " ";
    }
    // int n = 4;
    // int p[] = {5,10,20,2,1};
    cout << endl;
    scalarMultiplications(p,n);
}