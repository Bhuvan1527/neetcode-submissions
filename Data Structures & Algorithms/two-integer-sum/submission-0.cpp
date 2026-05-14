class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> umap;
        vector<int> ans{-1,-1};
        for(int i = 0; i < nums.size(); i++){
            if(umap.count(target - nums[i])){
                    ans[0] = umap[target - nums[i]];
                    ans[1] = i;
                    break;
            }
            else{
                umap[nums[i]] = i;
            }
        }
        return ans;
    }
};
