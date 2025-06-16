class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int value) {
     /*
     
        x1, x2 , x3, x4

        max mex 
        
        minimum missing non-negative

        x1, x2, x3 , x4

        0, if 0 exists then 
        1 , if not then make something as 1?

        if nums[i] % val = x, then 
     */   

       vector<int> canBeMade;
       map<int,int>mp;

       for(auto num:nums){
        int x = ((num%value)+value)%value;
        cout<<x<<endl;
        mp[x]++;
       }
    
       int n = 0;
       int m = 0;
       while(mp.size()){
        if(mp.count(n)){
            mp[n]--;
            if(mp[n] == 0)mp.erase(n);
        }else{
            return m;
        }
        n = (n+1)%value;
        m++;

       }
       return m;
    }
};