class Solution {
public:
    void dfs(int v,vector<vector<int>>& isConnected,vector<int>&vis){
        int n=isConnected.size();
        vis[v]=1;
        for(int i=0;i<n;i++){
            if(i==v){
                continue;
            }
            if(isConnected[v][i]==1 && vis[i]==0){
                dfs(i,isConnected,vis);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int count=0;
        int n1=isConnected.size();
        vector<int>vis(n1,0);
        for(int i=0;i<n1;i++){
            if(vis[i]==0){
                dfs(i,isConnected,vis);
                count++;
            }
        }
    return count;
    }
};