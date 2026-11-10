class Solution {
public:
    int firstUniqChar(string& s) {
        int n = s.size();
        if(n == 1) return 0;

        vector<int> freq(26, 0);

        for(int i = 0; i < n; i++){
            freq[s[i] - 'a']++;
        }

        for(int i = 0; i < n; i++){
            if(freq[s[i] - 'a'] == 1) return i;
        }

        return -1;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna