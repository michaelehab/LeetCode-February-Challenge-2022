class Solution {
public:
    char findTheDifference(string s, string t) {
        unordered_map <char, int> cnt(t.size());
        for(char c : t) cnt[c]++;
        for(char c : s) cnt[c]--;
        char ans;
        for(auto itr = cnt.begin(); itr != cnt.end(); itr++){
            if(itr->second != 0) ans = itr->first;
        }
        return ans;
    }
};