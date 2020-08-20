# <img src="https://user-images.githubusercontent.com/66263776/88350578-252ffd80-cd19-11ea-9730-7bd7b1da9fca.jpg" width="50" height= "50"> Simple Shell <img src="https://user-images.githubusercontent.com/66263776/88350578-252ffd80-cd19-11ea-9730-7bd7b1da9fca.jpg" width="50" height= "50">

<p align="center">
  <img src="https://github.com/CBarreiro96/simple_shell/blob/Camilo/shell_image.jpg" width="500" height= "300">
</p>

## :books: Resources:books:
Read or watch:
* [Everything you need to know to start coding your own shell](https://intranet.hbtn.io/concepts/64)
* [Unix Shell](https://en.wikipedia.org/wiki/Unix_shell)
* [Thompson shell](https://en.wikipedia.org/wiki/Thompson_shell)
* [Ken Thompson](https://en.wikipedia.org/wiki/Ken_Thompson)

## Prerequisites
Only use the following functions and system calls:
```
access (man 2 access)
chdir (man 2 chdir)
close (man 2 close)
closedir (man 3 closedir)
execve (man 2 execve)
exit (man 3 exit)
fork (man 2 fork)
free (man 3 free)
fstat (man 2 fstat)
getcwd (man 3 getcwd)
getline (man 3 getline)
kill (man 2 kill)
lstat (man 2 lstat)
malloc (man 3 malloc)
open (man 2 open)
opendir (man 3 opendir)
perror (man 3 perror)
read (man 2 read)
readdir (man 3 readdir)
signal (man 2 signal)
stat (man 2 stat)
strtok (man 3 strtok)
wait (man 2 wait)
waitpid (man 2 waitpid)
wait3 (man 2 wait3)
wait4 (man 2 wait4)
write (man 2 write)
_exit (man 2 _exit)
```
## Description
In this repositories you find a minishell where you can do all activities that you can do in a Shell like pwd(print working directory), cd, and thing like that. By the way this shell work that interactive mode and non interectactive. 

If you would like to have this program you need to clone this repositories:
```
git clone https://github.com/CBarreiro96/simple_shell/tree/master
```
## Compilation
```
gcc -Wall -Werror -Wextra -pedantic *.c -o hsh
```
After this Compilation you need to execute this command, you need to write the next in your terminal:
```
$ ./hsh
```
## Interactive-mode
```
$ ./hsh
($) /bin/ls
hsh main.c shell.c
($)
($) exit
$
```
## Non-interactive mode:
```
$ echo "/bin/ls" | ./hsh
hsh main.c shell.c test_ls_2
$
$ cat test_ls_2
/bin/ls
/bin/ls
$
$ cat test_ls_2 | ./hsh
hsh main.c shell.c test_ls_2
hsh main.c shell.c test_ls_2
$
```


## :gem: File description :gem:
| File | Description | Flowcharts |
| :---: | :---: | :---: |
| [main.c](https://github.com/CBarreiro96/simple_shell/blob/Camilo/main.c "Principal Function") | Contains the principal of execution | [flowchart main](https://github.com/CBarreiro96/simple_shell/blob/master/imagenes/readme1.png "mainflowchart") |
|[environment.c](https://github.com/CBarreiro96/simple_shell/blob/Camilo/environment.c "variable environment") | In this file get variable enviroment in this file we can find the next funtions that help to search files in the PATH vaible: :sunflower: **list_from_path**: in this will build a linked list from path :sunflower: **search_os**: searh go over directories of PATH the command if find it return the adress where the command is, if no find it return NULL| [flowchat search_path](https://user-images.githubusercontent.com/58672916/90821367-673c6700-e2f8-11ea-9d44-4a10bc7a5e6a.png "search_path")|
| [memory_managment.c](https://github.com/CBarreiro96/simple_shell/blob/master/memory_managment.c "Header") | Contains the libraries of proyect and It is define the struct |[flowchart new_memory](https://github.com/CBarreiro96/simple_shell/blob/master/imagenes/readme2.png "new_memoryflowchart")|
| [Operation.c](https://github.com/CBarreiro96/simple_shell/blob/master/operation.c "Operation system") | In this file ther are three function: :sunflower:   **_strlen:** " *fuction that return lenght of the argument*" :sunflower: **_strncmp=**" **int strncmp(const char *str1, const char *str2, size_t n)** _compares at most the first n bytes of str1 and str2_ " :sunflower: **_strcat_realloc**| ---| 
|[split_line.c](https://github.com/CBarreiro96/simple_shell/blob/master/split_line.c "Function Flowchart") | blbla | | 
| [execution.c](https://github.com/CBarreiro96/simple_shell/blob/master/execution.c "Execution") | ---- | --- | ---- |
| [linkend_list_operation.c](https://github.com/CBarreiro96/simple_shell/blob/master/linkend_list_operation.c "linkend list operation") | It contain to description about printf | |
| [_getenv.c](https://github.com/CBarreiro96/simple_shell/blob/Camilo/_getenv.c) | In this file contain the function **_getentv:** This function searches the environment list to find the environment variable name, and returns a pointer to the corresponding value string. | ---- |
| [shell.c](https://github.com/CBarreiro96/simple_shell/blob/Camilo/shell.h)| In this file contain prototypes of all function in the program| Header |
|[AUTHORS](https://github.com/CBarreiro96/simple_shell/blob/Camilo/AUTHORS "Team")| -- | -- |

## AuthorS
* **Camilo Barreiro** - [CBarreiro96](https://github.com/CBarreiro96)
* **Luis Esteban Martinez Fuentes** - [Estcode14](https://github.com/Estcode14)
