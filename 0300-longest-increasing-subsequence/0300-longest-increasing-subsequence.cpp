class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector <int> dp (n,1);
        vector <int> parent (n,-1);
        int maxlength=1;
        int lastidx=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[i]>nums[j]&&dp[j]+1>dp[i]){
                    dp[i]=dp[j]+1;
                    parent[i]=j;
                }
                if(dp[i]>maxlength){
                    maxlength=dp[i];
                    lastidx=i;
                }

            }
        }
        return maxlength;
}
};