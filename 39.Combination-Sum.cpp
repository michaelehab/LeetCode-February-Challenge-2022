class Solution {
public:
    vector<vector<int>> res;
    vector<int> r;
    
    void Solve(vector<int>& candidates, int target, int i){
        if(target == 0){
            res.push_back(r);
            return;
        }
        
        for(int j = i; j < candidates.size() && target - candidates[j] >= 0; j++){
            r.push_back(candidates[j]);
            Solve(candidates, target - candidates[j], j);
            r.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        Solve(candidates, target, 0);
        return res;
    }
};