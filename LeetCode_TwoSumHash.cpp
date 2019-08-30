class Solution {
public
    vectorint twoSum(vectorint& nums, int target) {
        vectorint answer;
        mapint, int hashTable;
        for(int i = 0; i  nums.size(); i++)
        {
            int curr = target - nums[i];
            if(hashTable.find(curr) != hashTable.end())
            {
                answer.push_back(hashTable[curr]);
                answer.push_back(i);
                return answer;
            }
            else
            {
                hashTable[nums[i]] = i;
            }
        }
        return answer;
    }
};