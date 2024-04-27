class Solution {
public:
    int maximumPopulation(vector<vector<int>>& logs) {
        // make a line using map 
        // when a birth happens , map++ and death map--
        // traverse the line get max population , year

        map<int,int>line;

        for(auto i:logs){
            line[i[0]]++;
            line[i[1]]--;
        }

        // intialize max pop year
        int mpy=-1;

        int max_p=0;

        int cnt_p=0;
        

        // traverse the line
        for(auto i:line){
            cnt_p+=i.second;
            if(cnt_p>max_p){
                cnt_p=max_p;
                mpy=i.first;
            }

        }
        return mpy;
    }
};