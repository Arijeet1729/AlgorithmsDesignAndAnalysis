#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Define the Item structure
struct Item {
    int value;
    int weight;
};

class Solution {
  public:
    // Comparator function to sort items by decreasing value/weight ratio
    static bool compareByRatio(const Item &a, const Item &b) {
        return (double)a.value / a.weight > (double)b.value / b.weight;
    }

    double fractionalKnapsack(vector<int>& val, vector<int>& wt, int capacity) {
        vector<Item> items;

        // Populate the items vector
        for (size_t i = 0; i < val.size(); i++) {
            items.push_back({val[i], wt[i]});
        }

        // Sort items based on value-to-weight ratio
        sort(items.begin(), items.end(), compareByRatio);

        double maxValue = 0.0; // Total value collected
        int remainingCapacity = capacity;

        // Process items for the knapsack
        for (const auto &item : items) {
            if (remainingCapacity >= item.weight) {
                // Take the whole item
                maxValue += item.value;
                remainingCapacity -= item.weight;
            } else {
                // Take the fraction of the remaining item
                maxValue += (double)item.value * remainingCapacity / item.weight;
                break; // Knapsack is full
            }
        }

        return maxValue;
    }
};

int main() {
    vector<int> values = {60, 100, 120};
    vector<int> weights = {10, 20, 30};
    int capacity = 50;

    Solution sol;
    double maxProfit = sol.fractionalKnapsack(values, weights, capacity);
    cout << "Maximum value in Knapsack: " << maxProfit << endl;

    return 0;
}
