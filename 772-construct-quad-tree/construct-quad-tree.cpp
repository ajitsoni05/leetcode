/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/

class Solution {
public:
    int allSame(vector<vector<int>>&g,int h,int k, int n){


        int prev  = -1;
        for(int i = h; i < h+n; i++){
            for(int j = k; j < k+n; j++){
                if(prev == -1)prev = g[i][j];
                else if(prev != g[i][j])return -1;
                
            }
        }

        return prev;
        
    }
    Node* quadC(vector<vector<int>>& g,int x,int y,int n){
        
        Node* quad = new Node();

        int val = allSame(g,x,y,n);

        if(val != -1){
            quad->val = val ? 1 : 0;
            quad->isLeaf = true;
            return quad;
        }else{
            int new_n = n/2;

            if(new_n >= 1){
                // top-left
                int new_x = x;
                int new_y = y;
                quad->topLeft = quadC(g,new_x,new_y,new_n);

                //top-right
                new_x = x;
                new_y = y+n/2;
                quad->topRight = quadC(g,new_x,new_y,new_n);

                //bottom-left
                new_x = x+n/2;
                new_y = y;
                quad->bottomLeft = quadC(g,new_x,new_y,new_n);

                //bottom-right
                new_x = x+n/2;
                new_y = y+n/2;
                quad->bottomRight = quadC(g,new_x,new_y,new_n);

            }

        }

        return quad;
        
        
    }
    Node* construct(vector<vector<int>>& grid) {
        // check for the grid values
        
        // first check the length of the current Grid
        int n = grid.size();

        return quadC(grid,0,0,n);




    }
};