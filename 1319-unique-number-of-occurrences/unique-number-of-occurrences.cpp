class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int>mp;
        unordered_map<int,int>oc;

        for(int i=0;i<arr.size();i++){
            mp[arr[i]]++;
        }

      


        for(auto it:mp){
           if(oc.count(it.second)>0)return false;
           else {
            oc[it.second]=1;
           }
            
        }
       
        return true;
    }
};