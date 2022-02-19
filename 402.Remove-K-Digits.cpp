class Solution {
public:
    string removeKdigits(string num, int k) {
        string ans;
        for(char c : num) {
            while(ans.length() && ans[ans.length() - 1] > c && k-- > 0) ans.pop_back();
            if(ans.length() || c != '0') ans.push_back(c);
        }
        while(ans.length() && k-- > 0) ans.pop_back();
        if(!ans.length()) ans = '0';
        return ans;
    }
};