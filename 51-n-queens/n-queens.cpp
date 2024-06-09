class Solution {
public:
    bool isSafe(vector<string>&board,int row,int col,int n){
        int cr=row;
        int cl=col;

        while(cr>=0 and cl>=0){
            if(board[cr][cl]=='Q')return false;
             cr--,cl--;
         
           
        }
        
        cr=row;
        cl=col;
        while(cl>=0){
            if(board[cr][cl]=='Q'){
                return false;
            }
             cl--;
            
           
        }
    
        cr=row;
        cl=col;
        while(cr<n and cl>=0){
             if(board[cr][cl]=='Q')return false;
            cl--,cr++;
           
            
        }   

        return true;
    }
    void placeQueens(vector<string>&board,vector<vector<string>>&ans,int col,int n){
        if(col==n){
            ans.push_back(board);
            return ;
        }
        for(int i=0;i<n;i++){
            if(isSafe(board,i,col,n)){
                board[i][col]='Q';
                placeQueens(board,ans,col+1,n);
                board[i][col]='.';
            }else continue;
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>>ans;
        vector<string> board(n, string(n, '.'));
      
        placeQueens(board,ans,0,n);
        return ans;
    }
};