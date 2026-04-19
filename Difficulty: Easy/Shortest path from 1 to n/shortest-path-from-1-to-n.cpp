// User function Template for C++

class Solution {
  public:
    int minimumStep(int n) 
    {
        // complete the function here
  
    int steps = 0;

    while(n > 1) {
        if(n % 3 == 0) {
            n /= 3;
        } 
        else {
            n -= 1;
        }
        steps++;
    
    }

    return steps;
       
}
    
};