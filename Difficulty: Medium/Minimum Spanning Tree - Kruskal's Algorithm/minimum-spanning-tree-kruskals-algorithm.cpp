// User function Template for C++
class Solution {
  public:
      int find(int u,vector<int>&parent)
      {
          if(u==parent[u])
          {
              return u;
          }
          
          return parent[u]=find(parent[u],parent);
      }
      void UnionByRank(int x,int y,vector<int>&parent,vector<int>&rank)
      {
          int x_parent=find(x,parent);
          int y_parent=find(y,parent);
          
          if(x_parent==y_parent)
          {
              return;
          }
          if(rank[x_parent]<rank[y_parent])
          {
              parent[x_parent]=y_parent;
          }
          else if(rank[x_parent]>rank[y_parent])
          {
              parent[y_parent]=x_parent;
          }
          else{
              parent[y_parent]=x_parent;
              rank[x_parent]++;
          }
      }
  
  
    int kruskalsMST(int V, vector<vector<int>> &edges) {
        // code here
        
        
        vector<int>parent(V);
        vector<int>rank(V,0);
        for(int i=0;i<V;i++)
        {
            parent[i]=i;
        }
        //priority queue
        //wt,u,v
       priority_queue<
    pair<int,pair<int,int>>,
    vector<pair<int,pair<int,int>>>,
    greater<pair<int,pair<int,int>>>
            > pq;
       
        
        for(auto edge:edges)
        {
            int u=edge[0];
            int v=edge[1];
            int w=edge[2];
            pq.push({w,{u,v}});
        }
       
       int cost=0;
       //int edges=0;
       while(!pq.empty())
       {
           int wt=pq.top().first;
           int u=pq.top().second.first;
           int v=pq.top().second.second;
           pq.pop();
           
           
           // check if they are in different set
           if(find(u,parent)!=find(v,parent))
           {
               cost=cost+wt;
              UnionByRank(u,v,parent,rank);
           }
       }
       
       return cost;
        
        
    }
};