class Solution {
  public:
  
    void dfs(int node,vector<vector<int>>&adj,vector<bool>&visited)
    {
        visited[node]=1;
        for(auto it :adj[node])
        {
            if(!visited[it])
            {
                dfs(it,adj,visited);
            }
        }
        
    }
    
    
    int countConnected(int V, vector<vector<int>>& edges) {
        // code here
        
        // 
        //   ges = [[0,1], [2,1], [3,4]]
        
        // Iska matlab:
        // 0 connected to 1
        // 2 connected to 1
        // 3 connected to 4
        
         // Step 1: adjacency list
        vector<vector<int>>adj(V);
        for(int i=0;i<edges.size();i++)
        {
            int u=edges[i][0];
            int v=edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        vector<bool>visited(V,0);
        // travers all node
        int count=0;
        for(int i=0;i<V;i++)
        {
            if(!visited[i])
            {
               count++;
                dfs(i,adj,visited);
            }
        }
        return count;
        
    }
};