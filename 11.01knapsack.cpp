#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int Knapsack(vector<pair<int, int>> items, int W) {
    vector<vector<int>> dp(items.size() + 1, vector<int>(W + 1, 0));

    
    for (int i = 1; i <= items.size(); i++) {
        for (int w = 1; w <= W; w++) {
            if (items[i - 1].second <= w) {
                dp[i][w] = max(dp[i - 1][w], dp[i - 1][w - items[i - 1].second] + items[i - 1].first);
            } else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    return dp[items.size()][W]; 
}

int main() {
    vector<pair<int, int>> items = { {60, 10}, {100, 20}, {120, 30} }; 
    int W = 50; 

    int maxValue = Knapsack(items, W);
    cout << "Maximum value in Knapsack = " << maxValue << endl;

    return 0;
}


