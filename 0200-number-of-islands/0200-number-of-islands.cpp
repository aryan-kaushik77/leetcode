class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>>vis(m,vector<int>(n,0));
        int dr[]={1,-1,0,0};
        int dc[]={0,0,1,-1};
        int count=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(vis[i][j]==1){
                    continue;
                }
                if(grid[i][j]=='1'){
                    count++;
                    vis[i][j]=1;
                    queue<pair<int,int>>q;
                    q.push({i,j});
                    while(!q.empty()){
                        auto[r,c]=q.front();
                        q.pop();
                        for(int k=0;k<4;k++){
                            int nr=r+dr[k];
                            int nc=c+dc[k];
                            if(nr>=0 && nr<m && nc>=0 && nc<n && grid[nr][nc]=='1'&& !vis[nr][nc]){
                                q.push({nr,nc});
                                vis[nr][nc]=1;
                            }
                        }
                    }
                }
            }
        }
    return count;
    }
};