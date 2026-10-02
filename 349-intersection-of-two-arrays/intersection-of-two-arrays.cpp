class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, bool> isPresent;
        unordered_set<int> set;

        for(int &i: nums1){
            isPresent[i] = true;
        }

        for(int &i : nums2){
            if(isPresent[i]) set.insert(i);
        }

        return vector<int>(set.begin(), set.end());

    }
};