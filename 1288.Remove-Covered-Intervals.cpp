class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals){
        sort(intervals.begin(), intervals.end());
        int ans = 0;
        int l = -1, r = -1;
        for(auto interval : intervals){
            if(l < interval[0] && r < interval[1]){
                l = interval[0];
                r = interval[1];
                ans++;
            }
            else r = max(r, interval[1]);
        }
        return ans;
    }
};