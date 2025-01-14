#include <iostream>
#include <string.h>
#include <vector>
#include<unordered_map>

using namespace std;

class Solution {
public:
    int findLength(vector<int>& A, vector<int>& B) {
        int res = 0, m = A.size(), n = B.size();
        
        // dp[i][j] max len of repeated subarray give A[0...i] B[0...j]
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                dp[i][j] = (A[i - 1] == B[j - 1]) ? dp[i - 1][j - 1] + 1 : 0;
                res = max(res, dp[i][j]);
            }
        }
        return res;
    }
};