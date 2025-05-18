class Solution {
public:
    int similarPairs(vector<string>& words) {
        // two ordered set should be same
        unordered_map<string,int>map;

        int pairs = 0;

        for(int i = 0;i <words.size();i++){
            set<char>s;

            for(int j = 0;j<words[i].size();j++){
                s.insert(words[i][j]);
            }

            string netString = "";
            
            for(auto ele:s){
                netString += ele+',';
            }

            cout<<netString<<endl;
            
            if(map.count(netString)){
                pairs += map[netString];
                map[netString]++;
            }else{
                map[netString]++;
            }
        }
        return pairs;
    }
};