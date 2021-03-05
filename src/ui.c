#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"
#include "history.h"
#include "tokenizer.c"
#include "history.c"

#define MAXINPUT 100

int main(){


  printf("Welcome to tokenizer:\n");
  printf("Enter a string to tokenize:\n");
  List *listHist = init_history();
  printf("> ");
  char userFirstChoice[MAXINPUT];
  fgets(userFirstChoice, MAXINPUT, stdin);
  add_history(listHist, userFirstChoice);
  char **tok = tokenize(userFirstChoice);
  print_tokens(tok);
  
  
  printf("Choose a menu option:\n");
  printf("1. Enter another string to tokenize\n");
  printf("2. Print histroy\n");
  printf("3. Exit\n");
  int userChoice;
  scanf("%d", &userChoice);
  while(userChoice != 3){
    if(userChoice == 1){
      printf("> ");
      char userStr[100];
      scanf(" %[^\n]", userStr);
      printf("%s\n", userStr);
      tok = tokenize(userStr);
      printf("Your tokenized string is:\n");
      print_tokens(tok);

      printf("...now adding to history");
    }
    if(userChoice == 2){
      print_history(listHist);
    }
    if(userChoice == 3){
      exit(0);
    }
    printf("Select menu option:\n");
    scanf("%d",&userChoice);
  }
}  
