class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<long> preProd(n), sufProd(n);
        preProd[0] = nums[0];
        sufProd[n-1] = nums[n-1];
        for(int i = 1; i < n; i++){
            preProd[i] = nums[i] * preProd[i-1];
            sufProd[n-i-1] = sufProd[n-i]*nums[n-i-1];
        }

        vector<int> ans(n);
        ans[0] = sufProd[1];
        for(int i = 1; i < n-1; i++){
            ans[i] = preProd[i-1] * sufProd[i+1];
        }
        ans[n-1] = preProd[n-2];
        return ans;

    }
};
