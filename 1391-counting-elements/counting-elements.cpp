class Solution {
public:
    int countElements(vector<int>& arr) {
        map<int,int>mp;

        for(int i=0;i<arr.size();i++){
            mp[arr[i]]++;
        }

        int ans = 0;

        for(auto it:mp){
            if(mp.count(it.first+1)){
                cout<<it.first<<" "<<it.first+1<<endl;
                ans += mp[it.first];
            }
        }
        return ans;
    }
};