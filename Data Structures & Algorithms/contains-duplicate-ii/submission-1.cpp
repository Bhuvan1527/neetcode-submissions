class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_set<int> window;
        for(int i = 0, j = 0; j < n; j++){
            if(j - i > k) {
                window.erase(nums[i]);
                i++;
            }
            if(window.count(nums[j])) return true;
            window.insert(nums[j]);
        }
        return false;
    }
};