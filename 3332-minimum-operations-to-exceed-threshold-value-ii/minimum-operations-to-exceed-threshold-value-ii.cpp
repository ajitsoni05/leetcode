class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        // 0 indexed array , integer l
        // 1 op -x, y smallest remove them
        // k 
        priority_queue<long long ,vector<long long >,greater<long long >>pq;

        long long  ctr=0;
        for(long long  i=0;i<nums.size();i++)pq.push(nums[i]);

        while(pq.size()>=2){
            
            long long  a = pq.top();
            pq.pop();
            long long  b = pq.top();
            pq.pop();


            if(a>b)swap(a,b);
            if(a>=k)return ctr;
            long long  num = a*2 +b;

            // new num 
            // pq.top()
            // pq.size()

            if(pq.size()){
                if(pq.top()>=k){
                    if(num>=k){
                        return ctr+1;
                    }else{
                        ctr++;
                    }
                }else{
                    ctr++;
                }

            }else{
                if(num>=k) return ctr+1;
                else ctr++;
            }
            pq.push(num);

        }
        return ctr;
    }
};