# My learnings while making this shelll

### `Resources` : https://www.youtube.com/watch?v=x8gsHFBW7zY

check man page of c pre processor : `man cpp`
https://en.cppreference.com/c/preprocessor

```h
#ifndef CELL_H
# define CELL_H
// cell.c includes cell.h using #include "cell.h", and if CELL_H hasn't been defined yet, the preprocessor defines it and processes the header's contents; otherwise, it skips them.
// cell.h is the filename, while CELL_H is a macro (a flag) used to track whether cell.h has already been included.
// CELL_H is just airbatiry and anythisng can be used in place of that
```

`Basically CELL_H is a tracking flag (macro) indicating that the contents of cell.h ( .h header file which contains CELL_H ) have already been included`

---

### simple shell concept

```h
// cell.h
#ifndef CELL_H
# define CELL_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/wait.h>
#endif
```

```c
// cell.c
#include "cell.h"
int main(int argc, char **argv){
    (void)argc;
    int status;
    //fork creates child process
    if (fork()==0){
        // execvp => execute the vector/argument with path -> it executes the argument with the current user's path
        execvp(argv[1] , argv + 1);
    }
    wait(&status);
    return EXIT_SUCCESS;
}
```

---

This is simple shell that when compiled (gcc -o shell cell.c) and run with argument (./shell ls -la) executes the command passed, if above code is implemented in loop it basically acts as shell by doing following task  
-> takes arguemnt  
-> parse the argument  
-> creates the child process based on the argument passed  
-> ececute the argument, in the child process,while the parent process waits for the child process  
-> looop the above task  
Simple Shell: https://github.com/RajivAnandKhanal/building_my_own_X_in_C/commit/ff27f819df2b2abcb7e683c95de7825b42c1e94f

---

This above shell is command execution shell, while shell like bash is command intrepreter shell

### `Resources`: `https://courses.washington.edu/css430/prog/dimpsey/prog1.html`

---

Basic Concept of Shell

### `Resources`: `https://en.wikipedia.org/wiki/Read%E2%80%93eval%E2%80%93print_loop`

REPL => Read -> Evaluate -> Print -> loop

---

```c
while ( 0xCE77)
```

-> creates an infinite loop  
because when thar hexadecimal is converted into decimal that would be greater then 1, and in c/c++ any value greater than 1 is considered true, its same as

```c
while(1)
```

---

```h
#define p(...) printf(__VA_ARGS_)
```

`p` is the macro name  
`...` means the mcaro accepts a variable number of arguments(variadic macro)

### `Resources : https://gcc.gnu.org/onlinedocs/cpp/Variadic-Macros.html`

`__VA_ARGS__` is a special preprocessor identifuer that represnts all arguments passed to `...`
