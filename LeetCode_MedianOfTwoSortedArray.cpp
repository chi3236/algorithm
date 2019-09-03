class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> totalNum = nums1;
        totalNum.insert(totalNum.end(), nums2.begin(), nums2.end());
        sort(totalNum.begin(), totalNum.end());
        int totalSize = totalNum.size();
        if(totalSize % 2 == 1)
        {
            return (double)totalNum[totalSize / 2];
        }
        else
        {
            return ((double)totalNum[(totalSize / 2) - 1] + (double)totalNum[(totalSize / 2)]) / 2;
        }
            
    }
};