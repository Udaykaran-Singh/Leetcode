class Solution {
  public:
    int kthSmallest(vector<int> &arr, int k) {
        // code here
        priority_queue<int> pq;
        int n = arr.size();
        
        for(int i = 0; i < k && i < n; i++){
            pq.push(arr[i]);
        }
        
        for(int i = k; i < n; i++){
            if(arr[i] < pq.top()){
                pq.push(arr[i]);
                pq.pop();
            }
        }
        
        return pq.top();
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna