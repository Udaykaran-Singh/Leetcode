class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<char> st;

        for(char i : s){
            if(i == '(') st.push(i);
            else{
                if(!st.empty() && st.top() == '(') st.pop();
                else st.push(i);
            }
        }

        return st.size();
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna