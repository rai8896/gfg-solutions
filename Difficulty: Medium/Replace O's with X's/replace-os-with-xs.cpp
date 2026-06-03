class Solution {
  public:
   void dfs(int row,int col,vector<vector<char>>& grid)
   {
       int n= grid.size();
       int m= grid[0].size();
       grid[row][col]='B';
       
       int delrow[]={-1,0,+1,0};
       int delcol[]={0,1,0,-1};
       for(int i=0;i<4;i++)
       {
           int nrow=row+delrow[i];
           int ncol=col+delcol[i];
           
           
           if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && grid[nrow][ncol]=='O')
           {
               dfs(nrow,ncol,grid);
               
           }
       }
       
   }
    void fill(vector<vector<char>>& grid) {
        // Code here
        
        int n= grid.size();
        int m=grid[0].size();
        
        // first row and last row
        for(int j=0;j<m;j++)
        {
            if(grid[0][j]=='O')
            {
                dfs(0,j,grid);
                
            }
             if(grid[n-1][j]=='O')
             {
                 dfs(n-1,j,grid);
                 
             }
        }
        
        // first and last column
        for(int i=0;i<n;i++)
        {
            if(grid[i][0]=='O')
            {
                dfs(i,0,grid);
            }
             if(grid[i][m-1]=='O')
             {
                 dfs(i,m-1,grid);
             }
        }
        
        
        // Convert remaining O -> X
        // Convert B -> O
        
        
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]=='O')
                {
                    grid[i][j]='X';
                }
                else if(grid[i][j]=='B')       
                {
                    grid[i][j]='O';
                }
            }
            
        }
        
         return ;
        
    }
};