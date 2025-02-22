#include <bits/stdc++.h>
using namespace std;

int maxProfit(int savings, vector<int>& current, vector<int>& future, int index, vector<vector<int>>& dp) {
    if (index == current.size()) {
        return 0;
    }
    if (dp[index][savings] != -1) 
        return dp[index][savings];
    
    int skip = maxProfit(savings, current, future, index + 1, dp);

    int buy = 0;
    if (savings >= current[index]) {
        buy = (future[index] - current[index]) + maxProfit(savings - current[index], current, future, index + 1, dp);
    }

    return dp[index][savings] = max(skip, buy);
}

int main() {
    int savings = 50;
    vector<int> current = {20, 30, 50};
    vector<int> future = {40, 60, 70};
    
    vector<vector<int>> dp(current.size(), vector<int>(savings + 1, -1));
    
    cout << "Maximum Profit: " << maxProfit(savings, current, future, 0, dp) << endl;
    return 0;
}
