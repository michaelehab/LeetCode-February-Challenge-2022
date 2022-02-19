class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int sum = 0, longest = 0;
        unordered_map <int, int> sum_index;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == 0) sum--;
            else sum++;
            
            if(sum == 0) longest = max(longest, i + 1);
            
            else if(sum_index.find(sum) != sum_index.end())
                longest = max(longest, i - sum_index[sum]);
            
            else sum_index[sum] = i;
        }
        
        return longest;
    }
};