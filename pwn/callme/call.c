#include<stdio.h>
#include<stdlib.h>
void callme(){
	system("/bin/cat flag.txt");
}
int main(){
	printf("Let's input something : ");fflush(stdout);
	char buf[16];
	fgets(buf,256,stdin);
}