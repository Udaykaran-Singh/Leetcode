class Solution {
  public:
    string firstNonRepeating(string &s) {
        // code here
        int n = s.size();
        if(n == 1) return s;
        
        string ans = "";
        vector<int> freq(26, 0);
        int i = 0, j = 0;
        
        while(j < n){
            freq[s[j] - 'a']++;
            
            while(i < j && freq[s[i] - 'a'] > 1) i++;
            
            if(freq[s[i] - 'a'] > 1) ans.push_back('#');
            else ans.push_back(s[i]);
            
            j++;
        }
        
        return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna