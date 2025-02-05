//GFG NEXT GREATER ELEMENT
#include <bits/stdc++.h>
using namespace std;
void nextLargerElement(vector<int>& arr) {
    int n = arr.size();
    vector<int> nge(n, -1);
    stack<int> st;
    for (int i = n - 1; i >= 0; i--) {
        while (!st.empty() && st.top() <= arr[i]) {
            st.pop();
        }
        if (!st.empty()) {
            nge[i] = st.top();
        }
        st.push(arr[i]);
    }
    for (int i : nge) {
        cout << i << " ";
    }
    cout << endl;
}
int main() {
    vector<int> arr{6, 8, 0, 1, 3};
    nextLargerElement(arr);
}