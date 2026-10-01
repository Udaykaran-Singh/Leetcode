class Solution {
public:
    int bitwiseComplement(int n) {
        if(n == 0) return 1;

        int ans = 0, two_count = 1;
        while(n){
            if(!(n&1)) ans += two_count;
            
            n >>= 1;
            two_count <<= 1;
        }

        return ans;
    }
};