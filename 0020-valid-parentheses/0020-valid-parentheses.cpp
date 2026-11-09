class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(char i : s){
            if((i == '(') || (i == '{') || (i == '[')) st.push(i);
            else if((i == ')') && (!st.empty() && st.top() == '(')) st.pop();
            else if((i == ']') && (!st.empty() && st.top() == '[')) st.pop();
            else if((i == '}') && (!st.empty() && st.top() == '{')) st.pop();
            else return false;
        }

        return !st.size();
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna