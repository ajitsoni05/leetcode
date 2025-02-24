class Solution {
public:
    vector<int> minOperations(string boxes) {
        /*
            n boxes
            string n
            boxes[i] - '0' empty
            boxes[i] - '1' filled
            
            "110"
            "1,1,3"
            difference of distance summed up together will yeild the answer
        */
        vector<int> ans;
        for(int i=0;i<boxes.size();i++){
            int dist=0;
            for(int j=0;j<boxes.size();j++){
                if(i==j)continue;
                if(boxes[j]=='1')dist+=abs(j-i);
            }
            ans.push_back(dist);
        }
    return ans;

    }
};