class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        vector<vector<int>>ans;

        unordered_map<int,vector<int>>mp;

        for(int i=0;i<groupSizes.size();i++){
            mp[groupSizes[i]].push_back(i);
        }

        for(auto it:mp){
            int gsize=it.first;
            vector<int>gp=it.second;

            while(gp.size()){
                vector<int>temp;

                temp.insert(temp.begin(),gp.end()-gsize,gp.end());
                while(gsize){
                    gp.pop_back();
                    gsize--;
                }
                gsize=it.first;
            ans.push_back(temp);

            }
        }
        return ans;

    }
};