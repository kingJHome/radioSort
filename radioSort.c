#include "radioSort.h"

//设置属性结点
void setMyAttribute(Attribute *attr,char *name,char *val){
	attr->name = name;
	attr->value = val;
}

//设置属性结点
void setMyAttrNode(AttrNode *atnode,Attribute attr){
	size_t newSize = (atnode->length+1) * sizeof(Attribute);
	void *nptr = realloc(atnode->data, newSize);
	
	if( nptr ){
		atnode->data[atnode->length++] = attr;
	}
}

//访问属性结点
void visitAttribute(AttrNode *atnode,char *attName,void *setAttr,setData _setData){
}

//设置keyNode
void setKeyNode(Wrap *target,int len){
	target->data = (KeyNode*)malloc(len * sizeof(KeyNode));
	
	if( target->data ){
		target->lenData = len;
	}
}

//设置keyArr
void setKeyArray(Wrap *target,char *keys){
	int slen = 0;
	size_t klen = strlen(keys);
	
	for(size_t i = 0; i < klen; ++i){
		if(keys[i]==' ' || keys[i]=='\n'){
			slen++;
		}
	}
	target->keyArr = (char**)malloc(slen * sizeof(char*));
	if( target->keyArr ){
		char *sepe = NULL;
		
		target->lenKey = slen;
		slen = 0;//做为统计序号
		while( sepe = strsep(&keys," \n") ){
			if( strlen(sepe) ){
				target->keyArr[slen++] = sepe;
			}
		}
	}
}

//使用属性列表初始化包裹数组
void initMyWrap(Wrap *target,AttrNode *atnode){
	for(int i = 0; i < atnode->length; ++i){
		if( strcmp(atnode->data[i].name, "radio") ){
			int nlen = atoi(atnode->data[i].value);
			setKeyNode(target, nlen);
		}else if( strcmp(atnode->data[i].name, "keynum") ){
			target->keyLayer = atoi(atnode->data[i].value);
		}else if( strcmp(atnode->data[i].name, "data") ){
			setKeyArray(target, atnode->data[i].value);
		}
	}
}

//关键字分发
void assignKey(){
}

//搜集新序列
void collection(){
}
