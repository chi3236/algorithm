

int singleNumber(int* nums, int numsSize){
    int answer = nums[0];
    for(int i = 1; i < numsSize; i++)
    {
        answer = answer ^ nums[i];
    }
    return answer;
}
