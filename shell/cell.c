
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
