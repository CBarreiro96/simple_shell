# <img src="https://user-images.githubusercontent.com/66263776/88350578-252ffd80-cd19-11ea-9730-7bd7b1da9fca.jpg" width="50" height= "50"> Simple Shell <img src="https://user-images.githubusercontent.com/66263776/88350578-252ffd80-cd19-11ea-9730-7bd7b1da9fca.jpg" width="50" height= "50">

<p align="center">
  <img src="https://github.com/CBarreiro96/simple_shell/blob/Camilo/ShellImage.jpg" width="400" height= "200">
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
## compilation
```
gcc -Wall -Werror -Wextra -pedantic *.c -o hsh
```
## File description
## :brain: Exrecise :brain:
| File | Description | Flowcharts |
| :---: | :---: | :---: |
| [main.c](https://github.com/CBarreiro96/simple_shell/blob/Camilo/main.c "Principal Function") | Contains the principal of execution | (Flowchart) |
|[environment.c](https://github.com/CBarreiro96/simple_shell/blob/Camilo/environment.c "variable environment") | In this file get variable enviroment | flowchart |
| [memory_managment.c](https://github.com/CBarreiro96/simple_shell/blob/master/memory_managment.c "Header") | Contains the libraries of proyect and It \
is define the struct | holberton |
| [Operation.c](https://github.com/CBarreiro96/simple_shell/blob/master/operation.c "Operation system") | --| ---| 
|[split_line.c](https://github.com/CBarreiro96/simple_shell/blob/master/split_line.c "Function Flowchart") | blbla | | 
| [execution.c](https://github.com/CBarreiro96/simple_shell/blob/master/execution.c "Execution") | Contains the function to printf byte to byte (**write**) | --- | ---- |
| [linkend_list_operation.c](https://github.com/CBarreiro96/simple_shell/blob/master/linkend_list_operation.c "linkend list operation") | It contain to description about printf | |
| [_getenv.c](https://github.com/CBarreiro96/simple_shell/blob/Camilo/_getenv.c) | --- | ---- |
| [shell.c](https://github.com/CBarreiro96/simple_shell/blob/Camilo/shell.h)| --- | |
|[AUTHORS](https://github.com/CBarreiro96/simple_shell/blob/Camilo/AUTHORS "Team")| -- | -- |

## AuthorS
* **Camilo Barreiro** - [CBarreiro96](https://github.com/CBarreiro96)
* **Luis Esteban Martinez Fuentes** - [Estcode14](https://github.com/Estcode14)
