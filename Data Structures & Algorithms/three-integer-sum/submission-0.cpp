class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        set<vector<int>> ans;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size(); i++){
            int j = 0, k = nums.size() - 1;
            while(j < k){
                if(j == i) j++;
                else if(k == i) k--;
                if(j < k){
                    int sum = nums[j] + nums[k] + nums[i];
                    if(sum == 0) {
                        vector<int> temp{nums[i], nums[j] ,nums[k]};
                        sort(temp.begin(), temp.end());
                        ans.insert(temp);
                        j++;
                        k--;
                    }
                    else if(sum > 0) k--;
                    else j++;
                }
            }
        }
        vector<vector<int>> a;
        for(auto i: ans) a.push_back(i);
        return a;
    }
};
