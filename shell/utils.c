#include"cell.h"

 void GetCwd(char *buf,size_t size){
     if (NULL == getcwd(buf, size)) {
             perror(RED"getcwd Failed");
    }
 }


 void print_banner(void){
     p(G " ██████╗███████╗██╗     ██╗\n"
         "██╔════╝██╔════╝██║     ██║\n"
         "██║     █████╗  ██║     ██║\n"
         "██║     ██╔══╝  ██║     ██║\n"
         " ╚██████╗███████╗███████╗███████╗\n"
         "  ╚═════╝╚══════╝╚══════╝╚══════╝\n"RST);
 }

// wrapper for malloc
 void *Malloc_Size(size_t size){
     void *ptr;
     if(size == 0){
         return (NULL);
     }
     ptr = malloc(size);

     if (!ptr){
         perror(RED "Malloc Failed" RST);
         exit(EXIT_FAILURE);
     }
     return (ptr);
 }

//  wrapper for realloc
void *Realloc_Size(void *ptr, size_t size){
    void *new_ptr;
    new_ptr = realloc(ptr, size);

    if (!new_ptr && size !=0){
        perror(RED "Realloc Failed" RST);
        exit(EXIT_FAILURE);
    }
    return (new_ptr);
}