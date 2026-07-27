class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int max1=1;
        int lastidx=0;
        int n=nums.size();
        vector <int> dp(n,1);
        vector <int> parent(n,-1);
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(dp[j]+1>dp[i] && nums[i]>nums[j]){
                    if(nums[j]%nums[i]==0 || nums[i]%nums[j]==0){
                        dp[i]=dp[j]+1;
                        parent[i]=j;
                    }

                }
                if(dp[i]>max1){
                    max1=dp[i];
                    lastidx=i;
                }
            }
        }
        vector<int> lis;
        while(lastidx!=-1){
            lis.push_back(nums[lastidx]);
            lastidx=parent[lastidx];
        }
        reverse(lis.begin(),lis.end());
        return lis;

    }
};