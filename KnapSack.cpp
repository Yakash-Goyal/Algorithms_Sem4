#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Structure for an item with value and weight
struct Item {
    int value, weight;

    // Constructor
    Item(int v, int w) : value(v), weight(w) {}
};

// Function to compare items based on value/weight ratio
bool compare(Item a, Item b) {
    double r1 = (double)a.value / a.weight;
    double r2 = (double)b.value / b.weight;
    return r1 > r2;
}

// Function to calculate the maximum value for the fractional knapsack
double fractionalKnapsack(int W, vector<Item> items) {
    sort(items.begin(), items.end(), compare); // Sort items by value/weight ratio

    double maxValue = 0.0; // Maximum value in knapsack
    int currentWeight = 0; // Current weight in knapsack

    for (auto item : items) {
        if (currentWeight + item.weight <= W) {
            currentWeight += item.weight;
            maxValue += item.value;
        } else {
            int remainingWeight = W - currentWeight;
            maxValue += item.value * ((double)remainingWeight / item.weight);
            break; // Knapsack is full
        }
    }
    return maxValue;
}

// Main function
int main() {
    int W = 50; // Knapsack capacity
    vector<Item> items = {{60, 10}, {100, 20}, {120, 30}}; // Items with value and weight

    cout << "Maximum value in Knapsack = " << fractionalKnapsack(W, items) << endl;
    return 0;
}
