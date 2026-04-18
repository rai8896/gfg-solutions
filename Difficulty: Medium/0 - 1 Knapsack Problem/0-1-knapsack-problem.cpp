class Solution {
  public:
  
  int dp[1001][1001];
  
  int knap(vector<int>& wt, vector<int>& val, int w, int n)
  {
      if(n == 0 || w == 0)
          return 0;

      if(dp[n][w] != -1)
          return dp[n][w];

      if(wt[n-1] <= w)
      {
          return dp[n][w] = max(
              val[n-1] + knap(wt, val, w - wt[n-1], n-1),
              knap(wt, val, w, n-1)
          );
      }
      else
      {
          return dp[n][w] = knap(wt, val, w, n-1);
      }
  }
  
  int knapsack(int W, vector<int> &val, vector<int> &wt) {
      int n = val.size();
      
      memset(dp, -1, sizeof(dp));  
      
      return knap(wt, val, W, n);
  }
};