// tree like directory viewer in C

// Working
// -> get (path)
// -> walk (path)
// ->   if is dir -> walk (subdir)
// ->   if is file -> print files

#include <dirent.h>
#include <stdio.h>
#include <string.h>

void print_file(const char *name, int is_dir, int indent) {
  if (indent) {
    printf("%*c", indent * 2, ' ');
  }
  if (is_dir) {
    printf("\033[0;34m%s\033[0m\n", name);
  } else {
    printf("%s", name);
  }
}

int walk(const char *path, int indent) {
  DIR *dir = opendir(path);

  if (!dir) {
    perror("opendir ");
    return 1;
  }

  struct dirent *dp;
  // this structure contains the information about the directory entry 

  while ((dp = readdir(dir)) != NULL) {
    // readdir has return type of struct dirent *

    const char *name = dp->d_name; // d_name is the null terminated file name of type char
    // d_type contains the name of file or directory 
    
    printf("%s\n", name);
    // prints the name of all files and directories in current directories  

    if (strcmp(name, ".") == 0 || strcmp(name, "..") == 0)
    {
      continue;
    }
    // this if statement skipps . and .. 
    // up to here is reading directory entry readdir() reads one directory entry at a time


    // check man page of readdir to understand about DT_DIR 
      // if d_type is directory ... 
    if (dp->d_type == DT_DIR ){ 
 

      print_file(name, 1, indent);


      size_t len = strlen(path) + strlen(name) + 2;
      // strlen returns number of characters in strings excluding the null terminator \0
      //  sk +2 means "\0" and "/" used in path eg: path + /documents\0 
      char sub_path[len];
      // sub_path holds the full path of the subdirectory
      
      // sub_path = buffer that holds the combined path.
      // len = total memory required to store that combined path, including / and \0. 
      

      snprintf(sub_path, len, "%s/%s", path, name);
  //  snprintf(buf, countof(buf), "%s some further text", buf);
      // check man page of snprintf
      walk(sub_path, indent + 1);
    }
    else {
      print_file(name, 0, indent);
    }
  }
  closedir(dir);
  return 0;
}

int main(int argc, char **argv) {
  const char *path = ".";

  if (argc > 1) {
    path = argv[1];
  }

  int err = walk(path, 0);

  return err;
}
