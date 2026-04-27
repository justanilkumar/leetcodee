class Solution {
public:
    int romanToInt(string s) {

        int sum = 0;

        for (int i = 0; i < s.size(); i++) {
            int cur = val(s[i]);

            if (i < s.size() - 1 && cur < val(s[i + 1]))
                sum -= cur;
            else
                sum += cur;
        }

        return sum;
    }

private:
    int val(char c) {

        if (c == 'I') return 1;
        if (c == 'V') return 5;
        if (c == 'X') return 10;
        if (c == 'L') return 50;
        if (c == 'C') return 100;
        if (c == 'D') return 500;
        return 1000;

    }
};