class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector <int> ans;
        unordered_map <char, int> pcnt;
        int n = s.size();
        int left = 0, right = 0;
        int counter = p.size();
        for(int i = 0; i < p.size(); i++) pcnt[p[i]]++;
        for(int right = 0; right < n; right++){
            if(pcnt.find(s[right]) != pcnt.end() && pcnt[s[right]]){
                pcnt[s[right]]--;
                counter--;
                if(counter == 0) ans.push_back(left);
            } 
            else {
                while(left < right){
                    if(pcnt.find(s[left]) != pcnt.end()) {
                        counter++;
                        pcnt[s[left]]++;
                    }
                    left++;
                    if(pcnt.find(s[right]) != pcnt.end() && pcnt[s[right]]){
                        right--;
                        break;
                    }
                }
                if(pcnt.find(s[left]) == pcnt.end()) left = right + 1;
            }
        }
        return ans;
    }
};