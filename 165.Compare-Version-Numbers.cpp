class Solution {
public:
    int compareVersion(string version1, string version2) {
        int n1 = version1.length();
        int n2 = version2.length();
        
        int rev_a = 0, rev_b = 0, i = 0, j = 0;
        
        while(i < n1 || j < n2){
            while(i < n1 && version1[i] != '.')
                rev_a = rev_a * 10 + (version1[i++] - '0');
            
            while(j < n2 && version2[j] != '.')
                rev_b = rev_b * 10 + (version2[j++] - '0');
            
            if(rev_a > rev_b ) return 1;
            else if(rev_a < rev_b) return -1;
            
            rev_a = 0;
            rev_b = 0;
            i++;
            j++;
        }
        
        return 0;
    }
};