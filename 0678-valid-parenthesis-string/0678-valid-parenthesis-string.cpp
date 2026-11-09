class Solution {
public:
    bool checkValidString(string& s) {
        int lefts = 0;
        int rights = 0;
        int len = s.size() - 1;
        
        for(int i = 0; i <= len; i++){
            if(s[i] == '(' || s[i] == '*') lefts++;
            else lefts--;
            
            if(s[len - i] == ')' || s[len - i] == '*') rights++;
            else rights--;
            
            if(lefts < 0 || rights < 0) return false;
        }
        
        return true;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna