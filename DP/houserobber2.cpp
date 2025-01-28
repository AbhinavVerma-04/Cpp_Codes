#include <bits/stdc++.h>
using namespace std;
int recursion(int index, vector<int> nums) {
    if (index < 0)
        return 0;
    int pick = nums[index] + recursion(index - 2, nums);
    int npick = recursion(index - 1, nums);
    return max(pick, npick);
}
int memoisation(int index, vector<int> nums, vector<int>& dp) {
    if (index < 0)
        return 0;
    if (dp[index] != -1)
        return dp[index];
    int pick = nums[index] + memoisation(index - 2, nums, dp);
    int npick = memoisation(index - 1, nums, dp);
    return dp[index] = max(pick, npick);
}
int tabulation(vector<int> nums) {
    int n = nums.size();
    if (n == 0)
        return 0;
    if (n == 1)
        return nums[0];
    vector<int> tab(n, 0);
    tab[0] = nums[0];
    if (n > 1)
        tab[1] = max(nums[0], nums[1]);
    for (int i = 2; i < n; i++) {
        tab[i] = max(nums[i] + tab[i - 2], tab[i - 1]);
    }
    return tab[n - 1];
}
int main() {
    vector<int> nums{2, 3, 2};
    int n = nums.size();
    vector<int> temp1, temp2;
    for (int i = 0; i < n; i++) {
        if (i != 0)
            temp1.push_back(nums[i]);
        if (i != n - 1)
            temp2.push_back(nums[i]);
    }
    int t1 = recursion(n - 1, temp1);
    int t2 = recursion(n - 1, temp2);
    cout << max(t1, t2) << endl;
    vector<int> dp1(temp1.size(), -1), dp2(temp2.size(), -1);
    t1 = memoisation(temp1.size() - 1, temp1, dp1);
    t2 = memoisation(temp2.size() - 1, temp2, dp2);
    cout << max(t1, t2) << endl;
    t1 = tabulation(temp1);
    t2 = tabulation(temp2);
    cout << max(t1, t2);
}