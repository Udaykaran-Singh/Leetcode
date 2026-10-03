class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> ans(m+n);
        int u = 0, v = 0;

        for(int i = 0; i < m+n; i++){
            if((u >= m) && (v < n)){
                ans[i] = nums2[v++];
                continue;
            }

            if((v >= n) && (u < m)){
                ans[i] = nums1[u++];
                continue;
            }

            ans[i] = (nums1[u] <= nums2[v]) ? nums1[u++] : nums2[v++];
        }

        nums1 = ans;
    }
};