class Solution {
public:
    int maxStudentsOnBench(vector<vector<int>>& students) {
        unordered_map<int,set<int>>bench;

        for(int i=0;i<students.size();i++){
            int sId= students[i][0];
            int bId = students[i][1];

            bench[bId].insert(sId);
            
        }

        int maxm=0;
        for(auto it:bench){
            maxm=max(maxm,int(it.second.size()));
        }
        return maxm;
    }
};