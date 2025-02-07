//LEETCODE 503
#include <bits/stdc++.h>
using namespace std;
void nextLargerElement(vector<int>& arr) {
    int n = arr.size();
    vector<int> nge(n, -1);
    stack<int> st;
    for (int i = 2 * n - 1; i >= 0; i--) {
        while (!st.empty() && st.top() <= arr[i % n]) {
            st.pop();
        }
        if (!st.empty()) {
            nge[i % n] = st.top();
        }
        st.push(arr[i % n]);
    }
    for (int i : nge) {
        cout << i << " ";
    }
    cout << endl;
}
int main() {
    vector<int> arr{1, 2, 3, 4, 3};
    nextLargerElement(arr);
}