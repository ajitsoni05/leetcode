class Solution {
public:
    string simplifyPath(string path) {
        /*
         path begins with /
         single period is dir
         dou
        
        
        */

        stringstream ss(path);
        char token = '/';
        string temp = "";
        string finalAns = "";
        stack<string>folders;

        while(getline(ss,temp,token)){
            if(temp==".")continue;
            else if(temp ==".."){
                if(folders.size())folders.pop();
            }else if(temp !=""){

                folders.push(temp);
            }
        
        }


        while(folders.size()){
            finalAns =  folders.top() + "/" + finalAns ;
            folders.pop();
        }
        return "/" + finalAns.substr(0,finalAns.size()-1);
    }
};