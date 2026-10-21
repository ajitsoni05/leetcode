class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        
        // Early check: if total count isn't divisible by k, partitioning is impossible
        if (nums.size() % k != 0) return false;
        
        // Use unordered_map for O(1) average lookups instead of O(log n) with ordered map
        unordered_map<int,int> freqMap;
        
        for(auto num: nums) {
            freqMap[num]++;
        }
        
        // Extract and sort unique keys to process from smallest to largest
        vector<int> keys;
        keys.reserve(freqMap.size());
        for(auto& p : freqMap) {
            keys.push_back(p.first);
        }
        sort(keys.begin(), keys.end());

        // Greedy: for each smallest remaining element, try to form a consecutive group of k
        for(int start : keys) {
            if(freqMap[start] == 0) continue; // already fully consumed

            int count = freqMap[start];
            
            // Attempt to build `count` groups starting from `start`
            for(int i = 0; i < k; i++) {
                if(freqMap[start + i] < count) return false; // not enough consecutive elements
                freqMap[start + i] -= count;
            }
        }

        return true;
    }
};