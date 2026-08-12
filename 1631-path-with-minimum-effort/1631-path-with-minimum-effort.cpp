class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int rows=heights.size();
        int cols=heights[0].size();
        vector<vector<int>>dist(rows,vector<int>(cols,INT_MAX));

        priority_queue<
            pair<int,pair<int,int>>,
            vector<pair<int,pair<int,int>>>,
            greater<pair<int,pair<int,int>>>
        >pq;
        int dr[]={1,-1,0,0};
        int dc[]={0,0,1,-1};
        dist[0][0]=0;
        pq.push({0,{0,0}});
        while(!pq.empty()){
            auto[effort,pos]=pq.top();
            pq.pop();
            int r=pos.first;
            int c=pos.second;
            if(effort>dist[r][c]){
                continue;
            }
            if(r==rows-1 && c==cols-1){
                return effort;
            }
            for(int i=0;i<4;i++){
                int nr=r+dr[i];
                int nc=c+dc[i];
                if(nr>=0 && nr<rows && nc>=0 && nc<cols){
                    int diff=abs(heights[r][c]-heights[nr][nc]);
                    int neweffort=max(effort,diff);
                    if(dist[nr][nc]>neweffort){
                        dist[nr][nc]=neweffort;
                        pq.push({neweffort,{nr,nc}});
                    }
                }
            }
        }
        return 0;
    }
};