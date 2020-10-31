#include<stdio.h>
#include<stdlib.h>

int main(){
	int money=998244353;
	int price=100;
	printf("Welcome to Paken store!\n");
	printf("Now, you have %d yen.\n",money);
	printf("This apple's price is %d yen.\n",price);
	printf("So, how many apples do you want to buy?\n");
	fflush(stdout);

	int input;
	scanf("%d",&input);
	
	if(input<=0){
		printf("Huh?\n");fflush(stdout);
		goto Siberia;
	}
	printf("Thanks!\n");
	fflush(stdout);

	money-=price*input;

	if(money>=1000000007){
		system("/bin/cat flag.txt");
	}
Siberia:;
}