
#include "cell.h"


char *cell_read_line(void){

char *buf;
size_t bufsize;
char cwd[BUFSIZ];
// BUFSIZ is a macro that is defined in stdio.h  

buf = NULL;

GetCwd(cwd, sizeof(cwd));

// if(isatty(fileno(stdin))){}
// todo -> this checks wheather the shell is in interactive mode or running scripts

p(C"🐚 %s 🦠 $> ", cwd); 
// %s is the actual path which is cwd

if (getline(&buf, &bufsize, stdin) == -1)
{
  buf = NULL;

  if (feof(stdin))
  {
    p(RED "[EOF]");
  }
  else
  {
    p(RED "Getline Failed");
  }
  }

  return buf;
}

int main(int argc, char **argv){

    // get line
     char * line;

  while (0xCE77){
    line =cell_read_line();
    p("%s\n", line);
  }

    // get tokens
 

    // exec


    return EXIT_SUCCESS;
}
