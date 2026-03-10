class Solution {
  public:
    int heapHeight(int n, int arr[]) {
        // code here
        
        if(n==1) return 1;
        int h=0;
        
        while(n>1)
        {
            h++;
            n=n/2;
        }
        return h;
    }
};