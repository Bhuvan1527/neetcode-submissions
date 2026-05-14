class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i = 0, j = 0;
        for(i = 0, j = 1; j < nums.size(); j++){
            if(nums[i] != nums[j]){
                if(j > i + 1){
                    nums[i+1] = nums[j];
                }
                i++;
            }
        }
        return i+1;
    }
};