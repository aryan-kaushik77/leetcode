class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum=0;
        int n=nums.size();
        int target=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
        }
        if(sum%2==1){
            return false;
        }
        
        else{
            target=sum/2;
        }
        vector<vector<int>>arr(n,vector<int>(target+1,-1));
        for(int i=0;i<n;i++){
            arr[i][0]=1;
        }
        for(int i=1;i<target+1;i++){
            arr[0][i]=0;    
        }
        if(target>nums[0]){
            arr[0][nums[0]]=1;
        }
        for(int i=1;i<n;i++){
            for(int j=1;j<target+1;j++){
                int take=0;
                if(nums[i]<=j){
                    take=arr[i-1][j-nums[i]];
                }
                int not_take=arr[i-1][j];

                arr[i][j]=take || not_take;
            }
        }
    return arr[n-1][target];
    }
};