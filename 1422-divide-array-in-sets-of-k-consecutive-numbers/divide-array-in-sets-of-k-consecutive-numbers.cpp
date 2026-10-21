class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {

        int n = nums.size();
        if(n%k !=0 )return false;
        /*

            1 2 3 3 4 4 5 6 
            
            sort the array
        
        */

        // freqMap
        /*
        
            1 -> 1
            2 -> 1
            3 -> 2
            4 -> 2
            5 -> 1
            6 -> 1

            minm = *(freqMap.begin())->second

        */  
        
        map<int,int>freqMap;
        
        for(auto num: nums) {
            freqMap[num]++;
        }
        
        
        /*
            1 -> 1
            2 -> 1
            3 -> 2
            4 -> 2
            5 -> 1
            6 -> 1      
        */


        int counter = 0;

        while(freqMap.size()) {
            int ele = freqMap.begin()->first;

            while(counter < k){
                if(freqMap.count(ele) == 0)return false;
                else{
                    counter++;
                    if(--freqMap[ele] == 0)freqMap.erase(ele);
                    ele = ele + 1;
                }
            }
            counter = 0;
        }

        return true;

        
       
    }
};