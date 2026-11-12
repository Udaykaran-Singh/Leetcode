class Solution {
    const int MOD = 1e9 + 7;
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        if(n == 1) return arr[0];

        vector<int> prev(n, 0), next(n, 0);
        stack<int> st;
        st.push(-1);

        for(int i = 0; i < n; i++){
            while(st.top() != -1 && arr[st.top()] >= arr[i]) st.pop();

            prev[i] = st.top();
            st.push(i);
        }

        while(!st.empty()){
            st.pop();
        }

        st.push(n);

        for(int i = n-1; i >= 0; i--){
            while(st.top() != n && arr[st.top()] > arr[i]) st.pop();

            next[i] = st.top();
            st.push(i);
        }

        long long ans = 0;

        for(int i = 0; i < n; i++){
            ans = (ans + 1LL * (i - prev[i]) * (next[i] - i) * arr[i] % MOD) % MOD;
        }

        return ans;
        
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna