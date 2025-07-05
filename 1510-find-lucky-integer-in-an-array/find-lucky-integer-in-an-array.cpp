class Solution {
public:
    int findLucky(vector<int>& arr) {
        unordered_map<int,int>freqMap;


        int n = arr.size();

        for(int i = 0; i < n; i++){
            freqMap[arr[i]]++;
        }


        int maxCandidate = -1;

        for(const auto& [element,frequency]: freqMap){
            if(element == frequency) maxCandidate = max(maxCandidate,element);
        }

        return maxCandidate;
    }
};