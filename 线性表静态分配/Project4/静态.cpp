#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#define MaxSize 10 //������󳤶�

#define ElementType  int
typedef struct {
	int data[MaxSize];//��̬����������Ԫ��
	int length;//˳���ǰ����
}Sqlist;

//����������ʼ��һ��˳���
void InitList(Sqlist &L){
	for (int i = 0; i < MaxSize; i++)
		L.data[i] = 0;
	L.length = 0;
}

//void ListInsert(Sqlist& L, int i, int e) {
//	for (int j = L.length; j >= i; j--)//����i��Ԫ���Լ�֮���Ԫ�غ���
//		L.data[j] = L.data[j - 1];
//	L.data[i - 1] = e;//�� λ��i����e
//	L.length++;//���ȼ�һ
//}
// 
//����
bool ListInsert(Sqlist& L, int i, int e) {
	if (i<1 || i>L.length + 1)//�ж�i �ķ�Χ�Ƿ���Ч
		return false;
	if (L.length >= MaxSize)//�ռ����� ���ܲ��� 
		return false;
	for (int j = L.length; j >= i; j--)
		L.data[j] = L.data[j - 1];
	L.data[i-1] = e;//�� λ��i����e
	L.length++;//���ȼ�һ
	return true;
}
//ɾ��
bool ListDelete(Sqlist& L, int i, int & e) {
	if (i<1 || i>L.length)//�ж�i�Ƿ���Ч
		return false;
	e = L.data[i-1];//����ɾ����ֵ����e
	for (int j = i; j < L.length; j++)//��i��Ԫ�غ��Ԫ��ǰ��
		L.data[j-1] = L.data[j];
	L.length--;//���Ա��ȼ�1
	return true;
}

//˳��� ��λ����
int GetElem(Sqlist L, int i) {
	return L.data[i - 1];

}
//˳��� ��ֵ����
int LocalElem(Sqlist L, int e) {
	for (int i = 0; i < L.length; i++)
		if (L.data[i] == e)
			return i + 1;
}

int main() {
	Sqlist L;
	InitList(L);

	for (int i = 0; i < L.length; i++)
		printf("data[%d]=%d\n", i, L.data[i]);
	ListInsert(L, 1, 1);
	ListInsert(L, 2, 2);
	ListInsert(L, 3, 3);
	ListInsert(L, 4, 4);
	ListInsert(L, 5, 5);
	ListInsert(L, 6, 6);


	printf("�����\n");
	printf("length=%d\n", L.length);
	
	for (int i = 0; i < L.length; i++)
		printf("data[%d]=%d\n", i, L.data[i]);

	int e = -1;
	if (ListDelete(L, 3, e))
		printf("�ɹ�ɾ����3λԪ�أ�  ɾ��Ԫ��ֵΪ=%d\n", e);
	else
		printf("��λi���Ϸ���ɾ��ʧ��\n");
	printf("ɾ����\n");
	printf("length=%d\n", L.length);


	for (int i = 0; i < L.length; i++)
		printf("data[%d]=%d\n", i, L.data[i]);
	printf("��ֵ���ң�Ϊ��%d����\n", GetElem(L, 1));
	printf("��λ���� ,Ϊ��%d����", LocalElem(L, 4));
	return 0;
}