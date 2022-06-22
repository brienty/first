#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <assert.h>



char* My_strstr(const char* str, const char* substr)
{
	assert(str && substr);//�п�
	
	//���������ַ����ǿ��ַ���ʱ�޷����ң�ֱ�ӷ���str
	if (*substr == '\0')
	{
		return (char*)str;//const���Σ�����char*ָ����Ҫǿ������ת��
	}
	
	//Ϊ�����ҵ���ʼλ�ã���s1��s2�������岻��
	const char* s1 = str;
	const char* s2 = substr;

	//��¼��ǰ�����ҵ���λ��
	const char* cur = str;//const������str������Ҫһ��

	//��ʼ����
	while (*cur)//��cur�������ַ�����'\0'˵���������ҵ���
	{
		s1 = cur;//ʹs1�ص���ǰʧ���ַ�����һ���ַ�
		s2 = substr;//ʹs2�ص���ʼλ��
		while (*s1 && *s1 == *s2 && *s2)//���*s1����'\0'˵���������ַ����Ѿ��������ˣ����������if�ж��Ƿ��ҵ���
		{
			s1++;
			s2++;
		}
		if (*s2 == '\0')//*s2����'\0'˵���ҵ��ˣ��������ַ����е����ַ�����ĵ�һ���ַ��ĵ�ַ
		{
			return (char*)cur;//const������Ҫǿ������ת��
		}
		cur++;//˵����һ��λ�ò����������ҵ��ִ���λ�ã�����һ��λ�ÿ�ʼ����
	}
	return NULL;//�Ҳ������ؿ�ָ��

}

int main()
{
	char arr1[20] = "acdfacbbbcg";
	char arr2[10] = "bbc";

	printf("%s\n", My_strstr(arr1, arr2));

	return 0;
}