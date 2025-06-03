class Solution {
public:
    bool validateBinaryTreeNodes(int n, vector<int>& l, vector<int>& r) {
        /*
            Rules to validate a binary tree
            - A binary tree must have a root | a node with no incoming edges | and it has no parent
            - every node other than root have exactly 1 parent
            - tree must be connected | every node must be reachable from one node(the root)
            - there cannot be a cycle
            - 

            Algo

            find the root

            start dfs upon finding the root

            if we see a node multiple times during dfs it means it has multiple parents
            and a cycle exists

            set seen to check if we have seen some node multiple time

            length of seen == n (to check if there are disconnected components)


            So basically 3 things

            - find a root , it should not occur in left and right child
            - start dfs from root using set 
            - and once dfs ends check if set size is equal to node size
          bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        
        */

        // lets find the root
        int root = findRoot(n, l, r);

        if(root == -1)return false;
        
        // once root is found let's start with dfs
        set<int>seen;
        bool hasCycle = false;
        dfs(n,l,r,seen,root,hasCycle);

        if(seen.size()!=n || hasCycle)return false;
        return true;
        
    }

    void dfs(int n,vector<int>&l,vector<int>&r,set<int>&seen,int start,bool&hasCycle){
        seen.insert(start);

        // check if left child exists
        if(l[start]!=-1){
            if(seen.count(l[start])){
                hasCycle = true;
                return;
            }else{
                dfs(n,l,r,seen,l[start],hasCycle);
            }
        }

        if(r[start]!=-1){
            if(seen.count(r[start])){
                hasCycle = true;
                return;
            }else{
                dfs(n,l,r,seen,r[start],hasCycle);
            }
        }

    }
    int findRoot(int n, vector<int>&l,vector<int>&r){
        // insert children into 
        unordered_set<int>ch;
        ch.insert(l.begin(),l.end());
        ch.insert(r.begin(),r.end());

        for(int i = 0; i < n; i++){
            if(ch.find(i)==ch.end())return i;
        }
        return -1;
    }
};