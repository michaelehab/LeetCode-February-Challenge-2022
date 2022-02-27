/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        int max_width = 0;
        queue<pair<TreeNode*, int>>q;
        q.push({root, 0});
        
        while(!q.empty()){
            int n = q.size();
            int max_num = INT_MIN, min_num = INT_MAX;
            
            while(n--){
                TreeNode* curr = q.front().first;
                int idx = q.front().second;
                
                q.pop();
                
                max_num = max(max_num, idx);
                min_num = min(min_num, idx);
                
                // Casting to Long Long to avoid overflow
                if(curr->left) q.push({curr->left, (long long)2 * idx + 1});
                if(curr->right) q.push({curr->right, (long long)2 * idx + 2});
            }
            
            max_width = max(max_width, max_num - min_num + 1);
        }
        
        return max_width;
    }
};