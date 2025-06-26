class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int left = 0;
        int right = 0;
        unordered_map<int,int>rightMostIndex;
        int n = fruits.size();

        int maxLen = 0;

        while(right < n){
            rightMostIndex[fruits[right]]++;

            while(rightMostIndex.size() > 2){
                rightMostIndex[fruits[left]]--;

                if(rightMostIndex[fruits[left]] == 0) rightMostIndex.erase(fruits[left]);
                left++;
            }

            maxLen = max(maxLen,right - left +1);
            right++;
        }

        return maxLen;
    }
};