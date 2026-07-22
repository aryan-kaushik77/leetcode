class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();

        vector<int> prev(amount + 1, -1), curr(amount + 1, -1);

        prev[0] = 0;

        for (int j = 1; j <= amount; j++) {
            if (j % coins[0] == 0)
                prev[j] = j / coins[0];
        }

        for (int i = 1; i < n; i++) {
            curr[0] = 0;

            for (int j = 1; j <= amount; j++) {
                int notTake = prev[j];
                int take = -1;

                if (j >= coins[i] && curr[j - coins[i]] != -1)
                    take = curr[j - coins[i]] + 1;

                if (notTake == -1)
                    curr[j] = take;
                else if (take == -1)
                    curr[j] = notTake;
                else
                    curr[j] = min(notTake, take);
            }

            prev = curr;
        }

        return prev[amount];
    }
};