#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"
#include "history.h"
#include "tokenizer.c"
#include "history.c"

#define MAXINPUT 100
int main(){
  char userInput[MAXINPUT]; //set max input for char in a string
  char **tokStr; //pointer of pointer for new strings 
  List *listHist = init_history(); //creates linked list
  printf("Hello! Let's tokenize some strings.");
  printf("Choose an option:\n");
  printf(" ($) for entering a string.");
  printf(" (#) for printing your history.");
  printf(" (*) for quit program\n");
  printf("> ");
  fgets(userInput, MAXINPUT, stdin); //gets user input
 
  while(*userInput != '*'){ 
    printf("> ");
    fgets(userInput, MAXINPUT, stdin);
    if(*userInput != '*' && *userInput != '#'){
      tokStr = tokenize(userInput);//will tokenize user input
      printf("your string tokenized is:\n");
      print_tokens(tokStr);//print tokens
      free_tokens(tokStr);//frees tokens
      printf("...now adding to history...\n");
      printf("Enter a new comand\n");
      //creates a node inisde the link list with the user string 
      add_history(listHist, copy_str(userInput, sizeof(userInput)));
    }
    if(*userInput =='#'){
      printf("...now printing history:\n");
      print_history(listHist);
    }
    if(*userInput == '*'){ //quits program
      printf("Goodbye.\n");
      break;
    } 
  }
  return 0;
}
 
