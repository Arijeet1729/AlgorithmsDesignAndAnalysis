#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Item {
    int value;
    int weight;
};

class Solution {
  public:
    static bool compareByRatio(const Item &a, const Item &b) {
        return (double)a.value / a.weight > (double)b.value / b.weight;
    }

    double fractionalKnapsack(vector<int>& val, vector<int>& wt, int capacity) {
        vector<Item> items;

        for (size_t i = 0; i < val.size(); i++) {
            items.push_back({val[i], wt[i]});
        }

        sort(items.begin(), items.end(), compareByRatio);

        double maxValue = 0.0; 
        int remainingCapacity = capacity;

        for (const auto &item : items) {
            if (remainingCapacity >= item.weight) {
                 maxValue += item.value;
                remainingCapacity -= item.weight;
            } else {

                maxValue += (double)item.value * remainingCapacity / item.weight;
                break;
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
