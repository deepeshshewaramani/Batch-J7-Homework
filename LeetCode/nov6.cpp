
class Solution {
public:
    int numberOfPermutations(int n, vector<vector<int>>& requirements) {
        const int MOD = 1e9 + 7;

        vector<int> req(n, -1);

        for (auto& r : requirements) {
            req[r[0]] = r[1];
        }

        int maxInv = req[n - 1];

        vector<int> dp(maxInv + 1, 0);
        dp[0] = 1;

        for (int i = 1; i <= n; i++) {
            vector<int> ndp(maxInv + 1, 0);

            long long window = 0;

            for (int j = 0; j <= maxInv; j++) {
                window += dp[j];

                if (j >= i) {
                    window -= dp[j - i];
                }

                window = (window % MOD + MOD) % MOD;

                ndp[j] = window;
            }

            int required = req[i - 1];

            if (required != -1) {
                for (int j = 0; j <= maxInv; j++) {
                    if (j != required) {
                        ndp[j] = 0;
                    }
                }
            }

            dp = ndp;
        }

        return dp[maxInv];
    }
};
