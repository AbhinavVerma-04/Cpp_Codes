//PRINTING SUBSEQUENCE WITH MAXIMUM PRODUCT
#include <bits/stdc++.h>
using namespace std;

// Function to find the subsequence with the maximum product
void findMaxProductSubsequence(int index, int arr[], int size, vector<int>& current, int& maxProduct, vector<int>& result) {
    // Base case: If we've considered all elements
    if (index == size) {
        int product = 1; // Calculate the product of the current subsequence
        for (int num : current) {
            product *= num;
        }
        // Update the maximum product and the resulting subsequence
        if (product > maxProduct) {
            maxProduct = product;
            result = current;
        }
        return;
    }

    // Include the current element in the subsequence
    current.push_back(arr[index]);
    findMaxProductSubsequence(index + 1, arr, size, current, maxProduct, result);

    // Exclude the current element from the subsequence
    current.pop_back();
    findMaxProductSubsequence(index + 1, arr, size, current, maxProduct, result);
}

int main() {
    int arr[] = {3, 2, -5, -1, 7, -6, 8}; // Input array
    int size = 7;                        // Size of the array

    vector<int> current;                 // Temporary vector to store the current subsequence
    int maxProduct = INT_MIN;            // Variable to store the maximum product
    vector<int> result;                  // Vector to store the subsequence with the maximum product

    // Find the maximum product subsequence
    findMaxProductSubsequence(0, arr, size, current, maxProduct, result);

    // Output the result
    cout << "Subsequence with maximum product: ";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    cout << "Maximum product: " << maxProduct << endl;

    return 0;
}
