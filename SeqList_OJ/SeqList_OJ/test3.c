#define _CRT_SECURE_NO_WARNINGS 1
/*
	�ϲ�������������
	���ӣ�https://leetcode-cn.com/problems/merge-sorted-array
*/

/*
    ˼·�����������ָ����������ʹ��dest��ǵ�һ����������չ�Ժ�����һ��Ԫ��
    ��ʹ��i��ǵ�һ������δ��չ֮ǰ�����һ��Ԫ��
    ʹ��j��ǵڶ�����������һ��Ԫ��
    ��i��j�Ƚϣ��Ѵ�ķŵ�dest��
    ������Ҫע��һ�����⣬�����һ�����������е�Ԫ�ش��ڵڶ�����������Ԫ�ص�ֵ
    ��ô����ѭ������Ҫ�ѵڶ������鵥��ѭ�������һ��������

*/
//ע�������nums1Size��nums2Size����û��
void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n) {
    int i = m - 1;
    int j = n - 1;
    int dest = m + n - 1;
    while (i >= 0 && j >= 0)
    {
        //��i����jʱ����i��ֵ��dest
        if (nums1[i] > nums2[j])
        {
            nums1[dest--] = nums1[i--];
        }
        //��iС��jʱ����j��ֵ��dest
        else
        {
            nums1[dest--] = nums2[j--];
        }
    }

    //������nums1�����е�����Ԫ�ش���nums2�����ȫ����Ԫ��ʱ
    while (j >= 0)
    {
        nums1[dest--] = nums2[j--];
    }
}