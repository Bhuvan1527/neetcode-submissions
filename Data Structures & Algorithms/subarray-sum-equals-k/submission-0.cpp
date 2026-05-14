class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        vector<int> p_sum{nums[0]};
        for(int i = 1; i < nums.size(); i++){
            p_sum.push_back(p_sum[i-1]+nums[i]);
        }

        int ans = 0;
        unordered_map<int,int> umap;
        umap[0] = 1;
        for(int i: p_sum){
            if(umap.count(i-k)){
                ans += umap[i-k];
            }
            umap[i]++;
        }
        return ans;
    }
};