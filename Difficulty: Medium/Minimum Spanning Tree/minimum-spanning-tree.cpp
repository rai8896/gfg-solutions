class Solution {
  public:
  typedef pair<int,int> P;
    int spanningTree(int V, vector<vector<int>>& edges) {
        // code here
        
        // adjancy list bnao
        vector<pair<int,int>>adj[V];
        for(auto edge:edges)
        {
            int u=edge[0];
            int v=edge[1];
            int w=edge[2];
            adj[u].push_back({v,w});
            adj[v].push_back({u,w});
        }
        
        vector<bool>inMST(V,false);
        priority_queue<P,vector<P>,greater<P>>pq;
        pq.push({0,0});
        int sum=0;
        while(!pq.empty())
        {
          int wt= pq.top().first;
          int node=pq.top().second;
          pq.pop();
          if(inMST[node]==true) continue;
          
          inMST[node]=true;
          sum+=wt;
          
          for(auto x:adj[node])
          {
              int ngbr=x.first;
              int ngbr_wt=x.second;
              
              if(inMST[ngbr]==false)
              {
                  pq.push({ngbr_wt,ngbr});
              }
          }
        }
        return sum;
        
        
    }
};