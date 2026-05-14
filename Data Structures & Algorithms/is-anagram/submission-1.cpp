class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char,int> umap;
        for(char c : s){
            umap[c]++;
        }

        for(char c: t){
            if(!umap.count(c))return false;
            umap[c]--;
            if(umap[c] == 0) umap.erase(c);
        }
        if(umap.size() == 0)return true;
        else return false;
    }
};
