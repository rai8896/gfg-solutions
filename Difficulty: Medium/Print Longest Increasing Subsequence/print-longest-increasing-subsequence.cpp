class Solution {
  public:
    vector<int> getLIS(vector<int>& arr) {
        // Code here
        int n=arr.size();
        vector<int>dp(n,1);
        vector<int>parent(n,-1);
         int maxLen = 1;
        int maxIndex = 0;

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                if(arr[i]>arr[j])
                {
                    // ddp[i]=max(dp[i],dp[j]+1);
                    if(dp[j]+1>dp[i])
                    {
                        dp[i]=dp[j]+1; 
                        parent[i]=j;
                    }
                }
            }
             if(dp[i] > maxLen)
            {
                maxLen = dp[i];
                maxIndex = i;
            }
        }
        
        
         vector<int>ans;
         while(maxIndex!=-1)
         {
             ans.push_back(arr[maxIndex]);
             maxIndex=parent[maxIndex];
             
         }
         reverse(ans.begin(),ans.end());
         return ans;
        
        
    }
};