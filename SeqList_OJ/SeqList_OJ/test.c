#define _CRT_SECURE_NO_WARNINGS 1

/*
移除元素（顺序表删除指定元素的变形题）
	给你一个数组 nums 和一个值 val，你需要 原地 移除所有数值等于 val 的元素，并返回移除后数组的新长度。
不要使用额外的数组空间，你必须仅使用 O(1) 额外空间并 原地 修改输入数组。
元素的顺序可以改变。你不需要考虑数组中超出新长度后面的元素。
链接：https://leetcode-cn.com/problems/remove-element
*/

//采用双指针方法最为简单，时间复杂度是O(n)，空间复杂度是O(1)
//方法来源于创建数组（空间复杂度是O(n)），但是该题要求空间复杂度是O(1)
int removeElement(int* nums, int numsSize, int val) {
    int dest = 0;
    int src = 0;
    
    //利用双指针将同一个数组内容改变
    while (src < numsSize)
    {
        //当nums[src]不等于val时，把src里的值给dest
        if (nums[src] != val)
        {
            nums[dest] = nums[src];
            ++src;
            ++dest;
        }
        //当nums[src]等于val时，直接跳过
        else
        {
            src++;
        }
    }

    //返回长度，而dest就是此时的长度
    return dest;
}

//暴力解法，直接遍历
int removeElement(int* nums, int numsSize, int val) {
    
    int newSize = 0;
    
    //遍历数组的同时，把不等于val的数放回数组，等于val的数直接覆盖
    for (int i = 0; i < numsSize; i++)
    {
        if (nums[i] != val)
        {
            nums[newSize] = nums[i];
            ++newSize;
        }
    }
    return newSize;
}