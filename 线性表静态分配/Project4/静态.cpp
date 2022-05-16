#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#define MaxSize 10 //定义最大长度

#define ElementType  int
typedef struct {
	int data[MaxSize];//静态数组存放数据元素
	int length;//顺序表当前长度
}Sqlist;

//基本操作初始化一个顺序表
void InitList(Sqlist &L){
	for (int i = 0; i < MaxSize; i++)
		L.data[i] = 0;
	L.length = 0;
}

//void ListInsert(Sqlist& L, int i, int e) {
//	for (int j = L.length; j >= i; j--)//将第i个元素以及之后的元素后移
//		L.data[j] = L.data[j - 1];
//	L.data[i - 1] = e;//在 位置i处放e
//	L.length++;//长度加一
//}
// 
//插入
bool ListInsert(Sqlist& L, int i, int e) {
	if (i<1 || i>L.length + 1)//判断i 的范围是否有效
		return false;
	if (L.length >= MaxSize)//空间已满 不能插入 
		return false;
	for (int j = L.length; j >= i; j--)
		L.data[j] = L.data[j - 1];
	L.data[i-1] = e;//在 位置i处放e
	L.length++;//长度加一
	return true;
}
//删除
bool ListDelete(Sqlist& L, int i, int & e) {
	if (i<1 || i>L.length)//判断i是否有效
		return false;
	e = L.data[i-1];//将被删除的值赋给e
	for (int j = i; j < L.length; j++)//第i个元素后的元素前移
		L.data[j-1] = L.data[j];
	L.length--;//线性表长度减1
	return true;
}

//顺序表 按位查找
int GetElem(Sqlist L, int i) {
	return L.data[i - 1];

}
//顺序表 按值查找
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


	printf("插入后\n");
	printf("length=%d\n", L.length);
	
	for (int i = 0; i < L.length; i++)
		printf("data[%d]=%d\n", i, L.data[i]);

	int e = -1;
	if (ListDelete(L, 3, e))
		printf("成功删除第3位元素，  删除元素值为=%d\n", e);
	else
		printf("序位i不合法，删除失败\n");
	printf("删除后\n");
	printf("length=%d\n", L.length);


	for (int i = 0; i < L.length; i++)
		printf("data[%d]=%d\n", i, L.data[i]);
	printf("按值查找，为第%d个数\n", GetElem(L, 1));
	printf("按位查找 ,为第%d个数", LocalElem(L, 4));
	return 0;
}