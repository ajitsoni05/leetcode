class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        /*
        
            counting sort

            freq array to store the number

            iterate 0 to max

            for each num -> 2*num (once)

            Algo:
                if size of chaanged is odd: return {}

                maxEle = max(changed)

                freq[2*maxNum+1] = {...0}

                from 0 to maxNum

                    for each num:
                        check if count(num) in freq > 0 
                            count(num)--
                            
                            check if count(2*num) > 0
                                count(2*num)--

                                add num to ans
                                 
                            num--

        */

        if(changed.size()%2) return {};


        // maxNum
        int maxNum = -1;

        vector<int>ans;

        for(auto num:changed){
            maxNum = max(maxNum,num);
        }
        vector<int>freq(2*maxNum+1,0);
        
        for(auto num:changed){
          freq[num]++;
        }

        for(int i = 0; i <= maxNum; i++){

            if(freq[i]){
                freq[i]--;

                if(freq[2*i]){
                    freq[2*i]--;
                    ans.push_back(i);
                }else{
                    return {};
                }
                i--;
            }
        }

        return ans;


    }
};