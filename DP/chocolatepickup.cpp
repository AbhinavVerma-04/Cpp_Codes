// GFG CHOCOLATE PICKUP
#include <bits/stdc++.h>
using namespace std;
int chocolate(int i, int j1, int j2, int n, int m, vector<vector<int>>& grid) {
    if (j1 < 0 || j2 < 0 || j1 > m - 1 || j2 > m - 1)
        return -1e8;
    if (i == n - 1) {
        if (j1 == j2)
            return grid[i][j1];
        else
            return grid[i][j1] + grid[i][j2];
    }
    int maxi = -1e8;
    for (int dj1 = -1; dj1 <= 1; dj1++) {
        for (int dj2 = -1; dj2 <= 1; dj2++) {
            if (j1 == j2)
                maxi = max(grid[i][j1] + chocolate(i + 1, j1 + dj1, j2 + dj2, n, m, grid), maxi);
            else
                maxi = max(grid[i][j1] + grid[i][j2] + chocolate(i + 1, j1 + dj1, j2 + dj2, n, m, grid), maxi);
        }
    }
    return maxi;
}
int memoisation(int i, int j1, int j2, int n, int m, vector<vector<int>>& grid, vector<vector<vector<int>>>& dp) {
    if (j1 < 0 || j2 < 0 || j1 > m - 1 || j2 > m - 1)
        return -1e8;
    if (i == n - 1) {
        if (j1 == j2)
            return grid[i][j1];
        else
            return grid[i][j1] + grid[i][j2];
    }
    if (dp[i][j1][j2] != -1)
        return dp[i][j1][j2];
    int maxi = -1e8;
    for (int dj1 = -1; dj1 <= 1; dj1++) {
        for (int dj2 = -1; dj2 <= 1; dj2++) {
            if (j1 == j2)
                maxi = max(grid[i][j1] + memoisation(i + 1, j1 + dj1, j2 + dj2, n, m, grid, dp), maxi);
            else
                maxi = max(grid[i][j1] + grid[i][j2] + memoisation(i + 1, j1 + dj1, j2 + dj2, n, m, grid, dp), maxi);
        }
    }
    return dp[i][j1][j2] = maxi;
}
int tabulation(int n, int m, vector<vector<int>>& grid) {
    vector<vector<vector<int>>> tab(n, vector<vector<int>>(m, vector<int>(m, 0)));
    for (int j1 = 0; j1 < m; j1++) {
        for (int j2 = 0; j2 < m; j2++) {
            if (j1 == j2)
                tab[n - 1][j1][j2] = grid[n - 1][j1];
            else
                tab[n - 1][j1][j2] = grid[n - 1][j1] + grid[n - 1][j2];
        }
    }
    for (int i = n - 2; i >= 0; i--) {
        for (int j1 = 0; j1 < m; j1++) {
            for (int j2 = 0; j2 < m; j2++) {
                int maxi = -1e8;
                for (int dj1 = -1; dj1 <= 1; dj1++) {
                    for (int dj2 = -1; dj2 <= 1; dj2++) {
                        int value = 0;
                        if (j1 == j2)
                            value = grid[i][j1];
                        else
                            value = grid[i][j1] + grid[i][j2];
                        if (j1 + dj1 >= 0 && j1 + dj1 < m && j2 + dj2 >= 0 && j2 + dj2 < m)
                            value += tab[i + 1][j1 + dj1][j2 + dj2];
                        else
                            value += -1e8;
                        maxi = max(value, maxi);
                    }
                }
                tab[i][j1][j2] = maxi;
            }
        }
    }
    return tab[0][0][m - 1];
}
int main() {
    vector<vector<int>> grid{{3, 1, 1}, {2, 5, 1}, {1, 5, 5}, {2, 1, 1}};
    int n = 4;
    int m = 3;
    vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(m, -1)));
    cout << chocolate(0, 0, m - 1, n, m, grid) << endl;
    cout << memoisation(0, 0, m - 1, n, m, grid, dp) << endl;
    cout << tabulation(n, m, grid);
}