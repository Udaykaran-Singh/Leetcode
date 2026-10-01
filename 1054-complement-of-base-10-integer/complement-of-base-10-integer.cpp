class Solution {
public:
    int bitwiseComplement(int n) {
        if(n == 0) return 1;

        int ans = 0, count = 0;
        while(n){
            if(!(n&1)) ans += pow(2, count);
            
            n >>= 1;
            count++;
        }

        return ans;
    }
};