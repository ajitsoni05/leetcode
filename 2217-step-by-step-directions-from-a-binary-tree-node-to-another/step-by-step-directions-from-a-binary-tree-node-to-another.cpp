/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* findStartNode(TreeNode*root,int startValue){
        if(!root)return NULL;

        if(root->val == startValue)return root;

        TreeNode* leftSearch = findStartNode(root->left,startValue);
        TreeNode* rightSearch = findStartNode(root->right,startValue);

        if(leftSearch)return leftSearch;
        if(rightSearch)return rightSearch;

        return NULL;
    }
    void populateMap(unordered_map<TreeNode*, pair<TreeNode*, string>>& parentMap, TreeNode* root, TreeNode* parent, string dir) {
        if (!root) return;

        if (parent != NULL) {
            parentMap[root] = {parent, dir};
        }

        populateMap(parentMap, root->left, root, "L");
        populateMap(parentMap, root->right, root, "R");
    }

    string getDirections(TreeNode* root, int startValue, int destValue) {
        /*
        
            get directions

            we will traverse tree like graph

            we will have a parent array which will track parent of each node
            

            then start a bfs traversal from the startNode to the destValue

            when destValue is found the path will be constructed

            pathTracker map 


            intialize parentMap - to store parent nodes

            startNode using findStartNOde to recursively search the startValue

            populate parentMap 


            For BFS
            startNode into queue

            visitedNodes to keep track 

            pathTracker to record path


            while queue is not empty

            dque 
            
            if(cur == destVal )path found backtrackPath called and path returned

            if(parentMap contains parent of current node )

            if dest is never reached return empty   

        
        */



        

        TreeNode* startNode = findStartNode(root,startValue);

        unordered_map<TreeNode*,pair<TreeNode*,string>>parentMap; 
        
        populateMap(parentMap,root,NULL,"");

        
        queue<TreeNode*>q;

        
        q.push(startNode);

        
        set<TreeNode*>visitedSet;

        unordered_map<TreeNode*,pair<TreeNode*,string>>pathTracker; 

        
        while(!q.empty()){

            TreeNode* frontNode = q.front();
            visitedSet.insert(frontNode);
            
            auto Par = parentMap[frontNode];
            TreeNode*parent = Par.first;
            string dir = Par.second;

            q.pop();

            if(frontNode->val == destValue){
                return findPath(frontNode,startNode,pathTracker);
            }

            if(parent and !visitedSet.count(parent)){
                pathTracker[parent] = {frontNode,"U"};
                q.push(parent);
            }

            if(frontNode->left and !visitedSet.count(frontNode->left)){
                  pathTracker[frontNode->left] = {frontNode,"L"};
                  q.push(frontNode->left);
            }

            if(frontNode->right and !visitedSet.count(frontNode->right)){
                  pathTracker[frontNode->right] = {frontNode,"R"};
                  q.push(frontNode->right);
            }


        }

        return "";

        
    }
    string findPath(TreeNode*destNode, TreeNode*startNode,unordered_map<TreeNode*,pair<TreeNode*,string>>&pathTracker){
            if(!startNode || !destNode) return "";

            string ans = "";

            TreeNode* temp = destNode;
            while(temp != startNode and temp != NULL){
                ans += pathTracker[temp].second;
                temp = pathTracker[temp].first;
            }
            reverse(ans.begin(),ans.end());
            return ans;
        }
};