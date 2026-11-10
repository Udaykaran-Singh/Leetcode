class Solution {
  public:
    int celebrity(vector<vector<int>>& mat) {
        // code here
        int n = mat.size();
        stack<int> st;
        for(int i = 0; i < n; i++){
            st.push(i);
        }
        
        while(st.size() != 1){
            int a = st.top();
            st.pop();
            int b = st.top();
            st.pop();
            
            mat[a][b] ? st.push(b) : st.push(a);
        }
        
        int a = st.top();
        st.pop();
        
        int h_sum = 0, v_sum = 0;
        
        for(int i = 0; i < n; i++){
            v_sum += mat[i][a];
            h_sum += mat[a][i];
        }
        
        return (h_sum == 1 && v_sum == n) ? a : -1;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna