class MyQueue {
public:
    stack<int>input ; 
    stack<int>output ; 
    MyQueue() {
        
    }
    
    void push(int x) {
        input.push(x) ; 
    }
    
    int pop() {
        // agr output me hai to uska top pop kr denge otherwise input k sare ele ko pahle output me dalenge then pop krenge 
        if(!output.empty()){
            int x = output.top() ; 
            output.pop() ;
            return x ; 

        }else{
            while(!input.empty()){
                output.push(input.top()) ; 
                input.pop() ;
            }
            int x = output.top() ; 
            output.pop() ;
            return x ; 
        }
        
    }
    
     int peek() {
        if(output.empty()){
            while(!input.empty()){
                output.push(input.top());
                input.pop();
            }
        }
        return output.top();
    }
    
    bool empty() {
        // agr dono stak empty hoga tab queue empty hoga 
        if(input.empty() && output.empty()){
            return true ;
        }

        return false;
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */