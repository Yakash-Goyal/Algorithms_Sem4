#include <iostream>
using namespace std;
void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

int counter = 0;

int partition(int arr[], int low, int high) {
    int pivot = arr[high]; 
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSort(int arr[], int low, int high) {
    counter++;
    if (low < high) {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main() {
    cout << "Enter the elements of array" << endl;
    int arr[6];
    int i = 0,n=6;
    while(i <= 5){
       cin >> arr[i];
       i++;
    }
    cout << "Original array: ";
    printArray(arr, n);
    quickSort(arr, 0, n - 1);
    cout << "your sorted array is  ";
    printArray(arr, n);
    cout <<endl <<  "Total no. of stacks formed: " << counter << endl;
    return 0;
}
