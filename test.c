#include <stdio.h>
#include <string.h>
#include "radioSort.h"

void getTxtData(char *filename,Wrap *awp);
void visiteWrap(Wrap wap,char *tips);

int main(int argc,char *argv[]){
	Wrap awp = {NULL,NULL,0,0};

	getTxtData("data.txt", &awp);
	visiteWrap(awp,"基数排序\ndefore sort:");
	radioSort(&awp);
	visiteWrap(awp,"after sort:");

	return 0;
}

void getTxtData(char *filename,Wrap *awp){
	FILE *fp = fopen(filename, "r");

	if( fp ){
		char *read = NULL,
			 seperator[] = " \n";
		size_t getlen = 0;

		while( getline( &read, &getlen, fp) != -1 ){
			getlen = 0;
			char *data = strchr(read,':') + 1,
				 *name = strndup(read, data-read-1);
			
			if( strcmp(name,"radio")==0 ){
				int len = atoi(data);
				setKeyNode(awp, len);
			}else if( strcmp(name,"keynum")==0 ){
				awp->keyLayer = atoi(data);
			}else if( strcmp(name,"data")==0 ){
				setKeyArray(awp, data);
			}
		}
	}
}

void visiteWrap(Wrap wap,char *tips){
	printf("%s", tips);
	for(int i = 0; i < wap.lenKey; ++i){
		printf("%-5s", wap.keyArr[i]);
	}
	printf("\n");
}
