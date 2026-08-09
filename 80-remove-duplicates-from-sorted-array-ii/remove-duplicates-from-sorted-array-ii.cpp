class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        // read once write at most twice

        /*
        
              r
            1 1 1 2 2 3
              w

            counter = 1

        */
        int reader_ptr = 1;
        int writer_ptr = 0;
        int counter = 1;
        int n = nums.size();

        while(reader_ptr < n) {
            if(nums[reader_ptr] == nums[writer_ptr]){
                counter++;
                if(counter <= 2){
                    nums[++writer_ptr] = nums[reader_ptr];
                    reader_ptr++;
                }else{
                    reader_ptr++;
                }
                
            }else{
                counter = 1;
                nums[++writer_ptr] = nums[reader_ptr];
                reader_ptr++;
            }
        }
        return writer_ptr+1;
    }
};