class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int m=image.size();
        int n=image[0].size();
        queue<pair<int,int>>q;
        int original=image[sr][sc];
        q.push({sr,sc});
        if(image[sr][sc]==color){
            return image;
        }
        image[sr][sc]=color;
        int dr[]={1,-1,0,0};
        int dc[]={0,0,1,-1};
        while(!q.empty()){
            auto[r,c]=q.front();
            q.pop();
            for(int k=0;k<4;k++){
                int nr=r+dr[k];
                int nc=c+dc[k];
                if(nr>=0 && nr<m && nc>=0 && nc<n && image[nr][nc]==original){
                    image[nr][nc]=color;
                    q.push({nr,nc});
                }
            }

        }
        return image;
        }
};