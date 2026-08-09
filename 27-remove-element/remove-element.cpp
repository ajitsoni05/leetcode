class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        // consider two pointers - reader_ptr and writer_ptr
        /*
            reader_ptr reads for val
            and writer_ptr writes if not val
        
        */

        int reader_ptr = 0, writer_ptr = 0;
        int n = nums.size();

        // while(reader_ptr < n){
        //     if(nums[reader_ptr] == val)reader_ptr++;
        //     else nums[writer_ptr++] = nums[reader_ptr++];
        // }

        // we can use for-loop

        for(int reader_ptr = 0; reader_ptr < n; reader_ptr++){
            if(nums[reader_ptr] != val){
                nums[writer_ptr++] = nums[reader_ptr];
            }
        }
        return writer_ptr;
    }
};