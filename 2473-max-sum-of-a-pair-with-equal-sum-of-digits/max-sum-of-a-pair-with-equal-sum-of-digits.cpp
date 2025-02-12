class Solution {
public:
    long long computeSum(long long num){
        long long sum=0;
        while(num!=0){
            sum+=(num%10);
            num/=10;
        }
        return sum;
    }
    int maximumSum(vector<int>& nums) {
        // compute sum of digits for each num in nums
        // map sum to equal num and append to the list
        // if list size is >=2 compute sum for larget 2 elements
        // max sum with curr

        long long curr =0;
        unordered_map<long long,priority_queue<long long>>mp;
        for(long long i=0;i<nums.size();i++){
            long long num=nums[i];
            long long sum = computeSum(num);
            mp[sum].push(num);
        }

        for(auto it:mp){
            priority_queue<long long>pq=it.second;
            long long sum=0;
            long long ctr=0;
            while(pq.size()!=0 && ctr!=2){
                sum+=pq.top();
                pq.pop();
                ctr++;
            }

            if(ctr==2)curr=max(curr,sum);
        }
        return curr==0?-1:curr;
    }
};