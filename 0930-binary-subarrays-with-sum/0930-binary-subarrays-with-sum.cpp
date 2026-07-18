class Solution {
public:

    int atmost(vector<int>&nums,int goal){
        int one=0;
        int left=0;
        int ans=0;
        if(goal==-1){
            return 0;
        }
        for(int right=0;right<nums.size();right++){
            if(nums[right]==1){
                one++;
            }
            while(one>goal){
                if(nums[left]==1){
                    one--;
                }
                left++;
            }
            ans=ans+(right-left+1);
        }
        return ans;
    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return atmost(nums,goal)-atmost(nums,goal-1);
    }
};