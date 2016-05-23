class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int index = m + n - 1;
        int nums1_index = m - 1;
        int nums2_index = n - 1;
        
        while ( 0 <= nums1_index && 0 <= nums2_index ) {
            
            if (nums1[nums1_index] < nums2[nums2_index] )
                nums1[index--] = nums2[nums2_index--];
            else
                nums1[index--] = nums1[nums1_index--];
                
        }
        
        while ( 0 <= nums1_index )
            nums1[index--] = nums1[nums1_index--];
            
        while ( 0 <= nums2_index )
            nums1[index--] = nums2[nums2_index--];
    }
};