class Solution {
public:
    int reverse(int x) {
        long int num = x;
        bool neg = false;

        if(num < 0){
            num = -num;
            neg = true;
        }

        int max = (pow(2, 31) - 1)/10;
        int ans = 0;

        while(num){
            int digit = num%10;
            num /= 10;
            
            if(max < ans) return 0;

            ans = ans*10 + digit;
        }

        ans = neg ? -ans : ans;

        return ans;
    }
};