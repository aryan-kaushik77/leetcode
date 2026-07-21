class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        int n = nums.size();

        for (int x : nums)
            sum += x;

        if (sum % 2)
            return false;

        int target = sum / 2;

        vector<int> prev(target + 1, 0), curr(target + 1, 0);

        prev[0] = 1;
        if (nums[0] <= target)
            prev[nums[0]] = 1;

        for (int i = 1; i < n; i++) {
            curr[0] = 1;

            for (int j = 1; j <= target; j++) {
                int take = 0;
                if (nums[i] <= j)
                    take = prev[j - nums[i]];

                int not_take = prev[j];

                curr[j] = take || not_take;
            }

            prev = curr;
        }

        return prev[target];
    }
};