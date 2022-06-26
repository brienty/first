#define _CRT_SECURE_NO_WARNINGS 1

/*
给你一个升序排列的数组nums，请你原地删除重复出现的元素，使每个元素只出现一次 ，返回删除后数组的新长度。
元素的相对顺序应该保持一致 。
由于在某些语言中不能改变数组的长度，所以必须将结果放在数组nums的第一部分。
更规范地说，如果在删除重复项之后有k个元素，那么nums的前k个元素应该保存最终结果。
将最终结果插入 nums的前k个位置后返回k。
不要使用额外的空间，你必须在原地修改输入数组并在使用O(1)额外空间的条件下完成。
示例 1：

输入：nums = [1,1,2]
输出：2, nums = [1,2,_]
解释：函数应该返回新的长度 2 ，并且原数组 nums 的前两个元素被修改为 1, 2 。
不需要考虑数组中超出新长度后面的元素。
示例 2：

输入：nums = [0,0,1,1,1,2,2,3,3,4]
输出：5, nums = [0,1,2,3,4]
解释：函数应该返回新的长度 5 ， 并且原数组 nums 的前五个元素被修改为 0, 1, 2, 3, 4 。
不需要考虑数组中超出新长度后面的元素。
 
提示：
0<=nums.length<=3*104
-104<=nums[i]<=104
nums已按升序排列
链接：https://leetcode-cn.com/problems/remove-duplicates-from-sorted-array
*/

//双指针解题
int removeDuplicates(int* nums, int numsSize) {
    int dest = 0;
    int src = 1;
    while (src < numsSize)
    {
        //如果src等于src-1，则src一直往后走到与src-1不同，跳过区间里相同的元素
        if (nums[src - 1] == nums[src])
        {
            src++;
        }
        //当src与src不相等时，把src-1给dest
        else
        {
            nums[dest] = nums[src - 1];
            dest++;
            src++;
        }
    }

    //最后一个元素与src-1无论是否相等都需要直接给dest
    nums[dest] = nums[numsSize - 1];
    dest++;

    //返回长度
    return dest;
}
