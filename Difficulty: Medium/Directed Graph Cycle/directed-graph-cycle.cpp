class Solution {
  public:
  bool dfs(int node,vector<int>adj[],int pathVis[],int vis[])
  {
      vis[node]=1;
      pathVis[node]=1;
      
      
      //traverse for adjacent node
      for(auto it:adj[node])
      {
          // if path is not visited
          if(!vis[it])
          {
              if(dfs(it,adj,pathVis,vis)==true) return true;
              
              
          }
              // if niode is previsioly visited but it has to be visited on the same path
              else if(pathVis[it])
              {
                  return true;
              }
          
      }
      pathVis[node]=0;
      return false;
  }
    bool isCyclic(int V, vector<vector<int>> &edge ) {
        // code here
        
        
        //adjancy list bnao
        vector<int>adj[V];
        
        for(auto & it:edge)
        {
            int u=it[0];
            int v=it[1];
            adj[u].push_back(v);
        
        }
        
        
        int vis[V]={0};
        int pathVis[V]={0};
        
        for(int i=0;i<V;i++)
        {
           if( dfs(i,adj,pathVis,vis) ==true)  return true;
        }
        return false;
        
            
        }
};