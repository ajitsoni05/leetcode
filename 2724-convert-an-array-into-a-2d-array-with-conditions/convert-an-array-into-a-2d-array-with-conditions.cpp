class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        vector<vector<int>>ans;

        unordered_map<int,int>mp;

        for(int i=0;i<nums.size();i++)mp[nums[i]]++;

        while(mp.size()){
            vector<int>temp;
            for(auto it=mp.begin();it!=mp.end();){
                if(it->second==1){
                    temp.push_back(it->first);
                    it=mp.erase(it);
                }else{
                    temp.push_back(it->first);
                    it->second--;
                    it++;
                }
            }
            ans.push_back(temp);
        }

        return ans;

    }
};