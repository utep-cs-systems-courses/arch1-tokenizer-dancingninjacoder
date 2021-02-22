#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"

int space_char(char c){
  if((c == '\t' || c == ' ') && c != 0){
    return 1;
  }
  return 0;
 }

int non_space_char(char c){
   if(c == '\t' || c == ' '){
    return 0;
   }
   return 1;
 }
  
char *word_start(char *str){
  if(sizeof(str) == 0)
    return '\0';
    
  for(int i= 0; i < sizeof(str); i++){
      if(non_space_char(str[i]) == 1){
	return &str[i];
      }
  }
  return '\0'; 
}

char *word_terminator(char *str){
  if(sizeof(str) == 0)
    return '\0';

  for(int i= 0; i < sizeof(str); i++){
    if(space_char(str[i]) == 1){
	return &str[i];
      }
   }
    return '\0';  
 }

int count_words(char *str){

  int count = 0;
  int temp = 0;

  for( ; *str != '\0'; str++){
    if(non_space_char(*str) == 1){
      temp = 1;
    }
    if((space_char(*str) == 1) &&(temp == 1)){
       count++;
       temp = 0;
    }
  }
  if(temp == 1){
    count++;
  }
  return count; 

}

  int main(){
    char str[] = "  hello";
    char *ptr = word_start(str);
    printf("\n%p\n", ptr);
    /* char *ptr = word_start(str); */
    printf("%p", &str[2]);

    char strend[] = "hello ";
    char *ptrt = word_terminator(strend);
    printf("\n%p\n", ptrt);
    printf("%p", &strend[5]);

    printf("%i", count_words("hello world"));
  }
