class Solution {
public:
    string removeOccurrences(string s, string pattern) {
        vector<int> kmpLPS = LSP(pattern);
        stack<char> st;
        vector<int> sLSP(s.length() + 1, 0);

        for (int i = 0, len = 0; i < s.length(); i++) {
            char ch = s[i];
            st.push(ch);

            if (ch == pattern[len]) {
                sLSP[st.size()] = ++len;

                if (len == pattern.length()) {

                    int popCount = pattern.length();
                    while (popCount != 0) {
                        st.pop();
                        popCount--;
                    }

                    len = st.empty() ? 0 : sLSP[st.size()];
                }
            } else {
                if (len != 0) {
                    i--;
                    len = kmpLPS[len - 1];
                    st.pop();
                } else {
                    sLSP[st.size()] = 0;
                }
            }
        }

        string result = "";
        while (!st.empty()) {
            result = st.top() + result;
            st.pop();
        }

        return result;
    }

private:
    vector<int> LSP(string& pattern) {
        vector<int> lps(pattern.length());
        lps[0] = 0;

        for (int i = 1, len = 0; i < pattern.length();) {

            if (pattern[i] == pattern[len]) {
                lps[i++] = ++len;
            }
            else if (len != 0) {
                len = lps[len - 1];
            }
            else {
                lps[i++] = 0;
            }
        }

        return lps;
    }
};