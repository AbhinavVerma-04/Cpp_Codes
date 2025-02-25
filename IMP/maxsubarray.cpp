#include <bits/stdc++.h>
using namespace std;
int Sum(vector<int> &nums, int &k)
{
    int l = 0;
    int r = 0;
    int maxLen = 0;
    int sum = 0;
    while (r < nums.size())
    {
        sum += nums[r];
        while (sum > k && l <= r)
        {
            sum -= nums[l];
            l++;
        }
        maxLen = max(maxLen, r - l + 1);
        r++;
    }
    return maxLen;
}
int main()
{
    vector<int> nums{2, 5, 1, 7, 10};
    int k = 14;
    cout << Sum(nums, k);
}