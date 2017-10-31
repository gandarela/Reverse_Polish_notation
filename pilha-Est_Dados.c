#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

struct Pilha{
  float x;
  struct Pilha *pt;
};

struct PilhaOpe{
  char x;
  struct PilhaOpe *pt;
};

struct Pilha* cria(struct Pilha *a, struct Pilha *p){
  p = a;
  return p;
}

struct PilhaOpe* criaOpe(struct PilhaOpe *a, struct PilhaOpe *p){
  p = a;
  return p;
}

struct Pilha* push(struct Pilha *a, float x){
  struct Pilha *novo = malloc(sizeof(struct Pilha));
  if(novo == NULL){
    exit(1);
  }
  novo->x = x;
  novo->pt = a;
  a = novo;
  return a;
}

struct PilhaOpe* pushO(struct PilhaOpe *a, char x){
  struct PilhaOpe *novo = malloc(sizeof(struct PilhaOpe));
  if(novo == NULL){
    exit(1);
  }
  novo->x = x;
  novo->pt = a;
  a = novo;
  return a;
}


struct Pilha* pop(struct Pilha *a, struct Pilha *p){
  if(p == a){
    return NULL;
  }else{
    struct Pilha *new;
    new = a->pt;
    free(a);
    return new;
  }
}

struct PilhaOpe* popO(struct PilhaOpe *a, struct PilhaOpe *p){
  if(p == a){
    return NULL;
  }else{
    struct PilhaOpe *new = NULL;
    new = a->pt;
    free(a);
    return new;
  }
}


int main (){
  struct Pilha *a = NULL, *p = NULL;
  struct PilhaOpe *b = NULL, *d = NULL;
  char c;
  int i=0;
  float aux;
  char x[1024];
  p = cria(a,p);
  d = criaOpe(b,d);
  scanf("%[^\n]s", x);
  while(x[i] != '\0'){
    if(isdigit(x[i])){
      int help = atoi(&x[i]);
      a = push(a,help);
      while(help > 9){
        i++;
        help = help/10;
      }
    } else{
    switch (x[i]) {
      case ')':
        switch (b->x) {
          case '+':
          aux = a->x;
          a = pop(a,p);
          aux = a->x+aux;
          a = pop(a,p);
          a = push(a,aux);
          b = popO(b,d);
          break;
          case '/':
          aux = a->x;
          a = pop(a,p);
          aux = a->x/aux;
          a = pop(a,p);
          a = push(a,aux);
          b = popO(b,d);
          break;
          case '*':
          aux = a->x;
          a = pop(a,p);
          aux = a->x*aux;
          a = pop(a,p);
          a = push(a,aux);
          b = popO(b,d);
          break;
          case '-':
          aux = a->x;
          a = pop(a,p);
          aux = a->x-aux;
          a = pop(a,p);
          a = push(a,aux);
          b = popO(b,d);
          break;
        }
        break;
      case '+':
        c = '+';
        b = pushO(b,c);
        break;
      case '-':
        c = '-';
        b = pushO(b,c);
        break;
      case '/':
        c = '/';
        b = pushO(b,c);
        break;
      case '*':
        c = '*';
        b = pushO(b,c);
        break;
    }
  }
    i++;
  }
  printf("Resultado = %f\n",a->x);
  return 0;
}
