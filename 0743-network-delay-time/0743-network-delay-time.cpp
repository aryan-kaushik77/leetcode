class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<pair<int,int>>adj[n+1];
        for(auto &e:times){
            int u=e[0];
            int v=e[1];
            int wt=e[2];
            adj[u].push_back({v,wt});
        }
        vector<int>dist(n+1,INT_MAX);
        dist[k]=0;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        pq.push({0,k});
        while(!pq.empty()){
            auto[dis,node]=pq.top();
            pq.pop();
            if(dis>dist[node]){
                continue;
            }
            for(auto &y:adj[node]){
                int adjnode=y.first;
                int wt1=y.second;
                if(dist[adjnode]>dis+wt1){
                    dist[adjnode]=dis+wt1;
                    pq.push({dist[adjnode],adjnode});
                }
            }
        }
        int max1=0;
        for(int i=1;i<=n;i++){
            if(dist[i]==INT_MAX){
                return -1;
            }
            max1=max(max1,dist[i]);
        }
        return max1;
    }
};