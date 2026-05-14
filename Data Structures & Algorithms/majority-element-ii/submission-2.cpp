class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int cand1, cand1C = 0, cand2, cand2C = 0;
        for(int i: nums){
            if(i == cand1)cand1C++;
            else if(i == cand2)cand2C++;
            else if(cand1C == 0){
                cand1C = 1;
                cand1 = i;
            }
            else if(cand2C == 0){
                cand2 = i;
                cand2C = 1;
            }
            else{
                cand1C--;
                cand2C--;
            }
        }

        int c1 = 0, c2 = 0;
        for(int i: nums){
            if(i == cand1)c1++;
            else if(i == cand2)c2++;
        }

        int n = nums.size();
        vector<int> ans;
        if(c1 > n/3) ans.push_back(cand1);
        if(c2 > n/3) ans.push_back(cand2);
        return ans;
    }
};