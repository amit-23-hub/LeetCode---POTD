// class Solution {
// public:
//     int numOfSubarrays(vector<int>& arr) {
//         vector<vector<int>> store;  
//         int n = arr.size();

//         // Storing all unique subarrays
//         for (int i = 0; i < n; i++) {
//             vector<int> subar;
//             for (int j = i; j < n; j++) {
//                 vector<int> subar(arr.begin() + i, arr.begin() + j + 1);      // sliceing method 
//                 store.push_back(subar);      // Storing unique subarrays
//             }
//         }

//         int cnt = 0;

//         // Counting subarrays with odd sum
//         for (auto &subarray : store) {
//             int sum = 0;
//             for (int num : subarray) {
//                 sum += num;
//             }
//             if (sum % 2 != 0) {
//                 cnt++;
//             }
//         }

//         return cnt;
//     } } ; 

class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        const int MOD=1e9+7;
        long long o=0,e=1,s=0,r=0;
        for(int a:arr){
            s+=a;
            if(s%2==0){
                r=(r+o)%MOD;
                e++;
            }else{
                r=(r+e)%MOD;
                o++;
            }
        }return r;
    }
};


