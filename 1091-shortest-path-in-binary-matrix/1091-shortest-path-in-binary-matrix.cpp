class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        queue<pair<int,int>>q;
        int dr[]={1,-1,1,-1,0,0,1,-1};
        int dc[]={0,0,1,-1,1,-1,-1,1};
        q.push({0,0});
        if(grid[0][0]==1){
            return -1;
        }
        if(n==1){
            return 1;
        }
        vector<vector<int>>vis(n,vector<int>(n,0));
        vis[0][0]=1;
        int count=1;
        while(!q.empty()){
            int size=q.size();
            while(size--){
                auto[r,c]=q.front();
                q.pop();
                for(int i=0;i<8;i++){
                    int nr=r+dr[i];
                    int nc=c+dc[i];
                    if(nr>=0 && nr<n && nc>=0 && nc<n && vis[nr][nc]==0 && grid[nr][nc]==0){
                        q.push({nr,nc});
                        vis[nr][nc]=1;
                        if(nr==n-1 && nc==n-1){
                            return count+1;
                        }
                    }
                }
            }
            count++;
        }
        return -1;
    }
};