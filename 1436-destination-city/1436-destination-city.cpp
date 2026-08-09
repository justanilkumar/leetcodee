class Solution {
public:
    string destCity(vector<vector<string>>& paths) {

        unordered_set<string> start;

       
        for(auto path : paths) {
            start.insert(path[0]);
        }

       
        for(auto path : paths) {
            if(start.find(path[1]) == start.end()) {
                return path[1];
            }
        }

        return "";
    }
};