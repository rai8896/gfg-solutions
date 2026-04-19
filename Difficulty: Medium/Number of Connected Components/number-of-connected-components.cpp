class Solution {
  public:
  
  void dfs(int node,vector<int>adjLs[],vector<bool>&visited)
  {
      visited[node]=true;
       for(int j=0;j<adjLs[node].size();j++)
     {
       if(!visited[adjLs[node][j]])
       {
           dfs(adjLs[node][j],adjLs,visited);
       }
   }
   
   
  }
    int countConnected(vector<vector<int>> adj, int V) {
        
        
        // code here
        
        vector<int>adjLs[V];
        for(int i=0;i<V;i++)
        {
            for(int j=0;j<V;j++)
            {
                if(adj[i][j]==1 && i!=j)
                {
                    adjLs[i].push_back(j);
                    adjLs[j].push_back(i);
                }
            }
        }
        
        vector<bool>visited(V,false);
        int count=0;
        for(int i=0;i<V;i++)
        {
            if(!visited[i])
            {
                count++;
                dfs(i,adjLs,visited);
            }
        }
        return count;
        
    }
};