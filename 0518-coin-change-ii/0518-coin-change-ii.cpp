class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        constexpr long long CAP = 2'000'000'000LL; // safely above INT32_MAX

        vector<long long> prev(amount + 1, 0), curr(amount + 1, 0);
        for (int j = 0; j <= amount; j++)
            prev[j] = (j % coins[0] == 0);

        for (int i = 1; i < n; i++) {
            for (int j = 0; j <= amount; j++) {
                curr[j] = prev[j];
                if (j >= coins[i])
                    curr[j] = min(curr[j] + curr[j - coins[i]], CAP);
            }
            prev = curr;
        }

        return (int)prev[amount];
    }
};