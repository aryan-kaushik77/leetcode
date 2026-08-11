class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        const long long MOD=1e9+7;

        vector<pair<int,int>> adj[n];

        for(auto &e:roads){
            int u=e[0];
            int v=e[1];
            int wt=e[2];

            adj[u].push_back({v,wt});
            adj[v].push_back({u,wt});
        }

        vector<long long> dist(n,LLONG_MAX);
        vector<long long> ways(n,0);

        priority_queue<
            pair<long long,int>,
            vector<pair<long long,int>>,
            greater<pair<long long,int>>
        > pq;

        dist[0]=0;
        ways[0]=1;

        pq.push({0,0});

        while(!pq.empty()){
            auto [d,u]=pq.top();
            pq.pop();

            if(d>dist[u])
                continue;

            for(auto [v,wt]:adj[u]){

                if(d+wt<dist[v]){
                    dist[v]=d+wt;
                    ways[v]=ways[u];

                    pq.push({dist[v],v});
                }

                else if(d+wt==dist[v]){
                    ways[v]=(ways[v]+ways[u])%MOD;
                }
            }
        }

        return ways[n-1];
    }
};