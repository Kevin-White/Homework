#include <stdio.h>
#include <pthread.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

char *wordList[25];
int turn = 0;

bool isVowel(char arg){
	if(tolower(arg) == 'a' || tolower(arg) == 'e' || tolower(arg) == 'i' || tolower(arg) == 'o' || tolower(arg) == 'u'){
		return true;
	}else{
		return false;
	}
}


void vowel(int s){
	int j;
	for(j = 0; j < s-1; j++){
		while(j != turn/2);
		if(isVowel(wordList[j][0])){
			printf("vow: %s\n", wordList[j]);
		}
		turn++;
	}
}

void consonant(int s){
        int k;
        for(k = 0; k < s-1; k++){
                while(k != turn/2);
                if(!isVowel(wordList[k][0])){
                        printf("cons: %s\n", wordList[k]);
                }
                turn++;
        }
}

int main(int argc, char *argv[]){
	int size = argc;
	
	pthread_t vow;
	pthread_t con;
	
	int i;
	for(i = 1; i < size; i++){
		wordList[i-1] = argv[i];
	}
	pthread_create(&vow, NULL, vowel, size);
	pthread_create(&con, NULL, consonant, size);
	pthread_join(vow, NULL);
	pthread_join(con, NULL);
}
