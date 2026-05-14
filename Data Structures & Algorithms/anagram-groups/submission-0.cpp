class Solution {
public:
    bool areAnagrams(vector<vector<int>>& c, int i, int j){
        for(int k = 0; k < 26; k++){
            if(c[i][k] != c[j][k]) return false;
        }
        return true;
    }
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n = strs.size();
        vector<vector<int>> count(n, vector<int>(26, 0));
        int idx = 0;
        vector<vector<string>> ans;
        for(int i = 0; i < n; i++){
            for(char c: strs[i]){
                count[i][c-'a']++;
            }
        }
        vector<int> status(n, -1);
        for(int i = 0; i < n; i++){
            if(status[i] != -1) continue;
            vector<string> an{strs[i]};
            status[i] = 0;
            for(int j = i+1; j < n; j++){
                if(areAnagrams(count, i, j)){
                    an.push_back(strs[j]);
                    status[j] = 0;
                }
            }
            ans.push_back(an);
        }
        return ans;
    }
};
