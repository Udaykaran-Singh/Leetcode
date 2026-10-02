class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> freq;
        unordered_set<int> seenFreq;

        for(int i : arr){
            freq[i]++;
        }

        for(auto &[key, val] : freq){
            if(seenFreq.find(val) != seenFreq.end()){
                return false;
            }

            seenFreq.insert(val);
        }

        return true;
    }
};