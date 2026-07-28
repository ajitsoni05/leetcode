class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        /*
        
        
            8   1   5   2   6
            0   1   2   3   4

            8 + 5 + 0 - 2
        
        */


        int result = 0;
        int current_max = values[0] - 1;
        int n = values.size();

        for(int i = 1; i < n; i++){
            result = max(result , current_max + values[i]);
            
            current_max = max(current_max - 1, values[i] - 1);
        }
      
      return result;

    }
};