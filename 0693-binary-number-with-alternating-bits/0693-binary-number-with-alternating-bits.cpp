class Solution {
public:
    bool hasAlternatingBits(int n) {
        
        while(n > 0) {
            int last = n % 2;   // last bit
            n = n / 2;
            
            int next = n % 2;   // next bit
            
            if(last == next) {
                return false;
            }
        }
        
        return true;
    }
};
