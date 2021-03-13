#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"

//checks if char c is a tab or space and not zero terminator 
int space_char(char c){
  if(c=='\t' || c == ' ' || c == '\n'){
    return 1;
  }
  return 0;
}
//check if char c is not a tab or space and not zero terminator
int non_space_char(char c){
  if(c=='\t' || c==' ' || c == '\n'){
    return 0;
  }
  return 1;
}
//accesses the start of the string 
char *word_start(char *str){

  if(sizeof(str)==0){
    return '\0';
  }
  
  for(int i=0; i<sizeof(str); i++){
    
    if(non_space_char(str[i])==1){
      return &str[i]; //returns address of str 
    }
  }
  return '\0';
}
//accesses the first space of string 
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
//counts words in the string 
int count_words(char *str){
  
  if(sizeof(str)==0){
    return 0; 
  }
  int count = 0;
  int temp = 0;
  for( ; *str != '\0';str++){
    if(non_space_char(*str)==1){
      temp = 1;//holds 1 only when the first char of the string is found 
    }

    if((space_char(*str)==1)&&(temp==1)){
      count++;
      temp = 0;//resets to 0  once the first word of the string is found
    }
  }
  //checks strings that do not have a space after a word ends
  if(temp == 1){
    count++;
  }
  return count;
  /*
  int count = 0;
  while(*str != '\0'){
    str = word_start(str);
    str = word_terminator(str);
    count++;
  }
  return count; */ 
}

char *copy_str(char *inStr, short len){

  char *cStr = (char*)malloc(sizeof(char)*(len+1)); //allocates memory for the copied string

   int i=0;
   while(i < len){
     cStr[i] = inStr[i]; //inserts whats in the string into new copy string
     i++;
   }
    cStr[len] = '\0'; //sets end of string to zero terminator 
    return cStr;
}

char **tokenize(char* str){

  int length = count_words(str); //stores the amount of words in string 
  char **char_array;
  char_array = (char**)malloc(sizeof(char*)*(length+1)); //allocates memory 
  int i = 0;
  while(i<length){
    str = word_start(str); //stores first char of string
    int stringLen = word_terminator(str) - str; //stores the length of the word in string 
    char_array[i] = copy_str(str, stringLen); 
    str = word_terminator(str); //sets str in blank 
    i++;
  }
  char_array[i] = NULL;
  return char_array;
}

void print_tokens(char **tokens){

  int i;
  for(i=0; tokens[i] != NULL; i++){
    printf("%s\n",tokens[i]);
  }
  /* while(*tokens != NULL){
    printf("<%s>", *tokens);
    tokens++;
  }*/
  
} 

void free_tokens(char **tokens){
  int i=0;
  while(tokens[i] != NULL){
    free(tokens[i]);
    i++;
  }
  free(tokens);
}
   
