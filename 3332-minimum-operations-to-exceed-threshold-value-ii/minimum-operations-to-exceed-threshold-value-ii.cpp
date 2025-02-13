class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        priority_queue<long long, vector<long long>, greater<long long>> pq;

        for (int num : nums) {
            if (num < k) {
                pq.push(num);
            }
        }

        long long op = 0;

    
        if (pq.empty()) return 0;

       
        while (pq.size() > 1 && pq.top() < k) {
            long long t1 = pq.top();
            pq.pop();
            long long t2 = pq.top();
            pq.pop();

           
            pq.push(2 * t1 + t2);
            op++;
        }

        return pq.top() < k ? op + 1 : op;
    }
};
