#include<iostream>
#include<cstdlib>
#include<ctime>
#include <climits>
#define MAX 10
#define INF INT_MAX
using namespace std;
void generateMatrix(int **M,int r,int c){
    for(int i = 0; i < r;i++){
        for(int j = 0; j < c;j++){
            M[i][j] = rand() % 10;
        }
    }
}

void DisplayMatrix(int **M,int r,int c){
    for(int i = 0; i < r;i++){
        for(int j = 0; j < c;j++){
            cout << M[i][j] << " ";
        }
        cout << endl;
    }
}

void Multiplication(int **A,int r1,int c1,int **B,int r2,int c2,int **M){
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c2; j++) {
            M[i][j] = 0;
            for (int k = 0; k < c1; k++) {
                M[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

int main(){
    srand(time(0));
    int r1,c1,r2,c2;
    r1 = 2 + rand() % 5;
    c1 = 2 + rand() % 5;
    c2 = 2 + rand() % 5;
    r2 = c1;

    int** M1 = new int*[r1];
    for (int i = 0; i < r1; i++) {
        M1[i] = new int[c1];
    }

    int** M2 = new int*[r2];
    for (int i = 0; i < r2; i++) {
        M2[i] = new int[c2];
    }
    generateMatrix(M1,r1,c1);
    cout << "The elements of matrix 1 with row size " << r1 << " and column size " << c1 << endl;
    DisplayMatrix(M1,r1,c1);

    generateMatrix(M2,r2,c2);
    cout << "The elements of matrix 2 with row size " << r2 << " and column size " << c2 << endl;
    DisplayMatrix(M2,r2,c2);

    int** M3 = new int*[r1];
    for (int i = 0; i < r1; i++) {
        M3[i] = new int[c2];
    }
    Multiplication(M1,r1,c1,M2,r2,c2,M3);
    cout << "After Multiplication, The Elements of new matrix are" << endl;
    DisplayMatrix(M3,r1,c2);
}