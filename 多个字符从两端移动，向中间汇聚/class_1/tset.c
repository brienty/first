//����ַ��������ƶ������м���
//��ΪҪ�ı��ַ������Կ���ʹ�������±��������ַ�
#include <stdio.h>
#include <windows.h>
#include <string.h>
#include <stdlib.h>
int main()
{
	char arr[] = "hello bit!!!!!!!!";
	//�ַ����а������ص�\0
	//[a b c \0]
	 //0 1 2  3
	char arr1[] = "hello bit!!!!!!!!";
	char arr2[] = "#################";
	int left = 0;
	int right = strlen(arr1) - 1;//������ͷ�ļ�
	//���Ҫʹ��sizeof()�������˴�Ӧ��Ϊsizeof(arr)-2����Ϊsizeof()�������ص�\0��strlen()����������
	while (left <= right)
	{
		arr2[left] = arr1[left];//arr1��ֵ��arr2
		arr2[right] = arr1[right];//ͬ��
		printf("%s\n", arr2);
		Sleep(1000);//˯�ߺ���-��λ�Ǻ��룬��Ϣָ��ʱ���ٴ�ӡ��ע��SΪ��д��������ͷ�ļ�
		system("cls");//�ú�������ִ��ϵͳ���������ͷ�ļ���clsΪ��������
		left++;
		right--;
	}
	printf("%s\n", arr2);//��ʾ���Ľ��

	return 0;
}