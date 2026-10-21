class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        /*
            first optimization
            early exit
            check if nums.size is divisible by k
        */
        if(nums.size() % k != 0) return false;

        // store the elements in a freqMap
        unordered_map<int,int>freqMap;

        for(auto num: nums){
            freqMap[num]++;
        }

        // collect keys for starting batch processing in a vector
        vector<int>keys;

        for(auto [k,v]:freqMap) {
            keys.push_back(k);
        }

        // sort the keys
        sort(keys.begin(),keys.end());

        // do the batch-processing
       for(auto start:keys){
        // check if already consumed | check frequency in the map
        if(freqMap[start] == 0) continue;
        int count = freqMap[start];

        for(int i = 0; i < k; i++){
            if(freqMap[start+i] < count) return false;
            else freqMap[start+i] -= count;
        }

       }

       return true;
    }
};