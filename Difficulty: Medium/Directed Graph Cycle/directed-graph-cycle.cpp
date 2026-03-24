class Solution {
  public:
//   bool DetectCycle(int node,vector<int>adj[],vector<bool>&path,vector<bool>&visited)
//   {
      
//       visited[node]=1;
//       path[node]=1;
//       for(int j=0;j<adj[node].size();j++)
//       {
//           if(path[adj[node][j]])
//           {
//               return 1;
//           }
//         if(visited[adj[node][j]] )
//           {
//               continue;
//           }  
//           if(DetectCycle(adj[node][j],adj,path,visited))
//           {
//               return 1;
//           }
//       }
//       path[node]=0;
//       return 0;
      
      
//   }
    bool isCyclic(int V, vector<vector<int>> &edges) {
        // code here
        
        
    //     vector<int>adj[V];
    //     for(auto edge:edges)
    //     {
    //         int u=edge[0];
    //         int v=edge[1];
    //         adj[u].push_back(v);
    //     }
        
        
        
        
    // vector<bool>path(V,0);
    // vector<bool>visited(V,0);
    // for(int i=0;i<V;i++)
    // {
    //     if(!visited[i] && DetectCycle(i,adj,path,visited))
    //     {
    //         return 1;
    //     }
    // }
    // return 0;
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
        vector<int>adj[V];
        for(auto edge:edges)
        {
            int u=edge[0];
            int v=edge[1];
            adj[u].push_back(v);
        }
        
    
    
    
    
    
    
    
    
    vector<int>ans;
    vector<int>InDeg(V,0);
    // calculation of indegree
    for(int i=0;i<V;i++)
    {
        for(int j=0;j<adj[i].size();j++)
        {
            InDeg[adj[i][j]]++;
        }
    }
    
    queue<int>q;
    for(int i=0;i<V;i++)
    {
        if(InDeg[i]==0)
        {
            q.push(i);
        }
    }
    
    while(!q.empty())
    {
        int node=q.front();
        q.pop();
        ans.push_back(node);
        for(int j=0;j<adj[node].size();j++)
        {
            InDeg[adj[node][j]]--;
            if( InDeg[adj[node][j]]==0)
            {
                q.push(adj[node][j]);
            }
        }
    }
    int count=ans.size();
    return count!=V;
    
    
    
   }
};