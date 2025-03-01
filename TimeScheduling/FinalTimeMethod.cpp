#include<iostream>
using namespace std;

void Sort(int arr[2][10],int n) {
    for (int i = 0; i < n-1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[1][j] < arr[1][minIndex]) {
                minIndex = j;
            }
        }
        swap(arr[1][i], arr[1][minIndex]);
        swap(arr[0][i], arr[0][minIndex]);
    }
}
void Schedule(){

}

int main(){
    cout << "Enter the desired starting and ending time for your program" << endl;
    int n;
    cout << "Enter total no. of processes" << endl;
    cin >> n;
    int i = 0,arr[2][n];
    while(i < n){
        cout <<endl << i+1 <<"Process" << endl;
        cin >> arr[1][i];
        cin >> arr[2][i];
        i ++;
    }
    Sort(arr,n);
    int j = 0;
    while(j <= n){
        if(j == 1)
        {cout << "Execute the first program" << endl;
        j++;
        }
        else{
            if(arr[2][j] > arr[1][j-1])
            cout << "Execute the " << i << " program" << endl;
            else
            i++;
        }
    }
}