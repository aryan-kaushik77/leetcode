class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int zeroes=0;   
        int ans=0;
        int left=0;
        for(int right=0;right<nums.size();right++){
            if(nums[right]==0){
                if(zeroes>=k){
                    while(nums[left]){
                        left++;
                    }
                    left++;            
                }
                else{
                    zeroes++;
                }

            }
            ans=max(ans,right-left+1);
        }
    return ans;   
    }

};