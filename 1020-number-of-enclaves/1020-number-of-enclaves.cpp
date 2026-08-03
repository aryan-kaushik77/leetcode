class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        int count=0;
        queue<pair<int,int>>q;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    if(i==0 || j==0 || i==m-1 || j==n-1){
                        q.push({i,j});
                        grid[i][j]=0;
                    }
                    count++;
                    
                }
            }
        }
        int dr[]={1,-1,0,0};
        int dc[]={0,0,1,-1};
        while(!q.empty()){
            count--;

            auto[r,c]=q.front();
            q.pop();
            for(int i=0;i<4;i++){
                int nr=r+dr[i];
                int nc=c+dc[i];
                if(nr>0 && nr<m-1 && nc>0 && nc<n-1 && grid[nr][nc]==1){
                    grid[nr][nc]=0;
                    q.push({nr,nc});

                }
            }
        }
    return count;
    }
};