class Solution {
public:
    void sortColors(vector<int>& nums) {
        int zptr = -1, tptr = nums.size();
        int i = 0;
        while(i < tptr){
            if(nums[i] == 0 && zptr < i){
                zptr++;
                swap(nums[zptr], nums[i]);
            }
            if(nums[i] == 2){
                tptr--;
                swap(nums[tptr], nums[i]);
                continue;
            }
            i++;
        }
        return;

    }
};