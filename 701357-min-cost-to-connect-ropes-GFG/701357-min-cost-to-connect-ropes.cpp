class Solution {
  public:
    int minCost(vector<int>& arr) {
        // code here
        priority_queue<int, vector<int>, greater<int>> pq;
        
        for(int i: arr){
            pq.push(i);
        }
        
        int cost;
        
        while(pq.size() > 1){
            int a = pq.top();
            pq.pop();
            
            int b = pq.top();
            pq.pop();
            
            cost += a+b;
            
            pq.push(a+b);
        }
        
        return cost;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna