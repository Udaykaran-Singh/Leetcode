class Solution {
  public:
    void rearrangeQueue(queue<int> &q) {
        // code here
        int n = q.size();
        if(n < 3){
            return;
        }
        
        queue<int> q1, q2;
        
        while(q.size() != n/2){
            q1.push(q.front());
            q.pop();
        }
        
        for(int i = 0; i < n/2; i++){
            q2.push(q1.front());
            q1.pop();
            
            q2.push(q.front());
            q.pop();
        }
        
        q = q2;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna