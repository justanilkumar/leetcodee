class Solution {
public:
    int maxVowels(string s, int k) {
        int left = 0;
        int right = k;
        int count = 0;
        int maxi = 0;

        // First window
        for (int i = 0; i < right; i++) {
            if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' ||
                s[i] == 'o' || s[i] == 'u') {
                count++;
            }
        }

        maxi = count;

        // Slide the window
        while (right < s.size()) {

            // Remove left character
            if (s[left] == 'a' || s[left] == 'e' || s[left] == 'i' ||
                s[left] == 'o' || s[left] == 'u') {
                count--;
            }

            left++;

            // Add right character
            if (s[right] == 'a' || s[right] == 'e' || s[right] == 'i' ||
                s[right] == 'o' || s[right] == 'u') {
                count++;
            }

            right++;

            maxi = max(maxi, count);
        }

        return maxi;
    }
};