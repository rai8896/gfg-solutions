class Solution {
  public:
    vector<int> rangeSumQueries(vector<int>& arr, vector<vector<int>>& queries) {
        // code here
        
        int n= arr.size();
        vector<int>prefix(n);
        prefix[0]=arr[0];
        for(int i=1;i<n;i++)
        {
            prefix[i]=prefix[i-1]+arr[i];
        }
        
        vector<int> ans;
        
        for(auto &q:queries)
        {
            int l=q[0];
            int r=q[1];
            if(l==0)
            {
                ans.push_back(prefix[r]);
            }else
            {
                ans.push_back(prefix[r]-prefix[l-1]);
            }
         }
          return ans;
    }
};