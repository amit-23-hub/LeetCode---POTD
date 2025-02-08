class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
       
       if(m==0){
            for(int x=0;x<n;x++){
                nums1[x]=nums2[x];
            }
        }
        int i=m-1;
        int j=n-1;
        int k=nums1.size()-1;
        while(i>=0 && j>=0){
            if(nums1[i]>=nums2[j]){
                nums1[k]=nums1[i];
                i--;
                k--;
            }
            else{
                nums1[k]=nums2[j];
                j--;
                k--;
            }
            
        }
        while (j >= 0) {
            nums1[k] = nums2[j];
            j--;
            k--;
        }
    }
};