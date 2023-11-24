 /* Implement Coin Change problem.
Statement Given an integer array of coins[ ] of 
size N representing different types of currency and an 
integer sum, The task is to find the number of ways to 
make sum by using different combinations 
from coins[]. 
Note: Assume that you have an infinite supply of each 
type of coin.
Input: sum = 4, coins[] = {1,2,3}, Output: 4
Input: sum = 10, coins[] = {2, 5, 3, 6} Output: 5 */ 


// Here we are solving this problem using dynamic programming 
// Here we need to find the number of ways to make a given sum using different combinaiton of coins


#include <iostream>
#include <vector>

using namespace std;

int coinChangeWays(int sum, vector<int>& coins) {
    vector<int> dp(sum + 1, 0);
    dp[0] = 1;

    for (int coin : coins) {
        for (int i = coin; i <= sum; ++i) {
            dp[i] += dp[i - coin];
        }
    }

    return dp[sum];
}

int main() {
    int sum1 = 4;
    vector<int> coins1 = {1, 2, 3};
    cout << "Number of ways to make sum 4: " << coinChangeWays(sum1, coins1) << endl;

    int sum2 = 10;
    vector<int> coins2 = {2, 5, 3, 6};
    cout << "Number of ways to make sum 10: " << coinChangeWays(sum2, coins2) << endl;

    return 0;
}



  
