#include"cell.h"

 void GetCwd(char *buf,size_t size){
     if (NULL == getcwd(buf, size)) {
             perror(RED"getcwd Failed");
    }
 }