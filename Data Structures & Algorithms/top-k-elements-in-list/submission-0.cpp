class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> umap;
        for(int i: nums) umap[i]++;
        //maxHeap
        priority_queue<pair<int,int>> pq;
        for(auto i: umap){
            pq.push({i.second, i.first});
        }

        vector<int> ans;
        for(int i = 0; i < k; i++){
            auto top = pq.top();
            pq.pop();
            ans.push_back(top.second);
        }
        return ans;
    }
};
