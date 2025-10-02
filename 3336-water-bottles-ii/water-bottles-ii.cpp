class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
        /*

            - drink any number of full -> empty
            - exchange numEx with 1 full and numEx++

            max num bottles we can drink

            13 
      
        
        
        */

        int currEmpty = numBottles;
        
        numBottles = 0;

        int total = currEmpty;

        while( numExchange <= currEmpty ){
            // deduct numExchange from currentEmpty
            currEmpty -= numExchange;
            
            // increase numBottles by 1
            numBottles++;

            // total drank increments by numBottles
            total += numBottles;

            // numExchange increments by 1 upon conversion
            numExchange++;

            // currEmpty increase by numBottles since they are empty now
            currEmpty+= numBottles;

            // set numBottles to 0
            numBottles = 0;


        }

        return total;
    }
};