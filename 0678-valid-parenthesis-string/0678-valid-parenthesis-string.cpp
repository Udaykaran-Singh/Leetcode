class Solution {
public:
    bool checkValidString(string s) {
        stack<char> st;
        int left = 0;

        for(char i: s){
            if(i == '('){
                st.push(i);
                left++;
            }
            else if(i == '*'){
                st.push(i);
            }
            else{
                if(left > 0){
                    if(st.top() == '('){
                        st.pop();
                        left--;
                    }
                    else{
                        int temp_star = 0;
                        while(st.top() == '*'){
                            temp_star++;
                            st.pop();
                        }

                        st.pop();
                        left--;

                        while(temp_star){
                            st.push('*');
                            temp_star--;
                        }
                    }
                }
                else{
                    if(!st.empty()){
                        st.pop();
                    }
                    else return false;
                }
            }
        }

        int star = 0;

        while(!st.empty()){
            if(st.top() == '*') star++;
            else{
                if(star) star--;
                else return false;
            }

            st.pop();
        }

        return true;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna