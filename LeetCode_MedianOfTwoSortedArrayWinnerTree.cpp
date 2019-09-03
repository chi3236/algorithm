class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int totalNum = nums1.size() + nums2.size();
        if(totalNum == 1)
        {
            if(!nums1.empty())
                return nums1[0];
            
            if(!nums2.empty())
                return nums2[0];      
        }
        int target = totalNum / 2;
        int index1 = 0, index2 = 0, count = 0;
        int remain = 0;
        double answer = 0;
        double answerPrev = 0;
        while(count <= target)
        {
            if(index1 >= nums1.size() || index2 >= nums2.size())
            {
                break;
            }
            if(totalNum % 2 == 1)
            {
                if(nums1[index1] < nums2[index2])
                    answer = nums1[index1++];
        
                else
                    answer = nums2[index2++];
                
            }
            else
            {
                if(nums1[index1] < nums2[index2])
                {
                    answerPrev = answer;
                    answer = nums1[index1++];
                }
                else
                {
                    answerPrev = answer;
                    answer = nums2[index2++];
                }
            }
            count++;
        }
        remain = target - (count-1);
        if(remain != 0)
        {
            if(index1 == nums1.size())
            {
                if(totalNum % 2 == 1)
                    answer = nums2[index2 + remain - 1];
            
                else
                {
                    if(remain == 1)
                    {
                        answerPrev = answer;
                        answer = (answerPrev + (double)nums2[index2])/2;
                    }
                    else
                        answer = ((double)nums2[index2 + remain - 2] + (double)nums2[index2 + remain - 1]) / 2;
                }
            }
            if(index2 == nums2.size())
            {
                if(totalNum % 2 == 1)
                    answer = nums1[index1 + remain - 1];
                
                else
                {
                    if(remain == 1)
                    {
                        answerPrev = answer;
                        answer = (answerPrev + (double)nums1[index1])/2;
                    }
                    else
                        answer = ((double)nums1[index1 + remain - 2] + (double)nums1[index1 + remain - 1]) / 2;
                }
            }
        }
        else
        {
            if(totalNum % 2 == 0)
            {
                answer = (answer + answerPrev) / 2;
            }
        }
        return answer;
    }
};