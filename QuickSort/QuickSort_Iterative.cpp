#include <iostream>
#include <stack>
using namespace std;

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSortIterative(int arr[], int n) {
    stack<int> s;
    s.push(0);
    s.push(n - 1);

    while (!s.empty()) {
        int high = s.top(); s.pop();
        int low = s.top(); s.pop();

        int p = partition(arr, low, high);

        if (p - 1 > low) {
            s.push(low);
            s.push(p - 1);
        }
        if (p + 1 < high) {
            s.push(p + 1);
            s.push(high);
        }
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int arr[] = {10, 7, 8, 9, 1, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    quickSortIterative(arr, n);
    cout << "Sorted array: ";
    printArray(arr, n);

    return 0;
}
