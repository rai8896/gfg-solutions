class Solution {
  public:
    int largest(vector<int> &arr) {
        // code here
        
        priority_queue<int>p;
        for(int i=0;i<arr.size();i++)
        {
            p.push(arr[i]);
        }
        return p.top();
    }
};
