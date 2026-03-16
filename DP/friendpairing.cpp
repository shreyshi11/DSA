#include <iostream>
#include <vector>
using namespace std;

long long solve(int n, vector<long long> &dp) {
    
    if(n <= 2)
        return n;

    if(dp[n] != -1)
        return dp[n];

    dp[n] = solve(n-1, dp) + (n-1) * solve(n-2, dp);

    return dp[n];
}

int main() {
    
    int n = 4;
    vector<long long> dp(n+1, -1);

    cout << solve(n, dp);

}

// tabulation
long long friendPairing(int n) {

    vector<long long> dp(n+1);

    dp[1] = 1;
    dp[2] = 2;

    for(int i = 3; i <= n; i++) {
        dp[i] = dp[i-1] + (i-1) * dp[i-2];
    }

    return dp[n];
}
