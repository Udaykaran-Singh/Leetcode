class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        int rs = 0, re = m - 1;
        int cs = 0, ce = n - 1;

        vector<int> ans;
        ans.reserve(m * n);

        while (rs <= re && cs <= ce) {

            // 1. Top row
            for (int j = cs; j <= ce; j++) {
                ans.push_back(matrix[rs][j]);
            }
            rs++;

            // 2. Right column
            for (int i = rs; i <= re; i++) {
                ans.push_back(matrix[i][ce]);
            }
            ce--;

            // 3. Bottom row
            if (rs <= re) {
                for (int j = ce; j >= cs; j--) {
                    ans.push_back(matrix[re][j]);
                }
                re--;
            }

            // 4. Left column
            if (cs <= ce) {
                for (int i = re; i >= rs; i--) {
                    ans.push_back(matrix[i][cs]);
                }
                cs++;
            }
        }

        return ans;
    }
};