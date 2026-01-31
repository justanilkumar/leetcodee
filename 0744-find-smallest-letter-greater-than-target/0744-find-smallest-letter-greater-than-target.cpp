class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        sort(letters.begin(),letters.end());
        for(char c:letters){
            if(c>target) {
                return c;
            }
        }
       return letters[0];
       
    }
};