class Solution {
public:
    bool bfs(int v,vector<vector<int>>& graph,vector<int>&color){
        queue<int> q;
        q.push(v);
        color[v]=0;
        while(!q.empty()){
            int node=q.front();
            q.pop();    
            for(int x:graph[node]){
                if(color[node]==0){
                    if(color[x]==0){
                        return false;
                        }
                    else if(color[x]==-1){
                        q.push(x);
                        color[x]=1;
                    }
                }
                else if(color[node]==1){
                    if(color[x]==1){
                        return false;
                        }
                    else if(color[x]==-1){
                        q.push(x);
                        color[x]=0;
                    }
                }
            }
        }
        return true;
    }

    
    bool isBipartite(vector<vector<int>>& graph) {
        int v=graph.size();
        vector<int>color(v,-1);

        for(int i=0;i<v;i++){
            if(color[i]==-1){
                if(bfs(i,graph,color)==false){
                    return false;
                }
            }
        }
        return true;
    }
};