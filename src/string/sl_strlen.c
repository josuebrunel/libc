#include "sl_strlen.h"

int sl_strlen(char *s){
  int i = 0 ;
  while(*s){
    *s++;
    i++;
  }
  return i;
}
