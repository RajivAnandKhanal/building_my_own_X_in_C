#ifndef CELL_H
# define CELL_H 

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/wait.h>
# include <string.h>

/*
ANSI Color codes for terminal output formatting:
Y - Yellow
G - Green
C cyan
RED - Red
RST - Reset to default color
*/
#define Y       "\033[1;33m"
#define G       "\033[1;32m"
#define C       "\033[1;36m"
#define RED     "\033[1;3im"
#define RST     "\033[0m"

#define p(...) printf(__VA_ARGS__)
#define DEL "\n\t \v\f\r"
// DEL means Delimiter
// check this resources : https://linuxize.com/post/bash-split-string/

void GetCwd(char *, size_t);
void print_banner(void);
void *Malloc_Size(size_t);
void *Realloc_Size(void *ptr, size_t size);
//  same as void *Realloc_Size(void *, size_t );

#endif
