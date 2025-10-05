class Solution {
public:
typedef pair<int, vector<int>> Item;
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>>ans ; 
      priority_queue<Item, vector<Item>, greater<Item>> pq;

      for(int i = 0; i < points.size() ; i++){
        int dis = ((points[i][0])*(points[i][0]) + (points[i][1])*(points[i][1])) ;
        pq.push({dis , points[i]} ) ;
      }

      while(k--){
        Item s = pq.top() ;
        ans.push_back(s.second) ; 
        pq.pop() ; 
      }
     return ans ; 
    }
};