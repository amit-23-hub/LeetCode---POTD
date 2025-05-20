class StockSpanner {
public:
    stack<pair<int,int>>st ; 
    StockSpanner() {
        
    }
    
    int next(int price) {
        int span = 1 ;         ///  sbka span 1 hota hai 

        while(!st.empty() && st.top().first<= price){   /// agr cuurent price se jitne bhi chhote honge unta count krke span me add kr denge 
            span = span + st.top().second ; 
            st.pop();
        }

        st.push({price,span}) ; 

        return span ;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */