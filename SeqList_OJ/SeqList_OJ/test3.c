#define _CRT_SECURE_NO_WARNINGS 1
/*
	合并两个有序数组
	链接：https://leetcode-cn.com/problems/merge-sorted-array
*/

/*
    思路：本题采用三指针做法，先使用dest标记第一个数组中扩展以后的最后一个元素
    再使用i标记第一个数组未扩展之前的最后一个元素
    使用j标记第二个数组的最后一个元素
    让i和j比较，把大的放到dest中
    这里需要注意一个问题，如果第一个数组中所有的元素大于第二个数组所有元素的值
    那么跳出循环后需要把第二个数组单独循环放入第一个数组中

*/
//注：这里的nums1Size和nums2Size多余没用
void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n) {
    int i = m - 1;
    int j = n - 1;
    int dest = m + n - 1;
    while (i >= 0 && j >= 0)
    {
        //当i大于j时，将i赋值给dest
        if (nums1[i] > nums2[j])
        {
            nums1[dest--] = nums1[i--];
        }
        //当i小于j时，将j赋值给dest
        else
        {
            nums1[dest--] = nums2[j--];
        }
    }

    //当出现nums1数组中的所有元素大于nums2数组的全部的元素时
    while (j >= 0)
    {
        nums1[dest--] = nums2[j--];
    }
}