class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int>pq;
        int ans=0;
        for(int i=0;i<stones.size();i++){
            pq.push(stones[i]);
        }
        if(pq.size()==1)return pq.top();
        else{
            
            while(pq.size()>1){
            int top=pq.top();
            pq.pop();
            int next=pq.top();
            pq.pop();
            if(top==next)ans=0;
            else ans=top-next;
            pq.push(ans);
            }
            if(pq.size()==1)return pq.top();
        }
        return ans;
    }
};