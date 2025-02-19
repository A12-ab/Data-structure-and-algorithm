class Solution {

    public:
        bool isSafe(vector<string>&board,int row,int j,int n){
            for(int i=0; i<n; i++){
                if(board[row][i]=='Q'){
                    return false;
                }
            }
            for(int i=0; i<n; i++){
                if(board[i][j]=='Q'){
                    return false;
                }
            }
            for(int i=row, k=j; i>=0 && k>=0; i--,k--){
                if(board[i][k]=='Q'){
                    return false;
                }
            }
            for(int i=row, k=j; i>=0 && k<n; i--,k++){
                if(board[i][k]=='Q'){
                    return false;
                }
            }
            return true;
            
        }
        void nQueens(vector<vector<string>>&ans, vector<string>&board,int n,int row){
            if(row==n){
                ans.push_back({board});
                return;
            }
            for(int j=0; j<n; j++){
                if(isSafe(board,row,j,n)){
                    board[row][j]='Q';
                    nQueens(ans,board,n,row+1);
                    board[row][j]='.';
                }
            }
    
        }
        vector<vector<string>> solveNQueens(int n) {
            vector<vector<string>>ans;
            vector<string>board(n,string(n,'.'));
            nQueens(ans,board,n,0);
            return ans;
    
        }
    };