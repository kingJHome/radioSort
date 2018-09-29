#ifndef _MYRADIO_SORT
#define _MYRADIO_SORT

#include <stdlib.h>
#include <string.h>

typedef void (*setData)(void *data);

typedef struct{
	char *name;
	char *value;
}Attribute;

typedef struct{
	Attribute *data;
	int length;
}AttrNode;

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

//设置属性结点
void setMyAttribute(Attribute *attr,char *name,char *val);

//设置属性结点
void setMyAttrNode(AttrNode *atnode,Attribute attr);

//访问属性结点
void visitAttribute(AttrNode *atnode,char *attName,void *setAttr,setData _setData);

//设置keyNode
void setKeyNode(Wrap *target,int len);

//设置keyArr
void setKeyArray(Wrap *target,char *keys);

//使用属性列表初始化包裹数组
void initMyWrap(Wrap *target,AttrNode *atnode);

//关键字分发
void assignKey();

//搜集新序列
void collection();

#endif
