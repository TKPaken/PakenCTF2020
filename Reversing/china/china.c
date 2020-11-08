#include<stdio.h>
#include<stdlib.h>

void output(char* t){
	char s[]={99,81,80,18,119,90,84,82,24,80,65,24,13,25,69,83,90,83,91,118,108,127,73,123,95,8,91,87,66,83,106,103,93,84,6,81,89,93,80,64,110,98,93,80,8,75,87,85,74};
	for(int i=0;i<sizeof(s);i++){
		s[i]^=t[i%12];
	}
	for(int i=0;i<sizeof(s);i++)printf("%c",s[i]);
	printf("\n");
	fflush(stdout);
}
int main(){
	long long A[]={389,484,8,16,4},B[]={56563,5684,20,48,89};
	long long C;scanf("%lld",&C);
	for(int i=0;i<5;i++){
		if(C%B[i]!=A[i]){
			printf("Wrong!!\n");return 0;
		}
	}
	if(C>1000000000000){
		printf("It's too big, isn't it?\n");return 0;
	}
	char* buffer=malloc(12);
	sprintf(buffer,"%lld",C);
	output(buffer);
}
