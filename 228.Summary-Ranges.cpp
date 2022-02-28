class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums){
        vector<string> ans;
        if (!nums.size()) return ans;
        
        int start = nums[0], end = nums[0];
        
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] == nums[i - 1] + 1) end = nums[i];
            else {
                if (start == end) ans.push_back(to_string(end));
                else ans.push_back(to_string(start) + "->" + to_string(end)); 
                
                start = nums[i];
                end = nums[i];
            }
        }
        
        if(start == end) ans.push_back(to_string(end));
        else ans.push_back(to_string(start) + "->" + to_string(end));                 
        
        return ans;
    }
};