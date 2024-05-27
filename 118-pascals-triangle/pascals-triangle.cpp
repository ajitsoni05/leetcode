class Solution {
public:
    vector<vector<int>> generate(int numRows) {

        vector<vector<int>>ans;
        vector<int>prev(1,1);
        for(int i=1;i<=numRows;i++){
            vector<int>vec;
            vec.resize(i,1);
            for(int j=0;j<prev.size();j++){  
                if(j>=1)vec[j]=prev[j]+prev[j-1];
            }   
            ans.push_back(vec);
            prev=vec;
        }
        return ans;
    }
};