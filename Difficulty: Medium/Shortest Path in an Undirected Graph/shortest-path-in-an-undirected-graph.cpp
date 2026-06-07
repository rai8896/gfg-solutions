class Solution {
  public:
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        // Code here
        
        //adjancxy list bmao
        vector<pair<int,int>>adj[n+1];
    
        
        
        for(auto x:edges)
        {
            int u=x[0];
            int v=x[1];
            int weight=x[2];
            adj[u].push_back({v,weight});
            adj[v].push_back({u,weight});
        }
        
        
        
        vector<int>dist(n+1,INT_MAX);
        vector<int>parent(n+1,-1);
        
        
        priority_queue< pair<int,int>,vector< pair<int,int>>,greater< pair<int,int>>>p;
        p.push({0,1});
        dist[1]=0;
        
        
        while(!p.empty())
        {
            int node=p.top().second;
            int distance=p.top().first;
            p.pop();
            
            
        // adjace node dekho
            for(auto x:adj[node])
            {
                int edgewight=x.second;
                int adjNode=x.first;
                
                
            /// relax the neighbour
                if(distance+edgewight<dist[adjNode])
                {
                    dist[adjNode]=distance+edgewight;
                    p.push({dist[adjNode],adjNode});
                    parent[adjNode]=node;
                    
                    
                }
            }
        
        
        }
        
        vector<int>path;
        if(parent[n]==-1)
        {
            path.push_back(-1);
            return path;
        }
        int dest=n;
        while(dest!=-1)
        {
            path.push_back(dest);
            dest=parent[dest];
        }
       
       path.push_back(dist[n]);
       reverse(path.begin(),path.end());
       return path;
       
       
        
        
    }
};