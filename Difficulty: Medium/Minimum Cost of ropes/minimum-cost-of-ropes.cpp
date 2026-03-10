class Solution {
  public:
    int minCost(vector<int>& arr) {
        // code here
        
        // priority_queue<int int,vector<int int>,greater<int>>p;
        priority_queue<int, vector<int>, greater<int>> p;
        int n=arr.size();
        for(int i=0;i<n;i++)
        {
            p.push(arr[i]);
        }
        
        int cost=0;
         while(p.size()>1)
         {
           int firstmin=p.top();
           p.pop();
           int secondmin=p.top();
           p.pop();
           int t=firstmin+secondmin;
           cost=cost+t;
           p.push(t);
         }
         return cost;
    }
};