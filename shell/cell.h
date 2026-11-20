#ifndef CELL_H
# define CELL_H 

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/wait.h>

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

#define p(...) printf(__VA_ARGS_)


#endif
