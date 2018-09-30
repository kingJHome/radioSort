#ifndef _MYRADIO__SORT
#define _MYRADIO__SORT

#include <stdlib.h>
#include <string.h>

typedef struct keyNode{
	char *key;
	struct keyNode *next;
}KeyNode;

typedef struct{
	KeyNode *data;
	char **keyArr;
	int lenData;
	int lenKey;
	int keyLayer;
}Wrap;

//设置keyNode
void setKeyNode(Wrap *target,int len);

//设置keyArr
void setKeyArray(Wrap *target,char *keys);

//基数排序
void radioSort(Wrap *tar);

//比较关键字
int cmpKeyWord(char *prev,char *next,int pos,int len);

//关键字分发
void assignKey(int curlayer,int layer,KeyNode *data,char **keyArr,int klen);

//搜集新序列
void collection(KeyNode *data,int knLen,char **keyArr);

#endif
