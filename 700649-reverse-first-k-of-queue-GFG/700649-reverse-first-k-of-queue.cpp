class Solution {
  public:
    queue<int> reverseFirstK(queue<int>& q, int k) {
        // code here
        int n = q.size();
        if (k <= 0 || k > n) return q;
        
        stack<int> st;
        
        while(k){
            st.push(q.front());
            q.pop();
            k--;
            n--;
        }
        
        while(!st.empty()){
            q.push(st.top());
            st.pop();
        }
        
        while(n){
            q.push(q.front());
            q.pop();
            n--;
        }
        
        return q;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna