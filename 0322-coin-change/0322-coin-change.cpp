class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<int>prev(amount+1,-1);
        vector<int>curr(amount+1,-1);
        prev[0]=0;
        for(int i=1;i<amount+1;i++){
            if(i%coins[0]==0){
                prev[i]=i/coins[0];
            }
        }
        for(int i=1;i<n;i++){
            curr[0]=0;
            for(int j=1;j<=amount;j++){
                int nottake=prev[j];
                int take=-1;
                if(j>=coins[i]&&curr[j-coins[i]]!=-1){
                    take=1+(curr[j-coins[i]]);
                }
                if(nottake==-1){
                    curr[j]=take;
                }
                else if(take==-1){
                    curr[j]=nottake;
                }
                else{
                    curr[j]=min(take,nottake);
                }
            }
            prev=curr;

        }
    return prev[amount];
    }

};