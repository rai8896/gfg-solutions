class Solution {
  public:
    vector<int> bfs(vector<vector<int>> &adj) {
        // code here
         int V=adj.size();
        queue<int>q;
        q.push(0);
        vector<bool>visited(V,0);
        visited[0]=1;
        vector<int>ans;
        int node;
        while(!q.empty())
        {
            node=q.front();
            q.pop();
            ans.push_back(node);
            
            for(int j=0;j<adj[node].size();j++)
            {
                if(!visited[adj[node][j]])
                {
                   visited[adj[node][j]]=1;
                    q.push(adj[node][j]);
                }
            }
        }
        return ans;
        
        
        
    }
}; 