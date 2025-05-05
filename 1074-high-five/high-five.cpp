class Solution {
public:
    vector<vector<int>> highFive(vector<vector<int>>& items) {
        /*
            items - id and score

            result - id and top5 aveg
        */
        unordered_map<int,priority_queue<int,vector<int>,greater<int>>>ids;

        for(auto scores : items){
            int id = scores[0];
            int score = scores[1];

            if(ids.count(id)){
                if(ids[id].size()<5){
                    ids[id].push(score);
                }else{
                    int temp = ids[id].top();
                    if(score>temp){
                        ids[id].pop();
                        ids[id].push(score);
                    }
                }
            }else{
                ids[id].push(score);
            }
        }
        vector<vector<int>>ans;

        for(auto it:ids){
            int count = 0;
            int sum = 0;
            while(it.second.size()){
                sum += it.second.top();
                it.second.pop();
                count++;
            }
            int avg = sum / count;

            ans.push_back({it.first,avg});
        } 
        sort(ans.begin(),ans.end());
        return ans;
    }
};