#include "radioSort.h"

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

//基数排序
void radioSort(Wrap *tar){
	for(int i = tar->keyLayer-1; i >= 0; --i){
		assignKey(i, tar->keyLayer, tar->data, tar->keyArr, tar->lenKey);
		collection(tar->data, tar->lenData, tar->keyArr);
	}
}

//比较关键字
int cmpKeyWord(char *prev,char *next,int pos,int len){
	int result = 0;

	if( pos == 0 ){
		result = prev[pos+1] - next[pos+1];
	}else if( pos == len - 1 ){
		result = prev[pos-1] - next[pos-1];
	}

	return result;
}

//关键字分发
void assignKey(int curLayer,int layer,KeyNode *data,char **keyArr,int klen){
	for(int i = 0; i < klen; ++i){
		char indexChar = keyArr[i][curLayer];
		int index = atoi(&indexChar);
		KeyNode *curNode = (KeyNode*)malloc(sizeof(KeyNode));

		if( curNode ){
			curNode->next = NULL;
			curNode->key = keyArr[i];

			if( !data[index].next ){
				data[index].next = curNode;
			}else{//插入到适当位置
				KeyNode *prev = data + index,
						*cur = prev->next;

				for( ; cur && cmpKeyWord(curNode->key,cur->key,curLayer,layer); prev = cur,cur = cur->next);
				curNode->next = cur;
				prev->next = curNode;
			}
		}
	}
}

//搜集新序列
void collection(KeyNode *data,int knLen,char **keyArr){
	int curPos = 0;

	for(int i = 0; i < knLen; ++i){
		KeyNode *temp = data[i].next,*frep = NULL;
		while( temp ){
			frep = temp;
			keyArr[curPos++] = temp->key;
			temp = temp->next;
			free(frep);
		}
		data[i].next = NULL;
	}
}
