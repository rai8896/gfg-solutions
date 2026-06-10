class Solution {
  public:
  
  void dfs_stack_fill(int u,vector<int>adj[],vector<bool>&visited,stack<int>&st)
  {
      visited[u]=true;
      for(auto x:adj[u])
      {
          if(!visited[x])
          {
              dfs_stack_fill(x,adj,visited,st);
          }
      }
      st.push(u);
  }
  
  
    void dfsTraversal(int u,vector<int>Readj[],vector<bool>&visited)
    {
        
        visited[u]=true;
        for(auto &x:Readj[u])
        {
            if(!visited[x])
            {
                dfsTraversal(x,Readj,visited);
            }
        }
        
    }
    
    
    
    int kosaraju(int V, vector<vector<int>> &edges) {
        // code here
        
        
        // step 1 store order of dfs in stack
        vector<int>adj[V];
        vector<int>Readj[V];
        
        for(auto edge:edges)
        {
            int u=edge[0];
            int v=edge[1];
            adj[u].push_back(v);
            Readj[v].push_back(u);
        }
        
        stack<int>st;
        vector<bool>visited(V,false);
         for(int i=0;i<V;i++)
         {
             
             if(!visited[i])
             {
             dfs_stack_fill(i,adj,visited,st);
             }
         }
         
         
         // step 2 make a reverse grapd
         // done
         
         
         
         // step 3 call dfs based on stack oreder
         
         int countScc=0;
         visited=vector<bool>(V,false);
         
         while(!st.empty())
         {
             int node= st.top();
             st.pop();
             if(!visited[node])
             {
                  dfsTraversal(node,Readj,visited);
                  countScc++;
             }
         }
         return countScc;
        
    }
};