//LEETCODE 1047
#include <bits/stdc++.h>
using namespace std;
string removeDuplicates(string s) {
    stack<char> st;
    for (char ch : s) {
        if (st.empty())
            st.push(ch);
        else if (!st.empty() && ch == st.top())
            st.pop();
        else
            st.push(ch);
    }
    string str = "";
    while (!st.empty()) {
        str = st.top() + str;
        st.pop();
    }
    return str;
}
int main() {
    string s = "abbaca";
    cout << removeDuplicates(s);
}