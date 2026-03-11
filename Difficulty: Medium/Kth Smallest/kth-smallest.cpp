class Solution {
  public:
    int kthSmallest(vector<int> &arr, int k) {
        
        priority_queue<int,vector<int>, greater<int>>p;
        
        int n=arr.size();
        for(int i=0;i<n;i++)
        {
            p.push(arr[i]);
        }
        while(--k&&(!p.empty()))
        {
            p.pop();
        }
        if(p.size()==0)return 0;
       else  return p.top();
        
    }
};