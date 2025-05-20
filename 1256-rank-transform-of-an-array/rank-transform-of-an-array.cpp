class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        map<int,vector<int>>rank;
        vector<int>rankArray(arr.size());
        for(int i = 0;i<arr.size();i++){
            rank[arr[i]].push_back(i);
        }
        
        int rnk = 1;
        for(auto it = rank.begin(); it != rank.end();it++,rnk++){
            for(auto ele:it->second){
                rankArray[ele] = rnk;
            }
        }
        return rankArray;
    }
};