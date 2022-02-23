/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    unordered_map<int, Node*> mp;
    Node* cloneGraph(Node* node) {
        if (node == NULL) return node; 
        if (mp.count(node->val)) return mp[node->val]; 
        
        // Cloning Node
        vector <Node*> arr;
        mp[node->val] = new Node(node->val, arr);
        
        // Exploring neighbors
        for (int i = 0; i < (node->neighbors).size(); i++) {
            Node * temp = cloneGraph(node->neighbors[i]);
            mp[node->val]->neighbors.push_back(temp);
        }
        
        return mp[node->val];
    }
};