//LEETCODE 85
#include <bits/stdc++.h>
using namespace std;

vector<int> nextSmallerLeft(vector<int> &heights) {
    int n = heights.size();
    vector<int> nsl(n, -1);
    stack<int> st;

    for (int i = 0; i < n; i++) {
        while (!st.empty() && heights[st.top()] >= heights[i])
            st.pop();
        if (!st.empty())
            nsl[i] = st.top();
        st.push(i);
    }
    return nsl;
}

vector<int> nextSmallerRight(vector<int> &heights) {
    int n = heights.size();
    vector<int> nsr(n, n);
    stack<int> st;

    for (int i = n - 1; i >= 0; i--) {
        while (!st.empty() && heights[st.top()] >= heights[i])
            st.pop();
        if (!st.empty())
            nsr[i] = st.top();
        st.push(i);
    }
    return nsr;
}

int largestRectangleArea(vector<int>& heights) {
    int n = heights.size();
    vector<int> nsl = nextSmallerLeft(heights);
    vector<int> nsr = nextSmallerRight(heights);
    int maxArea = 0;

    for (int i = 0; i < n; i++) {
        int width = nsr[i] - nsl[i] - 1;
        maxArea = max(maxArea, heights[i] * width);
    }
    return maxArea;
}

int maximalRectangle(vector<vector<char>>& matrix) {
    if (matrix.empty()) return 0;
    
    int rows = matrix.size(), cols = matrix[0].size();
    vector<int> heights(cols, 0);
    int maxArea = 0;

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            heights[j] = (matrix[i][j] == '1') ? heights[j] + 1 : 0;
        }
        maxArea = max(maxArea, largestRectangleArea(heights));
    }
    return maxArea;
}

int main() {
    vector<vector<char>> matrix = {
        {'1', '0', '1', '0', '0'},
        {'1', '0', '1', '1', '1'},
        {'1', '1', '1', '1', '1'},
        {'1', '0', '0', '1', '0'}
    };
    cout << "Maximal Rectangle Area: " << maximalRectangle(matrix) << endl;
    return 0;
}
