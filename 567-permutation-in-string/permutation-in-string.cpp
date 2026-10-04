class Solution {
public:
    bool check(vector<int>& s, vector<int>& window){
        for(int i = 0; i < 26; i++){
            if(s[i] != window[i]) return false;
        }

        return true;
    }

    bool checkInclusion(string s1, string s2) {
        int n = s1.size();

        if(n > s2.size()) return false;

        vector<int> s(26, 0);
        for(char i: s1){
            s[i - 'a']++;
        }

        vector<int> window(26, 0);
        for(int i = 0; i < n; i++){
            window[s2[i] - 'a']++;
        }

        if(check(s, window)) return true;

        for(int i = n; i < s2.size(); i++){
            window[s2[i] - 'a']++;
            window[s2[i - n] - 'a']--;

            if(check(s, window)) return true;
        }

        return false;

    }
};