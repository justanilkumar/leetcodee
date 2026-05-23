class Solution {
public:
    bool isPowerOfTwo(int n) {
        
        // base cases
        if(n <= 0) return false;

        if(n == 1) return true;

        // if not divisible by 2
        if(n % 2 != 0) return false;

        // recursive call
        return isPowerOfTwo(n / 2);
    }
};