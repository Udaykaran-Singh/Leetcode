class Solution {
  public:
    bool checkRedundancy(string &s) {
        // code here
        stack<char> st;
        
        for(char i : s){
            if(isalpha(i)) continue;
            
            if(i == '(' || i == '+' || i == '-' || i == '*' || i == '/') st.push(i);
            else{
                if(!st.empty() && st.top() != '('){
                    while(!st.empty() && st.top() != '(') st.pop();
                    
                    if(st.empty()) return true;
                    
                    st.pop();
                }
                else return true;
            }
        }
        
        return false;
    }
};


// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna