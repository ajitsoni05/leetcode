class Solution {
public:
    static bool comp(pair<int,int> a,pair<int,int> b){
        if(a.second==b.second)return a<b;
        else return a.second<b.second;
    }
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        unordered_map<int,int>mp;
        for(int i=0;i<arr2.size();i++)mp[arr2[i]]=i;
        vector<pair<int,int>>ar1;

        for(int i=0;i<arr1.size();i++){
            if(mp.count(arr1[i])>0)
            ar1.push_back({arr1[i],mp[arr1[i]]});
            else 
            ar1.push_back({arr1[i],1001});
        }
        sort(ar1.begin(),ar1.end(),comp);

        for(int i=0;i<ar1.size();i++)arr1[i]=ar1[i].first;
        return arr1;
    }
};