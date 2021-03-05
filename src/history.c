#include <stdlib.h>
#include <stdio.h>
#include "history.h"

//History list is initislized to root of list to null
List *init_history(){

  List *histList = malloc(sizeof(List));
  histList->root = NULL;
  return histList;
}
//every string created is added to history list
void add_history(List *list, char *str){
  Item  *node = (Item*)malloc(sizeof(Item));//allocates memory for node

  node-> str = str;
  node-> next = NULL;
  if(list->root == NULL){

    list->root = node;

    node-> id = 1;
  }
  else{
    int count = 2;
    Item *holder;
    holder = list-> root;
    while(holder->next != NULL){
      count++;
      holder = holder->next;
    }
    holder->next = node;
    node->id = count;
  }
}

char *get_history(List *list, int id){
  if(id == 1){
    list->root->str;
  }
  Item *holder = list->root;
  while(holder != NULL){
    if(holder ->id == id){
      return holder->str;
    }
    holder = holder->next;
  }
  return NULL;
}

void print_history(List *list){
  Item *holder = list->root;
  while(holder != NULL){
    printf("ID<%i> STR[%s]\n", holder->id, holder->str);
    holder = holder->next;
  }
}

void free_history(List *list){
  free(list);
}
