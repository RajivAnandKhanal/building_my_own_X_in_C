
#include "cell.h"

char **cell_split_line(char* line)
{
  char **tokens;
  unsigned int position;
  size_t bufsize;

  bufsize = BUFSIZ;

  tokens = Malloc_Size(bufsize * sizeof *tokens);
  
  position = 0;

  for (char *token = strtok(line, DEL); token; token = strtok(NULL, DEL))
  {
    tokens[position++] = token;
  
    if (position >= bufsize){
  
      bufsize *= 2;
  
      tokens = Realloc_Size(tokens, bufsize * sizeof(*tokens));
    }
  }
  
  tokens[position] = NULL;
  
  return NULL;
}

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
    p(RED "[EOF]"RST);
  }
  else
  {
    p(RED "Getline Failed"RST);
  }
}

  return buf;
}



// int main(int argc, char **argv){
int main(){

  print_banner();


       char * line;
     char **args;
    
    
     //1 get line
     while (line = cell_read_line())
     {

       p("%s\n", line);
     }

    //2 get tokens
 args =  cell_split_line(line);

 // loop to print all tokesn for testing purpose only 
 for (int i = 0; args[i];i++){
   p("%s\n", args[i]);
 }

   // 3 exec



  //  free
 free(line);
 free(args);

 return EXIT_SUCCESS;
}
