//GIVES THE MAXIMUM SUM FOR K LENGTH SUBSEQUENCE WITH DISTINCT ELEMENTS
#include <bits/stdc++.h>
using namespace std;

// Check if the elements in the vector are distinct
bool isDistinct(const vector<int>& ds) {
    unordered_set<int> seen;
    for (int i : ds) {
        if (seen.count(i)) return false; // Duplicate found
        seen.insert(i);
    }
    return true; // All elements are distinct
}

// Recursive function to find subsequences of length `count` with maximum sum
void findMaxSumSubsequence(int index, int arr[], int size, int count, vector<int>& ds, int& maxSum, vector<int>& result) {
    if (index == size) {
        if (ds.size() == count && isDistinct(ds)) {
            int sum = 0;
            for(int i : ds){
                sum += i;
            }
            if (sum > maxSum) {
                maxSum = sum;
                result = ds; // Update the result subsequence
            }
        }
        return;
    }

    // PICK the current element
    ds.push_back(arr[index]);
    findMaxSumSubsequence(index + 1, arr, size, count, ds, maxSum, result);

    // NOT PICK the current element
    ds.pop_back();
    findMaxSumSubsequence(index + 1, arr, size, count, ds, maxSum, result);
}

int main() {
    int arr[] = {1, 5, 4, 2, 9, 9, 9};
    int size = 7;
    int count = 3; // Length of subsequences to consider

    vector<int> ds;         // Temporary vector for recursion
    int maxSum = INT_MIN;   // To store the maximum sum
    vector<int> result;     // To store the subsequence with the maximum sum

    findMaxSumSubsequence(0, arr, size, count, ds, maxSum, result);

    // Output the result
    cout << "Subsequence with maximum sum: ";
    for (int i : result) {
        cout << i << " ";
    }
    cout << endl;
    cout << "Maximum sum: " << maxSum << endl;

    return 0;
}
