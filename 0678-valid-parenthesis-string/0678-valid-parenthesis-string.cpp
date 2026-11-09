class Solution {
public: 
    bool checkValidString(string& s) {
        stack<int> left; 
        stack<int> star;

        for(int i = 0; i < s.length(); i++) {
            char ch = s[i];

            if(ch == '(') left.push(i);
            else if(ch == '*') star.push(i);
            else{
                if(!left.empty()) left.pop();
                else if(!star.empty()) star.pop();
                else return false;
            }
        }

        while(!left.empty() && !star.empty()){
            if(left.top() > star.top()) return false;
            left.pop();
            star.pop();
        }

        return left.empty();
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna