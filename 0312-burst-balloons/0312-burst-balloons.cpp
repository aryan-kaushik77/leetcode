class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int x=nums.size();
        nums.push_back(1);
        nums.insert(nums.begin(),1);
        vector<vector<int>>dp(x+2,vector<int>(x+2,0));
        for(int i=x;i>=1;i--){
            for(int j=1;j<=x;j++){
                if(i>j){
                    continue;
                }
                int mini=INT_MIN;
                for(int k=i;k<=j;k++){
                    int cost=(nums[k]*nums[i-1]*nums[j+1])+dp[i][k-1]+dp[k+1][j];
                    mini=max(mini,cost);
                }
                dp[i][j]=mini;
            }
        }
        return dp[1][x];
    }
};