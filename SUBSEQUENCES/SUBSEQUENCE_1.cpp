//PRINTING ALL SUBSEQUENCES
#include <bits/stdc++.h>
using namespace std;

// Function to print all subsequences of the array
void printAllSubsequences(int index, int arr[], vector<int>& current, int size) {
    // Base case: If we've considered all elements
    if (index == size) {
        if (current.empty()) {
            cout << "{}"; // Print empty subsequence
        } else {
            for (int num : current) {
                cout << num << " ";
            }
        }
        cout << endl;
        return;
    }

    // Include the current element in the subsequence
    current.push_back(arr[index]);
    printAllSubsequences(index + 1, arr, current, size);

    // Exclude the current element from the subsequence
    current.pop_back();
    printAllSubsequences(index + 1, arr, current, size);
}

int main() {
    int arr[] = {3, 2, 5};  // Input array
    int size = 3;           // Size of the array
    vector<int> current;    // Temporary vector to store the current subsequence

    // Print all subsequences
    printAllSubsequences(0, arr, current, size);

    return 0;
}
