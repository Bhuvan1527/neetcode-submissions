class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int,int> umap;
        int ans = 0;
        for(int i: nums){
            umap[i] = 1;
        }
        for(int i: nums){
            if(!umap.count(i-1)){
                int temp = 1;
                while(umap.count(temp + i)) temp++;
                ans = max(ans, temp);
            }
        }
        return ans;
    }
};
