class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map <int, int> psum;
        int sum = 0, total = 0;
        for(int i : nums){
            sum += i;
            if(sum == k) total++;
            if(psum.find(sum - k) != psum.end()) total += psum[sum - k];
            psum[sum]++;
        }
        return total;
    }
};