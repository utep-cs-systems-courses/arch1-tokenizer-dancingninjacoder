#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"

int space_char(char c){
  if((c=='\t' || c == ' ') && c !=0){
    return 1;
  }
   return 0;
}

int non_space_char(char c){
 
  if((c=='\t' || c== ' ') && c!=0){
    return 0;
  }
  return 1;
}

char *word_start(char *str){

  if(sizeof(str)==0){
    return '\0';
  }

  for(int i=0; i<sizeof(str); i++){

    if(non_space_char(str[i])==1){
      return &str[i];
    }
  }
  return '\0';
}

char *word_terminator(char *str){

  if(sizeof(str)==0){
    return '\0';
  }
  for(int i=0; i<sizeof(str); i++){
    if(space_char(str[i])){
      return &str[i];
    }
  }
  return '\0';
}

int count_words(char *str){
  
  if(sizeof(str)==0){
    return 0; 
  }
  int count = 0;
  int temp = 0;
  for( ; *str != '\0';str++){
    if(non_space_char(*str)==1){
      temp = 1;
    }

    if((space_char(*str)==1)&&(temp==1)){
      count++;
      temp = 0;
    }
  }
  if(temp == 1){
    count++;
  }
  return count;
}

char *copy_str(char *inStr, short len){

  char *cStr = (char*)malloc(sizeof(char)*(len+1));

   int i=0;
   while(i < len){
     cStr[i] = inStr[i];
     i++;
   }
    cStr[len] = '\0';
    return cStr;
}

char **tokenize(char* str){

  int length = count_words(str);
  printf("\n>LENGTH %i\n", length);
  char **char_array;
  char_array = (char**)malloc(sizeof(char*)*(length+1));
  int i = 0;
  while(i<length){
    str = word_start(str);
    int stringLen = word_terminator(str) - str;
    char_array[i] = copy_str(str, stringLen);
    str = word_terminator(str);
    i++;
  }
  char_array[i] = NULL;
  return char_array;
}

void print_tokens(char **tokens){
   
  while(*tokens != NULL){
    printf("<%s>", *tokens);
    tokens++;
  }
  
} 

void free_tokens(char **tokens){
  int i=0;
  while(tokens[i] != NULL){
    free(tokens[i]);
    i++;
  }
  free(tokens);
}
    

