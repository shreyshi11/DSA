#include <iostream>
#include <vector>
using namespace std;

int solve(int n, vector<int> &dp) {

    if(n <= 2)
        return n;

    if(dp[n] != -1)
        return dp[n];

    dp[n] = solve(n-1, dp) + solve(n-2, dp);

    return dp[n];
}

int main() {

    int n = 5;

    vector<int> dp(n+1, -1);

    cout << solve(n, dp);
}

// tabulation
int climbStairs(int n) {

    vector<int> dp(n+1);

    dp[1] = 1;
    dp[2] = 2;

    for(int i = 3; i <= n; i++) {
        dp[i] = dp[i-1] + dp[i-2];
    }

    return dp[n];
}