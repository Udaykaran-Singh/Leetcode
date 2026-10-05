class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();
        int start = 0, end = m*n - 1;

        while(start <= end){
            int mid = start + (end - start)/2;
            int row = mid / n, col = mid % n;
            int val = matrix[row][col];

            if(val == target) return true;
            else if(target < val) end = mid - 1;
            else start = mid + 1;
        }

        return false;
    }
};