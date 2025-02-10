//LEETCODE 735
#include <bits/stdc++.h>
using namespace std;

vector<int> asteroidCollision(vector<int>& asteroids) {
    stack<int> st;
    
    for (int asteroid : asteroids) {
        bool destroyed = false;

        while (!st.empty() && asteroid < 0 && st.top() > 0) {
            if (abs(asteroid) > st.top()) {
                st.pop();  // Destroy the right-moving asteroid
                continue;
            } 
            else if (abs(asteroid) == st.top()) {
                st.pop();  // Both asteroids destroy each other
            }
            destroyed = true;
            break;
        }

        if (!destroyed) {
            st.push(asteroid);
        }
    }

    vector<int> result(st.size());
    for (int i = result.size() - 1; i >= 0; i--) {
        result[i] = st.top();
        st.pop();
    }
    return result;
}

int main() {
    vector<int> asteroids = {5, 10, -5};
    vector<int> result = asteroidCollision(asteroids);
    
    cout << "Remaining asteroids: ";
    for (int asteroid : result) {
        cout << asteroid << " ";
    }
    cout << endl;
    
    return 0;
}
