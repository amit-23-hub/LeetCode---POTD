/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
    unordered_map<Node* , Node* > mp    ; 
public:

void bfs(queue<Node*>q){
    while(!q.empty()){
        Node* front = q.front() ; 
        q.pop() ; 
        Node* cloneNode = mp[front] ; 

        for(Node* n :front->neighbors ){
            // agr deep copy created nhi hai to 
            if(mp.find(n)==mp.end()){
                  Node* clone = new Node (n->val) ;
                  mp[n] = clone  ; 
                  cloneNode->neighbors.push_back(clone) ; 
                  q.push(n) ; 
            }else{
                 cloneNode->neighbors.push_back(mp[n]) ; 
            }
        }
    }
}
    
    Node* cloneGraph(Node* node) {
        
        if (! node){
            return NULL ; 
        }

        // agr node hai to new node create kr lenge jo clone groahg me pass hua hai 
        Node* cloneNode =  new Node(node->val) ; 
        mp[node] = cloneNode ; 
        queue<Node*>q ; 
        q.push(node) ; 
        bfs(q) ; 
        return cloneNode ; 
    }
};