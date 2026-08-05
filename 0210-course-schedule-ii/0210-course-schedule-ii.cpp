class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int>indegree(numCourses,0);
        vector<int>adj[numCourses];
        for(auto &e:prerequisites){
            int u=e[0];
            int v=e[1];
            adj[u].push_back(v);
        }
        for(int i=0;i<numCourses;i++){
            for(int x:adj[i]){
                indegree[x]++;
            }
        }
        queue<int> q;

        for(int i=0;i<numCourses;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        vector<int>ans;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            ans.push_back(node);
            for(int y:adj[node]){
                indegree[y]--;
                if(indegree[y]==0){
                    q.push(y);
                }
            }
        }
        vector<int>a;
        reverse(ans.begin(),ans.end());
        if(ans.size()==numCourses){
            return ans;
        }
        else{
            return a;
        }
    }
};