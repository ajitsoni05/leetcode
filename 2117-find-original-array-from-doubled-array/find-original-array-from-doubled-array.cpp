class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        unordered_map<int,int>freq;

        for(auto it:changed){
            freq[it]++;
        }

        vector<int>ans;

        sort(changed.begin(),changed.end());

        for(int num:changed){
            if(freq[num]){
                freq[num]--;
                if(freq[2*num]>0){
                    freq[2*num]--;

                    ans.push_back(num);
                }else{
                    return {};
                }
            }
        }
        return ans;
    }
};