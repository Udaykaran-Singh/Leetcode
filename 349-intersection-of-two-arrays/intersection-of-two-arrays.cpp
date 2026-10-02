class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, bool> isPresent;
        unordered_set<int> set;
        vector<int> ans;

        for(int &i: nums1){
            isPresent[i] = true;
        }

        for(int &i : nums2){
            if(isPresent[i]) set.insert(i);
        }

        for(int i : set){
            ans.push_back(i);
        }

        return ans;

    }
};