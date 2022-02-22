class Solution {
public:
    int titleToNumber(string columnTitle) {
        int i;
        long long r = 0;
        for(char c : columnTitle){
            int d = c - 'A' + 1;
            r = r * 26 + d;
        }
        return r;
    }
};