class Solution {
public:
    int maximum69Number (int num) {
        
        vector<int>arr ; 
        if(num == 0){
            arr.push_back(0) ; 
        }else {
            int temp  =  num ;  
            while(temp>0){

            arr.push_back(temp%10) ; 
            temp = temp/10 ; 
            }
        }
       reverse(arr.begin(), arr.end());

       for(int i = 0 ; i <arr.size() ; i++) { 
            if(arr[i]==6){
                arr[i] = 9 ; 
                break ; 
            }
       }
       // convert arraay to string then in int 
    
    string s = "";

    // Convert each digit to a string and append
    for (int digit : arr) {
        s += to_string(digit);
    }

    // Convert the combined string to an integer
    int number = stoi(s);
  
  return number ; 
    }
};