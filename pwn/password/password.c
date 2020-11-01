#include<stdio.h>
#include<stdlib.h>
int main(){
	system("cat /dev/urandom | tr -dc \"[:alnum:]\" | fold -w 16 | head -n 1 > password.txt");
	FILE *fp=fopen("password.txt","r");
	char password[20];
	fgets(password,16,fp);
	
	printf("What's your name?\n");
	fflush(stdout);
	char* name=malloc(20);
	fgets(name,16,stdin);

	printf("Hello,");
	printf(name);
	printf("\n");
	fflush(stdout);

	printf("What is the password?\n");fflush(stdout);
	char* input=malloc(20);
	fgets(input,16,stdin);

	if(strcmp(input,password)==0){
		printf("Congraturations!\n");fflush(stdout);
		system("/bin/cat flag.txt");
	}
}
