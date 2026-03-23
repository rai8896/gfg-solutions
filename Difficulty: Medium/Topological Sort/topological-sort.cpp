class Solution {
  public:
    void DFS(int node,vector<int>adj[],vector<bool>&visited,stack<int>&s)
    {
        visited[node]=1;
        //looks its neighbour one by one 
        // sare childreen dekhne ke baad us node ko stack me push karna hai 
        //yhi topological sort ka core concept hai yha
        for(int j=0;j<adj[node].size();j++)
        {
            if(!visited[adj[node][j]])
            {
                DFS(adj[node][j],adj,visited,s);
            }
        }
        s.push(node);
        
        
        
        
    }
    
    
    
    
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        // code here
        
        
        //convert it into adjancey list
        vector<int>adj[V];
        for(auto edge: edges)
        {
            int u=edge[0];
            int v=edge[1];
            adj[u].push_back(v);
            
        }
        
        vector<bool>visited(V,0);
        stack<int>s;
        for(int i=0;i<V;i++)
        {
            if(!visited[i])
            {
                DFS(i,adj,visited,s);
            }
        }
        vector<int>ans;
        while(!s.empty())
        {
            ans.push_back(s.top());
            s.pop();
        }
        
        return ans;
    }
};