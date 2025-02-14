#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Item {
    int value, weight;
    Item(int v, int w) : value(v), weight(w) {}
};

bool compare(Item a, Item b) {
    double r1 = (double)a.value / a.weight;
    double r2 = (double)b.value / b.weight;
    return r1 > r2;
}

double fractionalKnapsack(int W, vector<Item> items) {
    sort(items.begin(), items.end(), compare);

    double maxValue = 0.0;
    int currentWeight = 0;

    for (auto item : items) {
        if (currentWeight + item.weight <= W) {
            currentWeight += item.weight;
            maxValue += item.value;
        } else {
            int remainingWeight = W - currentWeight;
            maxValue += item.value * ((double)remainingWeight / item.weight);
            break;
        }
    }
    return maxValue;
}

int main() {
    int W = 50;
    vector<Item> items = {{60, 10}, {100, 20}, {120, 30}};
    cout << "Maximum value in Knapsack = " << fractionalKnapsack(W, items) << endl;
    return 0;
}
