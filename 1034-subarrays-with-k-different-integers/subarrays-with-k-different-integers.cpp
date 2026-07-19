class Solution {
public:
    int getCount(vector<int>&nums, int k){

        int l_ptr = 0, r_ptr = 0;
        int total_count = 0;
        int n = nums.size();

        unordered_map<int,int>numFreq;

        while(r_ptr < n){
            
            // push element pointed by r_ptr 
            numFreq[nums[r_ptr]]++;


            // check if numFreq size < k
            
            if(numFreq.size() <= k){

                // increment total count 
                total_count += r_ptr - l_ptr + 1;
                // increment r_ptr
            }else{
                // shrink the window until numFreq size reduces to k
                while(numFreq.size() > k){

                    // get num at l_ptr;
                    int num = nums[l_ptr];

                    // decrement/remove it from numFreq;
                    numFreq[num]--;


                    if(numFreq[num] == 0) numFreq.erase(num);

                    // increment l_ptr;
                    l_ptr++;
                }
                // after complete shrink add valid subarrays
                total_count += r_ptr - l_ptr + 1;

            }
            r_ptr++;

        }
        return total_count;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        

        unordered_map<int,int>numFreq;
        int count1 =  getCount(nums,k);
        int count2 = getCount(nums,k-1);
        

        return count1 - count2;
       
    }
};