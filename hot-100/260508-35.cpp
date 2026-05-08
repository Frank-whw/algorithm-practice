class Solution {
public:
    int binary_search(vector<int>& nums, int target){
        int l = 0, r = nums.size();
        while (l < r )
        {
            int mid = l + (r - l) / 2;
            if(nums[mid] == target)   return mid;
            if(nums[mid] < target){
                l = mid + 1;
            }else{
                r = mid;
            }
        }
        return r;
        
    }
    int searchInsert(vector<int>& nums, int target) {
        //找到第一个大于等于target的值
        return binary_search(nums, target);
    }
};