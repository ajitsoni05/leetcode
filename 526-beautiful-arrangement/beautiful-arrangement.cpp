class Solution {
public:
    int n;
    void recurse(unordered_map<int,vector<int>>&div, int num, int& count,unordered_map<int,int>&seen){
        if(num > n){
            count++;
            return;
        }

        for(auto divs: div[num]){
            if(seen.count(divs) == 0){
                seen[divs]++;
                recurse(div,num+1,count,seen);
                seen.erase(divs);
            }
        }

        
    }
    int countArrangement(int n) {
        
        /*
        
            number of beautiful arrangments 

            perm[i] % i == 0 or i % perm[i] == 0
         

            n = 3

            1 2 3

            1 2 3 4 5 6 7 8 9 10 11 12 13 14 15

            1 -> [1,2,3,4,5,6,7,8,9,10,11,12,13,14,15]
            2 -> [2,4,6,8,10,12,14]
            3 -> [3,9,12,15]
            4 -> [4,8,12]
            5 -> [5,10,15]
            6 -> [6,12]
            7 -> [7,14]
            8 -> 8
            9 -> 9
            10 -> 10
            11 -> 11
            12 -> 12
            13 -> 13
            14 -> 14
            15 -> 15


            1 -> 1
            2 -> [1,2]
            3 -> [1,3]
            4 -> [1,2,4]
            5 -> [1,5]
            6 -> [1,2,3,6]
            7 -> [1,7]
            8 -> [1,2,4,8]
            9 -> [1,3,9]
            10 -> [1,2,5,10]
            11 -> [1,11]
            12 -> [1,2,3,4,6,12]
            13 -> [1,13]
            14 -> [1,2,7,14]
            15 -> [1,3,5,15]
        */
        this->n = n;

        // map of complete divisors
        unordered_map<int,vector<int>>div;

        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++) {
                if(i%j == 0 || j%i == 0){
                    div[i].push_back(j);
                }
            }
        }

        int count = 0;
        unordered_map<int,int>seen;
        recurse(div,1,count,seen);
        return count;
    }
};