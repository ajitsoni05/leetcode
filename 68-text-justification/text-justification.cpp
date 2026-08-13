class Solution {
public:
   void addSpace(string& line, int& totalSpaces, int& numWords, bool& isTerminal) {

    if (numWords == 1) {
        for (int i = 0; i < totalSpaces; i++) {
            line += " ";
        }
        totalSpaces = 0;
        return;
    }

    // Last line: only one space between words
    if (isTerminal) {
        line += " ";
        totalSpaces--;
        numWords--;
        return;
    }

    // Normal justified line
    int count = totalSpaces / (numWords - 1);
    int extra = totalSpaces % (numWords - 1);

    for (int i = 0; i < count + (extra > 0); i++) {
        line += " ";
    }

    totalSpaces -= count + (extra > 0);
    numWords--;
}
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        // Pad extra spaces
        /*

            each word comes with a space

            maxWidth < length of each word + (total number of words considered - 1)*(spaces)

            pick words until the above condition is true then if w

        */

        vector<string> lines;
        int n = words.size();
        int baseIter = 0;


        while(baseIter < n){

        
        string line = "";

        int wordIter = baseIter;

        int wordLen = words[wordIter].size();
    
        int spaceLen = 0;

        while (wordIter < n && wordLen + spaceLen < maxWidth) {
            
            spaceLen++;

            if(wordLen + spaceLen >= maxWidth){
                spaceLen--; // remove last space
                break;
            }
            if(wordIter == n - 1)break;
            wordLen += words[++wordIter].size();
            
        }

        // remove last word if exceeded
        if(wordLen + spaceLen > maxWidth){
            wordLen -= words[wordIter].size();
            wordIter--;
        }

        int numWords = (wordIter - baseIter) + 1;

        // get max space
        int totalSpaces = maxWidth -  (wordLen);    
        cout<<wordLen<<endl;
        // is maxSpace % numWords == 0
        cout<<totalSpaces<<endl;



        // create line  add word then space

        for(int i = baseIter; i <= wordIter; i++){
            line = line + words[i];
            // send info regarding wordIter being equal to n - 1
            bool isTerminal = wordIter == n - 1;
            addSpace(line,totalSpaces,numWords,isTerminal);
        }


        lines.push_back(line);
        baseIter = wordIter + 1;

        }


        return lines;
        



        
    }
};