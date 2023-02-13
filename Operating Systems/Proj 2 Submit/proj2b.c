#include <stdio.h>
#include <pthread.h>

int fibList[47];

void five(int arg){
	int i;
	for(i = 0; i < arg; i++){
		if(i == 0){
			fibList[i] = 0;
		}else if(i == 1){
			fibList[i] = 1;
		}else{
			fibList[i] = fibList[i-1] + fibList[i-2];
		}
	}
	pthread_exit(0);
}

int main(int argc, char *argv[]){
	pthread_t helper;
	int fibNum = atoi(argv[1]);
	if(fibNum > 47){
		fibNum = 47;
	}
	pthread_create(&helper, NULL, five, fibNum);
	pthread_join(helper, NULL);
	
	int i;
	for(i = 0; i < fibNum; i++){
		printf("Fib %d:\t%d\n", i+1, fibList[i]);
	}
}
