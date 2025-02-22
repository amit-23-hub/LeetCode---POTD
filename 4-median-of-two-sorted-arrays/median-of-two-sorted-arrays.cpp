class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        
        int n = nums1.size() ; 
        int m  =  nums2.size() ;
        vector<int>store ; 
        int i = 0 ; 
        int j = 0 ; 
        int k = 0 ; 
        while(i<n && j<m){
            if(nums1[i]<nums2[j]){
                store.push_back(nums1[i]) ; 
                i++ ; 

            }else{
                store.push_back(nums2[j]) ;
                j++ ; 
            }
        }

        while(i<n){
             store.push_back(nums1[i]) ;
             i++ ; 
        }
        while(j<m){
            store.push_back(nums2[j]) ;
            j++ ; 
        }
 int med =  (n+m)/2 ; 
 double ans = 0 ; 
 if((n+m)%2==0){
    ans  = (store[med]+store[med-1])/2.0 ; 
 }else{
    ans = store[med] ; 
 }
     return ans ;     
    }
};