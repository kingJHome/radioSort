#include <stdio.h>
#include "radioSort.h"

void getTxtData(char *filename,void *data);
void visiteWrap(Wrap wap);

int main(int argc,char *argv[]){
	AttrNode atnode = {NULL,0};
	Wrap awp = {NULL,NULL,0,0};

	getTxtData("data.txt", &atnode);
	initMyWrap(&awp, &atnode);
	visiteWrap(awp);

	return 0;
}

void getTxtData(char *filename,void *data){
	FILE *fp = fopen(filename, "r");

	if( fp ){
		char *read = NULL,
			 seperator[] = " \n";
		size_t getlen = 0;

		while( getline( &read, &getlen, fp) != -1 ){
			getlen = 0;
			char *data = strchr(read,':') + 1,
				 *name = strndup(read, data-read-1);
			AttrNode *adata = (AttrNode*)data;
			Attribute *anew = (Attribute*)malloc(sizeof(Attribute));
			
			if( anew ){
				setMyAttribute(anew, name, data);
				setMyAttrNode(adata, *anew);
			}
		}
	}
}

void visiteWrap(Wrap wap){
	for(int i = 0; i < wap.lenKey; ++i){
		printf("%-5s", wap.keyArr[i]);
	}
	printf("\n");
}
