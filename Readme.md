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

Note: $@ - current target, $^ all to the right of :, $< - first
to the right of :

