class Solution {
public:
    string largestWordCount(vector<string>& messages, vector<string>& senders) {
        // n messages
        // messages and senders

        // mi <- si

        // sender with largest word count

        unordered_map<string,int>wordCountMap;

        int senderIdx = 0;
        for(auto message:messages){
            
            stringstream s(message);

            string temp = "";

            int wordCount = 0;
            while(s>>temp)wordCount++;

            wordCountMap[senders[senderIdx++]]+=wordCount;
        }


        // reverseMap
        map<int,set<string,greater<string>>,greater<int>>TopSenderMap;
        
        for(auto element:wordCountMap){
            string sender = element.first;
            int count = element.second;

            TopSenderMap[count].insert(sender);
        }

        auto senderSet = TopSenderMap.begin()->second;

        auto topSender = *(senderSet.begin());

        return topSender;


    }
};