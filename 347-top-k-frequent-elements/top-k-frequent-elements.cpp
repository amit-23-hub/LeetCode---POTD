class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        priority_queue<pair<int ,int>> maxHeap;
        unordered_map<int, int> freq ; 

        for (int num : nums) {
        freq[num]++;
        }
        for (auto it = freq.begin(); it != freq.end(); it++) {
         maxHeap.push({it->second, it->first});  // Store (frequency, number)
          }
      vector<int>ans ; 
       while(k>0){
           int number = maxHeap.top().second ; 
           ans.push_back(number) ; 
            maxHeap.pop() ; 
          k-- ; 
       }

       return ans  ;
    }
};