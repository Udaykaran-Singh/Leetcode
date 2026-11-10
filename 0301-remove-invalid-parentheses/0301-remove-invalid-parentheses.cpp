class Solution {
    unordered_set<string> ans;
    string store = "";
    int siz;
    int max_len = 0;

public:

    void solve(string& s, int left, int i){
        // pruning
        if(left < 0) return;

        // base case
        if(i == siz){
            if(left == 0){
                if(store.size() > max_len){
                    max_len = store.size();
                    ans.clear();
                }

                if(store.size() == max_len){
                    ans.insert(store);
                }
            }
            
            return;
        }

        // adding alphas
        if((s[i] != '(') && (s[i] != ')')){
            store.push_back(s[i]);
            solve(s, left, i+1);
            store.pop_back();
            return;
        }


        // leave
        solve(s, left, i+1);

        // pic
        store.push_back(s[i]);
        solve(s, left + (s[i] == '(' ? 1 : -1), i+1);
        store.pop_back();

        
    }

    vector<string> removeInvalidParentheses(string& s) {
        int left = 0;
        siz = s.size();
        solve(s, left, 0);

        return vector<string>(ans.begin(), ans.end());
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna