// tree like directory viewer in C

// Working
// -> get (path)
// -> walk (path)
// ->   if is dir -> walk (subdir)
// ->   if is file -> print files


#include <stdio.h>

int walk(){
  
}

int main(int argc, char **argv)
{
  const char *path = ".";
// default path is current directory
  
  if(argc>1){
    path = argv[1];
  }
  // printf("path %s",path);

  return 0;
}
