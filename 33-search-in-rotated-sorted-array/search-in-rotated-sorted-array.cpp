class Solution {
public:
    int search(vector<int>& nums, int target) {
        if(nums.size() == 1 && nums[0] == target) return 0;

        int i = 0, j = nums.size();
        while(i < j){
            int mid = i + (j - i)/2;
            if(nums[mid] < nums[0]){
                j = mid;
            }
            else{
                i = mid + 1;
            }
        }

        int pivot = i;
        if(target < nums[0]){
            i = pivot, j = nums.size()-1;
        }else{
            i = 0; j = pivot - 1;
        }

        while(i <= j){
            int mid = i + (j-i)/2;

            if(target == nums[mid]){
                return mid;
            }
            else if(target < nums[mid]){
                j = mid-1;
            }else{
                i = mid + 1;
            }
        }

        return -1;
    }
};