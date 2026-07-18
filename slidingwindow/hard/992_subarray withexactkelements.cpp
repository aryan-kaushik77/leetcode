class Solution {
public:

    int atMost(vector<int>& nums, int k){

        unordered_map<int,int> mp;

        int left=0;
        int ans=0;

        for(int right=0; right<nums.size(); right++){

            mp[nums[right]]++;

            while(mp.size()>k){

                mp[nums[left]]--;

                if(mp[nums[left]]==0)
                    mp.erase(nums[left]);

                left++;
            }

            ans += right-left+1;
        }

        return ans;
    }

    int subarraysWithKDistinct(vector<int>& nums, int k) {

        return atMost(nums,k)-atMost(nums,k-1);

    }
};

// ______________________________________________________
// 2nd method
// ______________________________________________________
// class Solution {
// public:
//     int subarraysWithKDistinct(vector<int>& nums, int k) {
//         unordered_map<int, int> mp;

//         int left = 0;
//         int prefix = 0;
//         int ans = 0;

//         for (int right = 0; right < nums.size(); right++) {

//             // Include current element
//             mp[nums[right]]++;

//             // Too many distinct elements
//             while (mp.size() > k) {
//                 mp[nums[left]]--;

//                 if (mp[nums[left]] == 0)
//                     mp.erase(nums[left]);

//                 left++;
//                 prefix = 0;
//             }

//             // Remove unnecessary duplicates from the left
//             while (mp.size() == k && mp[nums[left]] > 1) {
//                 mp[nums[left]]--;
//                 left++;
//                 prefix++;
//             }

//             // Count all valid subarrays ending at 'right'
//             if (mp.size() == k)
//                 ans += prefix + 1;
//         }

//         return ans;
//     }
// };