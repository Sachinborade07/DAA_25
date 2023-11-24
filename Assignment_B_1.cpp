/*Implement a problem of activity selection problem 
with K persons.
Statement: Given two arrays S[] and E[] of size N denoting starting 
and closing time of the shops and an integer value K denoting the 
number of people, the task is to find out the maximum number of 
shops they can visit in total if they visit each shop optimally based 
on the following conditions:
 A shop can be visited by only one person
 A person cannot visit another shop if its timing collide with it
Input: S[] = {1, 8, 3, 2, 6}, E[] = {5, 10, 6, 5, 9}, K = 2
Output: 4
Input: S[] = {1, 2, 3}, E[] = {3, 4, 5}, K = 2
Output: 3 
*/


//There are two way to sort the shops 
// 1. On their opening time and
// 2. On their closing time  
// We Have sorting the shops on their end time and we are visiting the shops 


#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Shop {
    int start;
    int end;
};

bool sortByEnd(const Shop &a, const Shop &b) {
    return a.end < b.end;
}

int maxShopsVisited(vector<int>& S, vector<int>& E, int K) {
    int N = S.size();
    if (N == 0 || K == 0) return 0;

    vector<Shop> shops(N);
    for (int i = 0; i < N; ++i) {
        shops[i].start = S[i];
        shops[i].end = E[i];
    }

    
    sort(shops.begin(), shops.end(), sortByEnd);

    vector<vector<int>> dp(K + 1, vector<int>(N + 1, 0));

    for (int i = 1; i <= K; ++i) {
        for (int j = 1; j <= N; ++j) {
            int included = 0, excluded = 0;

            excluded = dp[i][j - 1];

            int idx = upper_bound(shops.begin(), shops.end(), shops[j - 1],
                                  sortByEnd) - shops.begin();

            if (idx >= 0 && idx < j) {
                included = 1 + dp[i - 1][idx];
            }

            dp[i][j] = max(included, excluded);
        }
    }

    return dp[K][N];
}

int main() {
    vector<int> S1 = {1, 8, 3, 2, 6};
    vector<int> E1 = {5, 10, 6, 5, 9};
    int K1 = 2;
    cout << "Maximum number of shops visited: " << maxShopsVisited(S1, E1, K1) << endl;

    vector<int> S2 = {1, 2, 3};
    vector<int> E2 = {3, 4, 5};
    int K2 = 2;
    cout << "Maximum number of shops visited: " << maxShopsVisited(S2, E2, K2) << endl;

    return 0;
}
