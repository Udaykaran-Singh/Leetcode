class Solution {
public:
    string removeDuplicates(string& s) {
        string st = "";

        for(int i = 0; i < s.size(); i++){
            (!st.empty() && (st.back() == s[i])) ? st.pop_back() : st.push_back(s[i]);
        }

        return st;
    }
};