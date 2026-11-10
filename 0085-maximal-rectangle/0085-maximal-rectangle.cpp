class Solution {
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> prev(n), next(n);

        stack<int> st;
        st.push(n);

        for(int i = n - 1; i >= 0; i--){
            while(st.top() != n && heights[st.top()] >= heights[i]) st.pop();

            next[i] = st.top();
            st.push(i);
        }
        
        while(!st.empty()) st.pop();
        st.push(-1);

        for(int i = 0; i < n; i++){
            while(st.top() != -1 && heights[st.top()] >= heights[i]) st.pop();

            prev[i] = st.top();
            st.push(i);
        }

        int ans = 0;

        for(int i = 0; i < n; i++){
            ans = max(ans, (next[i] - prev[i] - 1)*heights[i]);
        }

        return ans;

    }
public:

    int maximalRectangle(vector<vector<char>>& matrix) {
        vector<int> heights(matrix[0].size(), 0);
        int ans = 0;

        for(int i = 0; i < matrix.size(); i++){
            for(int j = 0; j < matrix[0].size(); j++){
                // cout<<i<<" "<<j<<" :";

                if(matrix[i][j] == '1') heights[j] += 1;
                else heights[j] = 0;

                // cout<<heights[j]<<endl;
            }

            // for(int k:heights) cout<<k<<" ";
            // cout<<endl;

            ans = max(ans, largestRectangleArea(heights));
        }

        return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna