class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int n = g.size();
        int m = s.size();

        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        int l = 0; // cookie pointer
        int r = 0; // child pointer

        while (l < m && r < n) {
            if (g[r] <= s[l]) {
                // child satisfied
                r++;
            }
            // move to next cookie
            l++;
        }

        return r; // number of satisfied children
    }
};