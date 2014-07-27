#include 'sl_strlen.h'

int sl_strlen(*s){
  i = 0 ;
  while(*s){
    *s++;
    i++;
  }
  return i;
}
