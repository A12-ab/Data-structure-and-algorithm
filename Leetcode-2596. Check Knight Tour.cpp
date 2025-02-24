class Solution {
    public:
        bool isValid(vector<vector<int>>& grid, int r, int c,int n, int expVal){
            if(r<0 || c<0 || r>=n || c>=n || grid[r][c] != expVal){
                return false;
            }
            if(expVal == n*n-1){
                return true;
            }
            // 8 possible moves
    
            int a1=isValid(grid,r-2,c+1,n,expVal+1);
            int a2=isValid(grid,r-1,c+2,n,expVal+1);
            int a3=isValid(grid,r+1,c+2,n,expVal+1);
            int a4=isValid(grid,r+2,c+1,n,expVal+1);
            int a5=isValid(grid,r+2,c-1,n,expVal+1);
            int a6=isValid(grid,r+1,c-2,n,expVal+1);
            int a7=isValid(grid,r-1,c-2,n,expVal+1);
            int a8=isValid(grid,r-2,c-1,n,expVal+1);
    
            return a1 || a2 || a3 || a4 || a5 || a6 || a7 || a8;
        }
        bool checkValidGrid(vector<vector<int>>& grid) {
            return isValid(grid,0,0,grid.size(),0);
            
        }
    };