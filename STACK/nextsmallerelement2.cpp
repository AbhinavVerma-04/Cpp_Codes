//NEXT SMALLEST ELEMENT(left side)
#include <bits/stdc++.h>
using namespace std;

void nextSmallerElementLeft(vector<int>& arr) {
    int n = arr.size();
    vector<int> nse(n, -1);
    stack<int> st;

    for (int i = 0; i < n; i++) {
        while (!st.empty() && st.top() >= arr[i]) {
            st.pop();
        }
        if (!st.empty()) {
            nse[i] = st.top();
        }
        st.push(arr[i]);
    }

    for (int i : nse) {
        cout << i << " ";
    }
    cout << endl;
}

int main() {
    vector<int> arr{6, 8, 0, 1, 3};
    nextSmallerElementLeft(arr);
}
