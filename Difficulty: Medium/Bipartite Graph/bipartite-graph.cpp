class Solution {
  public:
    bool isBipartite(int V, vector<vector<int>> &edges) {
        // Code here
        
        
        vector<int>adj[V];
        for(auto edge:edges)
        {
            int u=edge[0];
            int v=edge[1];
            
        adj[u].push_back(v);
        adj[v].push_back(u);
        }
        
        
       vector<int>color(V,-1);
       queue<int>q;
       q.push(0);
       color[0]=0;
       while(!q.empty())
       {
           
           int node=q.front();
           q.pop();
           for(int j=0;j<adj[node].size();j++)
           {
               //if not colored
               if(color[adj[node][j]]==-1)
               {
                   color[adj[node][j]]=(color[node]+1)%2;
                   q.push(adj[node][j]);
               }
               //if colored
               else
               {
                   if(color[node]==color[adj[node][j]])
                   {
                       return 0;
                   }
               }
               
           }
       }
       return 1;
        
    }
};