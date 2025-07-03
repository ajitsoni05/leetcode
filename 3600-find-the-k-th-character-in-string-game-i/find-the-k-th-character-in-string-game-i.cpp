class Solution {
public:
    // Perform operations until s becomes longer than k
    void kOps(string& s, int k) {
        if (s.size() > k) return;
        string temp = s;
        int n = temp.size();
        for (int i = 0; i < n; i++) {
            temp += (char)((s[i] - 'a' + 1) % 26 + 'a'); 
        }
        s = temp; 
        cout<<s<<endl;
        kOps(s, k);
    }

    char kthCharacter(int k) {
        string ans = "a";
        kOps(ans, k);
        cout<<ans<<endl;
        return ans[k-1];
    }
};
