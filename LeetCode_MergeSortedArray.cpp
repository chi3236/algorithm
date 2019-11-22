class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if(m == 0 || n == 0)
        {
            if(n == 0)
            {
                return;
            }
            else if (m == 0)
            {
                nums1 = nums2;
                return;
            }
            return;
        }
        for(int i = 0; i < n; i++)
        {
            int lo = 0;
            int hi = m;
            while(lo < hi)
            {
                int mid = (lo + hi) / 2;
                if(nums1[mid] >= nums2[i])
                {
                    hi = mid;
                }
                else
                {
                    lo = mid + 1;
                }
            }
            if(lo >= m)
            {
                nums1[lo] = nums2[i];
            }
            else
            {
                int j = m;
                while(j > lo)
                {
                    nums1[j] = nums1[j-1];
                    j--;
                }
                nums1[lo] = nums2[i];
            }
            m++;
        }
    }
};
