class Solution {
public:
    int minCost(int n, vector<int>& cuts) {
        int x=cuts.size();
        cuts.push_back(n);
        cuts.insert(cuts.begin(),0);
        sort(cuts.begin(),cuts.end());
        vector<vector<int>>dp(x+2,vector<int>(x+2,0));
        for(int i=x;i>=1;i--){
            for(int j=1;j<=x;j++){
                if(i>j){
                    continue;
                }
                int mini=INT_MAX;
                for(int k=i;k<=j;k++){
                    int cost=cuts[j+1]-cuts[i-1]+dp[i][k-1]+dp[k+1][j];
                    mini=min(mini,cost);
                }
                dp[i][j]=mini;
            }
        }
        return dp[1][x];
    }
};