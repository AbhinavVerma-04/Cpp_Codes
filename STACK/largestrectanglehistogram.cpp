//LEETCODE 84
#include <bits/stdc++.h>
using namespace std;

vector<int> nextSmallerLeft(vector<int>& heights) {
    int n = heights.size();
    vector<int> nse(n, -1);
    stack<int> st;

    for (int i = 0; i < n; i++) {
        while (!st.empty() && heights[st.top()] >= heights[i])
            st.pop();
        if (!st.empty())
            nse[i] = st.top();
        st.push(i);
    }
    return nse;
}

vector<int> nextSmallerRight(vector<int>& heights) {
    int n = heights.size();
    vector<int> nse(n, n);
    stack<int> st;

    for (int i = n - 1; i >= 0; i--) {
        while (!st.empty() && heights[st.top()] >= heights[i])
            st.pop();
        if (!st.empty())
            nse[i] = st.top();
        st.push(i);
    }
    return nse;
}

int main() {
    vector<int> heights{2, 4};
    int n = heights.size();

    vector<int> nsl = nextSmallerLeft(heights);
    vector<int> nsr = nextSmallerRight(heights);

    cout << "Heights: ";
    for (int i : heights)
        cout << i << " ";

    cout << "\nNext Smaller Left (nsl): ";
    for (int i : nsl)
        cout << i << " ";

    cout << "\nNext Smaller Right (nsr): ";
    for (int i : nsr)
        cout << i << " ";
    int maxArea = 0;
    for (int i = 0; i < n; i++) {
        int width = nsr[i] - nsl[i] - 1;
        int area = heights[i] * width;
        maxArea = max(maxArea, area);
    }
    cout << "\nMaximum Area: " << maxArea;
    return 0;
}
