class Solution {
    vector<string> ans;
    string store = "";
    string arr[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

    void solve(string& digits, int i, int m){
        // base case
        if(i == m){
            ans.push_back(store);
            return;
        }

        for(char j : arr[digits[i] - '0']){
            store.push_back(j);
            solve(digits, i+1, m);
            store.pop_back();
        }
    }

public:
    vector<string> letterCombinations(string& digits) {
        solve(digits, 0, digits.size());
        return ans;
    }
};