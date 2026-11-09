class Solution {
public:
    int minSwaps(string s) {
        int left = 0, right = 0;

        for(char i: s){
            if(i == '[') left++;
            else{
                if(left) left--;
                else right++;
            }
        }


        return (right + 1)/2;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna