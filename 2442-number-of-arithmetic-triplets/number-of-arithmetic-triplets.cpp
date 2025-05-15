class Solution {
public:
    int arithmeticTriplets(vector<int>& nums, int diff) {
        
        // nums[j] = nums[i] + diff;
        // nums[k] = nums[i] + 2*diff;

        // set for storing uniqueTriplets
        
        int count = 0;
        // hashMap for storing the avail of nums j and nums k
        unordered_map<int,int>indexMap;

        int start = 0;
        int end = nums.size();

        for(int i = start; i < end; i++){
            int ele = nums[i];

            indexMap[ele]=i;

        }

        // traverse thru the array once more and start collecting the triplets
        
        for(int i = start; i<end ;i++){
            int numJ = nums[i] + diff;
            int numK = nums[i] + 2*diff;

            if(indexMap.count(numJ) and indexMap.count(numK)){
                count++;
            }
        }

        return count;
    }
};