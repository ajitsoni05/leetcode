class Solution {
public:
    int candy(vector<int>& ratings) {
        
        int totsum=0;

        vector<int>candies(ratings.size(),1);

        int n=ratings.size();
        //left pass
        for(int i=1;i<n;i++){
            if(ratings[i]>ratings[i-1])candies[i]=candies[i-1]+1;
        }
        totsum=candies[n-1];
        //right pass
        for(int i=n-2;i>=0;i--){
            if(ratings[i]>ratings[i+1])candies[i]=max(candies[i],candies[i+1]+1);
            totsum+=candies[i];
        }
        return totsum;
    }
};