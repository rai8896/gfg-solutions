class Solution {
	public:
	vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
		
		// Code here
		// adjancy list bna rha hoon
		vector<vector<pair<int, int>> > adj(V);
		
		for (auto x:edges)
			{
			int u = x[0];
			int v = x[1];
			int w = x[2];
			
			adj[u].push_back({v, w});
			adj[v].push_back({u, w}); // agar graph undirected hai
		}
		
		vector<bool>explored(V, 0);
		vector<int>dist(V, INT_MAX);
		
		dist[src] = 0;
		
	
		
		priority_queue<	pair<int,int> ,vector<	pair<int,int>>,greater<	pair<int,int>>>p;
		p.push({0,src});
		
		
		while(!p.empty())
		{
		    int node=p.top().second;
		    p.pop();
		    if(explored[node]==1) continue;
		    
		    explored[node]=1;
		    
		
	
			explored[node] = 1;
			
			// relax the edges
			for (int j = 0; j<adj[node].size(); j++)
				{
				int neighbour = adj[node][j].first;
				int weight = adj[node][j].second;
				
				if (!explored[neighbour] && dist[node]+weight <dist[neighbour])
					{
					dist[neighbour] = dist[node]+weight;
					p.push({dist[neighbour],neighbour});
				}
			}
		}
		return dist;
		
	}
};
