class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int el = nums[0], cnt = 1;
        for(int i = 1; i < nums.size(); i++){
            if(nums[i] == el) cnt++;
            else {
                cnt--;
                if(cnt == 0){
                    el = nums[i];
                    cnt = 1;
                }
            }
        }
        return el;
    }
};