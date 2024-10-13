01) Is an example of using ncurses to create a C programm which is
 able to look through text in a file using SPACE.


02) Simple programm which prints some argv to the output. 
Main focus here is Makefile. The example provides 3 ways to build 
a program
    1) simple from .o files
    2) from static library and .o file
    3) from dynamic library and .o file
Also a simple test in makefile is provided(run with make test)
The purpose of tests is to check that different ways of building
didn't affect an output of the programm.

Note: "$@" - current target, "$^" all to the right of :, "$<" - first
to the right of :

03) Program is randomly printing redirected symbols to the top of the terminal

The idea is to produce commands to print letter of the input to position (i,j)
then shuffle the commands.
Also provides optional argument to set the delay between prints

Call examples
```
cal | randomize.sh 0.01
cat simple_test | randomize.sh
```
04) Basic example of gdb scritping and script execution from the Makefile.
