class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        
        vector<int>duplicates;

        for(int i = 0; i < nums.size(); i++){

            int num = abs(nums[i]);
            
            if(num > 0 and nums[num-1] < 0){

                duplicates.push_back(num);
                
      
            
            } else {

                nums[num-1] = -1 *  nums[num-1] ;
            }
            
        }

        for(auto num:nums){
            cout<<num<<" ";
        }
        /*
        
        [9,9,-4,-10,8,-5,2,-2,-7,-7]
         0 1 2 3 4 5 6 7 8 9    
         9 
        
        */
        return duplicates;
    }
};