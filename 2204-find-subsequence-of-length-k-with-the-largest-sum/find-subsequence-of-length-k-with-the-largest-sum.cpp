class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        // find top k elements
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;


        int n = nums.size();

        for(int i = 0; i < n; i++){
            if(pq.size() < k){
                pq.push({nums[i],i});
            }else{

                if(pq.top().first < nums[i]){
                    pq.pop();
                    pq.push({nums[i],i});
                }
                
            }

        }

    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq2;

    while(!pq.empty()){
        pair<int,int> p = pq.top();
        pq.pop();
        pq2.push({p.second,p.first});
    }


    vector<int>ans;

    while(!pq2.empty()){
        ans.push_back(pq2.top().second);
        pq2.pop();
    }

    return ans;

    }
};