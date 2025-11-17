class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        int n = nums.size();
        int mincnt = INT_MAX;
        bool seen = false; 
        int cnt = 0;

        for(int i = 0; i < n; i++){
            if(nums[i] == 1){
                if(seen) mincnt = min(mincnt, cnt);
                seen = true;
                cnt = 0;
            } else {
                if(seen) cnt++;
            }
        }

        if(!seen) return true;
        return mincnt >= k;
    }
};
