class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int candCount = 1, cand = nums[0];
        for(int i = 1; i < nums.size(); i++){
            if(cand == nums[i]) candCount++;
            else if(candCount == 0){
                candCount = 1;
                cand = nums[i];
            }
            else candCount--;
        }
        return cand;
    }
};