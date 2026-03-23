class Solution {
  public:
  
    bool DFS(int node,int parent,vector<int>adj[],vector<bool>&visited)
    {
        visited[node]=1;
        for(int j=0;j<adj[node].size();j++)
        {
            // 3cases
            //1st agr parent hai to skip
            //2nd agr already visited hai to return 1 mtlb cycle hai
            //3rd nhi to dfs chalao isi node se
            if(parent==adj[node][j])
            {
                continue;
            }
            if(visited[adj[node][j]])
            {
                return 1;
            }
            if(DFS(adj[node][j],node,adj,visited))
            {
                return 1;
            }
            
         }
         return 0;
        
    }
    bool isCycle(int V, vector<vector<int>>& edges) {
        // Code here
        
        
        // Step 1:  edge diya hua hai to hme adjacency list me convert krna pdega
        vector<int> adj[V];
        
        for(auto edge : edges)
        {
            int u = edge[0];
            int v = edge[1];
            
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        // dfs
        vector<bool>visited(V,0);
        
        //handle multiple component
        for(int i=0;i<V;i++)
        {
            if(!visited[i])
            {
                if(DFS(i,-1,adj,visited))
                {
                    return 1;
                }
            }
        
        
        }
        return 0;
        
    }
};