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
            currEmpty -= numExchange;
            numBottles++;
            
            total += numBottles;
            numExchange++;
            currEmpty+= numBottles;
            numBottles = 0;


        }

        return total;
    }
};