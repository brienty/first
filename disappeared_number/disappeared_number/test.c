#define _CRT_SECURE_NO_WARNINGS 1
/*
	接口型题目
	数组nums包含从0到n的所有整数，但其中缺了一个。
	请编写代码找出那个缺失的整数。
	你有办法在O(n)时间内完成吗？
	示例 1：
	输入：[3,0,1]
	输出：2
	示例 2：
	输入：[9,6,4,2,3,5,7,0,1]
	输出：8
*/

/*
*   思路：
    因为要求在O(n)的时间内完成，所以：
    1. 使用排序，目前所学->冒泡排序（O(n^2)）和qsort（(nlogn)）都不行
    2. 映射，将一个数组初始化为负数，把对应的数字放入对应的数组下标所对应的数组中，然后出现负数则为缺少的数字
       要使用数组开辟空间，有空间复杂度，不行
    3. 使用异或操作符，符合
    4. 等差数列，符合
*/

//第一种方法，使用异或操作符，同样的数字异或以后为0，不论顺序
int missingNumber(int* nums, int numsSize) {
    int i = 0;
    int temp = 0;

    //先和数组异或
    for (i = 0; i < numsSize; i++)
    {
        temp ^= nums[i];
    }

    //再和0~n的数字异或，就得到缺少的数字
    for (i = 0; i <= numsSize; i++)
    {
        temp ^= i;
    }

    return temp;
}

//第二种方法，使用等差数列
int missingNumber(int* nums, int numsSize) {
    int i = 0;
    //等差数列求和
    int Sn = ((0 + (numsSize)) * (numsSize + 1)) / 2;
    //减去数组中的每个值，即剩下的就是缺少值
    for (i = 0; i < numsSize; i++)
    {
        Sn -= nums[i];
    }
    return Sn;
}