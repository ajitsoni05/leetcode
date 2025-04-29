class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int n= nums.size();
        int diff=INT_MAX;
        int sum =INT_MIN;

        for(int i=0;i<nums.size();i++){
            int lo = i+1;
            int hi = n-1;

            while(lo<hi){
                int currSum = nums[i]+nums[lo]+nums[hi];
                int currDiff = abs(target-currSum);
                if(currDiff < diff){
                cout<<currDiff<<" "<<diff<<" "<<currSum<<" "<<sum<<endl;

                    diff = currDiff;
                    sum = currSum;
                }

                if(currSum>target){
                    hi--;
                }else if(currSum<target){
                    lo++;
                }else{
                    return currSum;
                }
            }
            
        }
        return sum==INT_MIN?-1:sum;
    }
};