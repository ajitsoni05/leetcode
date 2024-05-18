class Solution {
public:
    vector<vector<int>>b;
    int r,c;
    bool isValid(int i,int j){
        if(i>=0&&i<r&&j>=0&&j<c)return true;
        return false;
    }
    int count(int i,int j){
        int c=0;
        for(int h=-1;h<=1;h++){
            for(int k=-1;k<=1;k++){
                if(h==0&&k==0)continue;
                else if(isValid(i+h,j+k)&&b[i+h][j+k]==1)c++;
            }
        }
        return c;
    }
    void gameOfLife(vector<vector<int>>& board) {
        b=board;
        r=board.size();
        c=board[0].size();
        
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                int co=count(i,j);
                if(board[i][j]==1){
                    if(co<2||co>3)board[i][j]=0;
                }else{
                    if(co==3)board[i][j]=1;
                    
                }
            }
        }
    }
};