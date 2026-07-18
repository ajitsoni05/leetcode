class Solution {
public:
    int findLUSlength(string a, string b) {
        
        /*
        
         abc
         def

         abc


         abc

         abc


        
        */
        if(a != b)return a.size() > b.size() ? a.size() : b.size();
        return -1;
    }
};