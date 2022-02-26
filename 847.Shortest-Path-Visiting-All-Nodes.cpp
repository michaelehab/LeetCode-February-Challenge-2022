class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        if(graph.size() == 1) return 0;
        
        int n = graph.size();
        // Mask marking all the nodes as visited
        int all = (1 << n) - 1;
        
        // Node, Distance, Mask
        queue<pair<int,pair<int,int>>>q;
        set<pair<int,int>>seen;
        
        for(int i = 0 ; i<n; i++){
            // Starting from the i node
            int mask = (1<<i);
            q.push({i,{0,mask}});
            seen.insert({i,mask});
        }
        // BFS
        while(!q.empty()){
            auto node = q.front();
            q.pop();
            int val = node.first, dist = node.second.first, mask = node.second.second;
            for(auto temp : graph[val]){
                // New mask with all the visited nodes
                int newMask = (mask | (1<<temp));
                // Check ihe new mask has all the nodes visited 
                if(newMask == all) return dist + 1;
                else if(!seen.count(make_pair(temp,newMask))){
                    seen.insert(make_pair(temp,newMask));
                    q.push(make_pair(temp, make_pair(dist + 1 ,newMask)));
                }
            }
        }
        return 0;
    }
};