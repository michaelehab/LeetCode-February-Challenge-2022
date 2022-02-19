class Solution {
public:
    bool binary_search(vector<int>& nums, int l, int r, int target){
        while(l <= r){
            int mid = l + (r - l)/2;
            if(nums[mid] == target) return true;
            if(nums[mid] > target) r = mid - 1;
            else l = mid + 1;
        }
        return false;
    }
    int findPairs(vector<int>& nums, int k) {
        int total = 0;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size(); i++){
            if(i != 0) if(nums[i] == nums[i - 1]) continue;
            if(binary_search(nums, i + 1, nums.size() - 1, nums[i] + k)) total++;
        }
        return total;
    }
};