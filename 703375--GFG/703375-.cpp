class Solution {
  public:
    vector<int> firstNegInt(vector<int>& arr, int k) {
        // code here
        vector<int> ans;
        queue<int> q;
        
        for(int i = 0; i < k; i++){
            if(arr[i] < 0) q.push(i);
        }
        
        q.empty() ? ans.push_back(0) : ans.push_back(arr[q.front()]);
        
        for(int i = k; i < arr.size(); i++){
            while((!q.empty()) && (i - q.front() >= k)) q.pop();
            
            if(arr[i] < 0) q.push(i);
            q.empty() ? ans.push_back(0) : ans.push_back(arr[q.front()]);
        }
        
        return ans;
        
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna