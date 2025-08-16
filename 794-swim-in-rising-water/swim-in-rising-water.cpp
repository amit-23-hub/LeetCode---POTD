class Solution {
public:
 int r ,c  ; 
    int row[4] = {1,-1 , 0 , 0} ; 
    int col[4]  = {0,0 , -1,1} ; 

    bool isvalid(int i , int  j ){
        return i<r && i>=0 && j<c && j>=0 ; 
    }
    int swimInWater(vector<vector<int>>& grid) {
        int n =  grid.size() ; 
        r  =  grid.size() ; 


        c = grid[0].size() ; 
       vector<vector<int>> visited(n,vector<int>(n,0)); // iniitialis with 0 

       // in priority queue { val , {i,j}}
        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>> >pq;


pq.push({grid[0][0] , {0,0}}) ; 
// mark it visited 
visited[0][0] = 1 ;  

while(!pq.empty()){

    auto [val , idx] = pq.top() ; 
    auto [ i , j] = idx ; 
    pq.pop() ; 

    // check kr lenege ki ye last node pr pahucha ja nhi  
    if(i==n-1 && j==n-1){
        return val  ; 
    }
    // abb ek loop chalayneg jisme agal bagal k sare node ko check kr lenge 

    for(int k = 0 ; k<4 ; k++){
        int x = i+ row[k] ; 
        int y = j+col[k] ; 
        if(isvalid(x,y) && !visited[x][y]){
            int maxV =  max(val , grid[x][y]) ; 
            pq.push ( {maxV , {x,y }}) ; 
            visited  [x][y] = 1  ;  
        }
    }
}

return -1  ;   
    }
};