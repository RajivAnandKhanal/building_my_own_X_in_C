The purpose of this code is to build the full path of a subdirectory so walk() can enter it.

Let's break it down with an example.

Suppose:


c
path = "documents"
name = "photos"
1. Calculate the required memory


c
size_t len = strlen(path) + strlen(name) + 2;
strlen(path) = 9 (documents)

strlen(name) = 6 (photos)

+2 = one / and one null terminator \0.

Total = 17 bytes.

2. Create a character array


c
char sub_path[len];
Creates an array of 17 characters to store the new path.

3. Combine the paths


c
snprintf(sub_path, len, "%s/%s", path, name);
This produces:


text
documents/photos
Now sub_path contains the full path.

4. Recursively enter that directory


c
walk(sub_path, indent + 1);
This calls walk() again, but this time with:


c
walk("documents/photos", 1);
So it starts reading the contents of photos.

In one sentence:

You are combining the current directory path with the subdirectory name to get its full path, then passing that path to walk() to explore the subdirectory.
