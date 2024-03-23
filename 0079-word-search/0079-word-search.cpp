class Solution {
public:

    void traverse(vector<vector<char>>&board,string word,int i,int j,bool& exists){
        // mark i and j as visited
        char c=board[i][j];
        board[i][j]='#';
        if(word==""){
            exists=true;
            return;
        }
        for(int h=-1;h<=1;h++){
            for(int k=-1;k<=1;k++){
                if((abs(h)!=abs(k))&&(i+h>=0&&i+h<board.size())&&(j+k>=0&&j+k<board[0].size())&&board[i+h][j+k]!='#'&&board[i+h][j+k]==word[0])
                {
                    traverse(board,word.substr(1),i+h,j+k,exists);
                }
            }
        }
        board[i][j]=c;
    }
    bool exist(vector<vector<char>>& board, string word) {
        bool exists=false;

        if(word=="")return true;


        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(board[i][j]==word[0]){
                    traverse(board,word.substr(1),i,j,exists);
                    if(exists)return true;
                }
            }
        }
        return exists;
    }
};