class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        

        /*
        
        i 
        2 2 3 3
          j
        
        */

        int n = nums.size();

        int back_ptr = n - 1;
        int front_ptr = 0;
        int count = 0;
        
        // double pass first modify 
        while(front_ptr < back_ptr){
            while(back_ptr > 0 and nums[back_ptr] == val)back_ptr--;

            if(front_ptr < back_ptr and nums[front_ptr] == val){
                swap(nums[front_ptr],nums[back_ptr]);
                front_ptr++;
                back_ptr--;
            }else{
                front_ptr++;
            }
        }

        for(int i = 0; i < nums.size(); i++){
           if(nums[i] == val) count++;
        }

        
        // then count
       return n - count;
    }
};