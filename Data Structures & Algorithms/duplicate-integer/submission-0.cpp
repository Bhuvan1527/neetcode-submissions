class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_map<int,int> umap;

        for(int i: nums){
            if(umap.count(i)) return true;
            else umap[i]++;
        }
        return false;
    }
};