class Solution {
public:
    bool match(int* arr1, int* arr2){
        for(int i = 0; i < 26; i++)
            if(arr1[i] != arr2[i]) return false;
        return true;
    }
    
    bool checkInclusion(string s1, string s2) {
        if (s1.length() > s2.length()) return false;
        int* arr1 = new int[26];
        int* arr2 = new int[26];
        for(int i = 0; i < s1.length(); i++){
            arr1[s1[i] - 'a']++;
            arr2[s2[i] - 'a']++;
        }
        for(int i = 0; i < s2.length() - s1.length(); i++){
            if(match(arr1, arr2)) return true;
            arr2[s2[i + s1.length()] - 'a']++;
            arr2[s2[i] - 'a']--;
        }
        return match(arr1, arr2);
    }
};