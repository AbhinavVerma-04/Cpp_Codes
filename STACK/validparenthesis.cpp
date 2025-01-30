// LEETCODE 20
#include <bits/stdc++.h>
using namespace std;
bool isValid(string s) {
    stack<char> st;
    for (char i : s) {
        if (st.empty())
            st.push(i);
        else if ((st.top() == '(' && i == ')') ||
                 (st.top() == '{' && i == '}') ||
                 (st.top() == '[' && i == ']')) {
            st.pop();
        } else {
            st.push(i);
        }
    }
    if (st.empty())
        return true;
    else
        return false;
}
int main() {
    string s = "()[]{}";
    cout << isValid(s);
}