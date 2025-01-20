//PRINTING AND COUNTING THE NUMBER OF SUBSEQUENCES WITH SUM K
#include <bits/stdc++.h>
using namespace std;

// Function to print subsequences with a sum equal to k
void findSubsequencesWithSum(int index, int arr[], vector<int>& current, int size, int targetSum, int& count) {
    // Base case: If all elements are considered
    if (index == size) {
        int currentSum = 0;
        for(int i : current){
            currentSum += i;
        }
        if (currentSum == targetSum) {
            cout << "Subsequence: ";
            for (int num : current) {
                cout << num << " ";
            }
            cout << endl;
            count++; // Increment the count of valid subsequences
        }
        return;
    }

    // Include the current element in the subsequence
    current.push_back(arr[index]);
    findSubsequencesWithSum(index + 1, arr, current, size, targetSum, count);

    // Exclude the current element from the subsequence
    current.pop_back();
    findSubsequencesWithSum(index + 1, arr, current, size, targetSum, count);
}

int main() {
    int arr[] = {10, 2, 8, 6, 4, 3, 7}; // Input array
    int size = 7;                      // Size of the array
    int targetSum = 10;                // Target sum to find
    vector<int> current;               // Temporary vector to store the current subsequence
    int count = 0;                     // Counter for valid subsequences

    // Find and print all subsequences with a sum equal to the target
    findSubsequencesWithSum(0, arr, current, size, targetSum, count);

    // Print the total count of valid subsequences
    cout << "Total subsequences with sum " << targetSum << ": " << count << endl;

    return 0;
}
