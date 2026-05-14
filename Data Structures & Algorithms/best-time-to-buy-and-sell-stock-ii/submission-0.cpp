class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans = 0, buy;
        buy = prices[0];
        for(int i: prices){
            if(i <= buy){
                buy = i;
            }
            else{
                ans += i - buy;
                buy = i;
            }
        }
        return ans;
    }
};