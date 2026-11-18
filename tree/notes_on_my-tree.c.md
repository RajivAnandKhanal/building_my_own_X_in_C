# My learning while making this program

### `const` -> read only   
Eg:
```c
const char *path = ".";
```
It creates a pointer to character variable. This `pointer to character varibale` (ie path in this case) is pointing to a memory location and value (character) stored in that location is not modifiable via this variable (ie path cannot modify the value it is storing). 
`BUT`  
path can point to somewhere else in memory ie

```c
if (argc > 1){
	path = argv[1];

// the path pointer is pointing to somewhere else in memory, which is allowed  
// path = "A"; this is also allowed since we are changing where the pointer points    
// BUT  
// path[0] = 'A'; this is not allowed because we are modifying the actual character in the string    
}
``` 
We are not modifying the 
--------------------------------------
A string in c is just a null terminated array ie char *x = "."; will be dissolve into [".","\0"] and x will store the address of first element of array ie "." 

```c
const int *p = 10;
int *p = 10;
//these both are wrong and throw error because *p is expecting memory address
```

`But`

```c
const char *p = ".";
// This is valid because in case of string every string is actually an array and this is actually one of the fundamental concept of c.
// Array returns the memory address of its first element ie address of the array
```
------
## Aribitary parameters
The shell divides arguments based on <space>  
argc -> argument count  

argv -> argument vector  

When argv is passed to main() by the operating system, it will decay into a pointer to its zeroth element, so the data will be of type pointer-to-pointer-to-char.  
`argv[0]` -> is always the name of program and `argc` -> always includes that in its cound ie argc = 1 = the program itself ie  
In a program without user provided argument, has argv[0] = name of program and argc = 1  
In a program with user provided argument, has the arguments from argv[1] and goes upto argv[argc - 1 ] and argc = name of program + argument/s provided

--------------------

`const` -> doesn't changes the original value even if operation happens via pass by reference

----------------------

file descripter is number  
in Kernel there is table that consist of file descripter number  
whenever a file is opened operating system creates an entry in this table and allots a file descripter number for that file. This file descripter contains information about this file  
Wnen another file is opened then again os creates another entry in file descripter table with different file descripter number  
If we close first file then file descripter is removed and that number is used to create another file descripter  

--------------------

##`walk() function`  

opendir() returns a pointer of type DIR* -> check man function of opendir() and dirent.h  
If opendir() fails it returns NULL this happens when the directory name is invalid and this errorr checking is happening in 
```c
  if (!dir) {
    perror("opendir");
    return 1;
  }
```

struct dirent *readdir(DIR *dirp);  -> check man function of readdir()

--------------------------

```c
         struct dirent {
             ino_t          d_ino;       /* Inode number */
             off_t          d_off;       /* Not an offset; see below */
             unsigned short d_reclen;    /* Length of this record */
             unsigned char  d_type;      /* Type of file; not supported
                                            by all filesystem types */
             char           d_name[256]; /* Null-terminated filename */
         };
```
```c
    if (strcmp(name, ".") == 0 || strcmp(name, "..") == 0)
      continue;

```
check man page of strcmp() as the return value is pointing to memcmp()  
the whole logic is strcmp returns 0 when two strings are identical so checking with 0 is just testing whether there exists . and .. or not and the whole if statement is skipping . and .. if exists

--------------------

##`print_file() function`  

```c
printf("%*c", 4, 'A');
// pirint the character A after four space ie:
//    A  
```
---------------------------------

Note:
1. After successfully opening the directory, we use readdir(dir) inside a while loop to read directory entries one by one, storing each entry in the dp pointer, until there are no more entries.  
2. Then we get the entry's name using dp->d_name, print it, skip . and .., and check dp->d_type to determine whether it's a directory or a regular file.  
3. If it's a directory (DT_DIR), we print its name in blue, construct its full path, and recursively call walk(sub_path, indent + 1) to explore that directory; otherwise, we print it as a file.  
4. After processing all entries, we close the directory using closedir(dir) and return 0 to indicate successful execution.  
5. main() returns the error code from walk() as the program's exit status. 
