class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        vector <int> tmp(nums.size());
        
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] & 1) tmp[i] = nums[i] * 2;
            else tmp[i] = nums[i];
        }
        
        int ans = INT_MAX;
        while(tmp[tmp.size() - 1] % 2 == 0){
            tmp[tmp.size() - 1] /= 2;
            sort(tmp.begin(), tmp.end());
            int dev = tmp[tmp.size() - 1] - tmp[0];
            ans = min(ans, dev);
        }
        
        return ans;
    }
};