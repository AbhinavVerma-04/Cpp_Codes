#include <bits/stdc++.h>
using namespace std;

// Function to precompute sum of factors for numbers up to maxN
vector<int> precomputeSumOfFactors(int maxN) {
    vector<int> sumFactors(maxN + 1, 1); // Initialize with 1 (since 1 is a factor for all)
    
    for (int i = 2; i <= maxN; i++) {
        for (int j = i; j <= maxN; j += i) {
            sumFactors[j] += i;
        }
    }
    return sumFactors;
}

// Function to return sum of factors for each element in the vector
vector<int> sumOfFactorsVector(const vector<int>& nums) {
    int maxN = *max_element(nums.begin(), nums.end());
    vector<int> sumFactors = precomputeSumOfFactors(maxN);

    vector<int> result;
    for (int num : nums) {
        result.push_back(sumFactors[num]);
    }
    return result;
}

// Example usage
int main() {
    vector<int> nums = {10, 15, 20};
    vector<int> result = sumOfFactorsVector(nums);

    for (int sum : result) {
        cout << sum << " ";
    }
    return 0;
}
