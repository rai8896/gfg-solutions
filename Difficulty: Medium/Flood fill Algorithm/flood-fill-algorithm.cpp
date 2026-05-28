class Solution {
  public:
  
    void dfs(int row,int col,vector<vector<int>>&ans,vector<vector<int>>&image,int newColor,int initColor,int delrow[],int delcol[])
    {
        ans[row][col]=newColor;
        int n=image.size();
        int m=image[0].size();
        for(int i=0;i<4;i++)
        {
            int nrow=row+delrow[i];
            int ncol=col+delcol[i];
            if(nrow>=0 && nrow<n && ncol>=0 &&ncol<m && image[nrow][ncol]==initColor && ans[nrow][ncol]!=newColor)
            {
                dfs(nrow,ncol,ans,image,newColor,initColor,delrow,delcol);
            }
        }
    }
    
    
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc,
                                  int newColor) {
        // code here
        int initColor=image[sr][sc];
        vector<vector<int>>ans=image;
        int delrow[]={-1,0,+1,0};
        int delcol[]={0,+1,0,-1};
        
        dfs(sr,sc,ans,image,newColor,initColor,delrow,delcol);
        return ans;
        
        
        
    }
};