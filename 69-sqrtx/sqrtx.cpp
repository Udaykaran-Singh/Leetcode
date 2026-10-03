class Solution {
public:
    int mySqrt(int x) {
        int i = 0, j = x;
        int ans = 0;

        while(i <= j){

            long long int mid = i + (j-i)/2;
            if(mid*mid > x){
                j = mid - 1;
            }
            else if(mid*mid < x){
                ans = mid;
                i = mid + 1;
            }
            else{
                return mid;
            }
        }

        return ans;
    }
};