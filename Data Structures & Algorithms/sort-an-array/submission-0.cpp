class Solution {
public:

    void mergeSort(vector<int>& arr, int l, int r){
        if(l >= r) return;
        int m = (l + r)/2;
        mergeSort(arr, l, m);
        mergeSort(arr, m+1,r);
        int i = l, j = m + 1;
        vector<int> temp;
        while(i <= m && j <= r){
            if(arr[i] < arr[j]){
                temp.push_back(arr[i]);
                i++;
            }
            else{
                temp.push_back(arr[j]);
                j++;
            }
        }

        while(i <= m)temp.push_back(arr[i++]);
        while(j <= r)temp.push_back(arr[j++]);
        for(i = 0; i <= (r - l); i++){
            arr[l+i] = temp[i];
        }
        return;
    }
    vector<int> sortArray(vector<int>& nums) {
        mergeSort(nums, 0, nums.size() - 1);
        return nums;
    }
};