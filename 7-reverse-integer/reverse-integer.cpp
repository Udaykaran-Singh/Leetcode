class Solution {
public:
    int reverse(int x) {
        int num = x;
        int ans = 0;

        while(num){
            int digit = num%10;
            num /= 10;
            
            if((ans < INT_MIN/10) || (ans > INT_MAX/10)) return 0;

            ans = ans*10 + digit;
        }

        return ans;
    }
};