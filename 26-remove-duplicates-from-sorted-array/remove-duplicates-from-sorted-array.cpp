class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        // same reader and writer
        
        /*
            since it is given non-decreasing order which esentially means
            next elements are either duplicates or greater than current

            consider reader_ptr and writer_ptr 
            if writer_ptr->val == reader_ptr->val
            simply move reader_ptr 
            else write nums[writer_ptr+1] = nums[reader_ptr]
        */

        int n = nums.size();
        int writer_ptr = 0;
        

        for(int reader_ptr = 0; reader_ptr < n; reader_ptr++) {

            if(nums[writer_ptr] == nums[reader_ptr]){
                // do nothing
            }else{
                nums[writer_ptr+1] = nums[reader_ptr];
                writer_ptr++;
            }
        }
        cout<<writer_ptr<<endl;
        return writer_ptr+1;



    }
};