class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {

        int sum = 0;
        int n = nums.size();

        for (int x : nums)
            sum += x;

        if (abs(target) > sum || (sum + target) % 2)
            return 0;

        int req = (sum + target) / 2;

        vector<int> prev(req + 1, 0);
        vector<int> curr(req + 1, 0);

        if (nums[0] == 0) {
            prev[0] = 2;
        } else {
            prev[0] = 1;
            if (nums[0] <= req)
                prev[nums[0]] = 1;
        }

        for (int i = 1; i < n; i++) {

            for (int j = 0; j <= req; j++) {

                int not_take = prev[j];
                int take = 0;

                if (nums[i] <= j)
                    take = prev[j - nums[i]];

                curr[j] = take + not_take;
            }

            prev = curr;
        }

        return prev[req];
    }
};