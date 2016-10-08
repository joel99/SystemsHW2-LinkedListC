#include <stdio.h>

struct node { int i; struct node *n;};

void print_list(struct node *ll){
  printf("\n");
  while (ll->n){
    printf("Node: %d\n", ll->i );
    ll = ll->n;
  }
  printf("Node: %d\n", ll->i);
}

struct node * insert_front(struct node *ll, int data){
  struct node *newNode = (struct node *)malloc(sizeof(struct node));
  newNode->n = ll;
  newNode->i = data;
  return newNode;
}

struct node * free_list(struct node *ll){
  struct node *ret = ll;
  struct node *tmp;
  while (tmp = ll->n){
    free(ll);
    ll = tmp;
  }
  free(ll);
  free(ret);
  return ret;
}

int main(){

  //taken from Zeech and modified w/ permission :)

  struct node *Foo = insert_front(0, 2);
  printf("Foo: ");
  print_list(Foo);

  // Adding Values
  printf("Adding values 1, 2, 4, 8, 16, 32, 64 to front of list...\n");

  int i;
  for (i = 1; i < 128; i = i * 2)
    Foo = insert_front(Foo, i);

  printf("Foo: \n");
  print_list(Foo);

  // Freeing Memory
  printf("Freeing memory...\n");
  free_list(Foo);
  printf("printing again \n");
  print_list(Foo);
  return 0;
}
