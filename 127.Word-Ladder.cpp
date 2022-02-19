class Solution {
public:
    int ladderLength(string start, string end, vector<string> &wordList) {
        if(count(wordList.begin(), wordList.end(), end) == 0) return 0;
        
        map <string, int> dis;
        unordered_set<string> dict(wordList.begin(), wordList.end());
        dis[start] = 1;
        
        queue<string> q;
        q.push(start);
        
        while(!q.empty()){
            string word = q.front(); 
            q.pop();
            
            if (word == end) break;
            
            for (int i = 0; i < word.size(); i++){
                string tmp = word;
                for(char c='a'; c<='z'; c++){
                    tmp[i] = c;
                    if (dict.count(tmp) > 0 && dis.count(tmp) == 0){
                        dis[tmp] = dis[word] + 1;
                        q.push(tmp);
                    }
                }
            }
        }
        return dis[end];
        
    }
};