class Solution {
public:
    vector<int> findXSum(vector<int>& nums, int k, int x) {
        /*

            n nums

            k   and    x

            occurence map of x most frequent

            if freqA == freqB and A > B A is more freq

            sum of resulting array

            if array has less than x distinct then x-sum is sum of the array

            n - k + 1 -> ans[i] = (i..i+k-1)


        */
        vector<int>ans;
        int n = nums.size();

       for(int i = 0; i <= n-k; i++){

        int tempX = x;
        // ans[i] = xsum of i -> i + k-1
        vector<int>smallArray;

        smallArray.assign(nums.begin()+i,nums.begin()+i+k);

        // find x-sum for smallArray

        unordered_map<int,int>occMp;

        for(int i = 0; i < smallArray.size(); i++){
            occMp[smallArray[i]]++;
        }

        //array sum
        int sum = accumulate(smallArray.begin(),smallArray.end(),0);
        
        if(occMp.size() < x){
            ans.push_back(sum);
            continue;
        }

        map<int,set<int,greater<int>>,greater<int>>setMap;


        for(auto it:occMp){
            setMap[it.second].insert(it.first);
        }

        sum = 0;
        
        for(auto setArray:setMap){
            int occ = setArray.first;
            for(auto setEle:setArray.second){
                
                sum+=(setEle*occ);
               
                tempX--;

                if(tempX==0)break;
            }
            if(tempX==0)break;
        }
        ans.push_back(sum);
          
       }
       return ans;
    }
};