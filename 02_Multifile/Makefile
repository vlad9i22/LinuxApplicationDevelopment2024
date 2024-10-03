GENERATES = prog prog-a prog-so
TRASH = *.o *.a *.so file*
CFLAGS = -Wall -fPIC
LIB_PARTS = fun.o const.o

all: $(GENERATES) libout.a

prog: prog.o fun.o const.o

prog-a: prog.o libout.a
	cc $(CFLAGS) $^ -o $@

prog-so: prog.o libout.so
	cc $^ -o $@

libout.so: $(LIB_PARTS)
	$(CC) $^ -o $@ -shared

libout.a: libout.a(fun.o const.o)

fun.o: outlib.h

test_no_params:
	./prog > file 2>&1
	./prog-a > filea 2>&1
	LD_LIBRARY_PATH=`pwd` ./prog-so > fileso 2>&1
	cmp file filea
	cmp filea fileso

test_one_param:
	./prog TESTPARAM > file 2>&1
	./prog-a TESTPARAM > filea 2>&1
	LD_LIBRARY_PATH=`pwd` ./prog-so TESTPARAM > fileso 2>&1
	cmp file filea
	cmp filea fileso

test_three_params:
	./prog p1 p2 p3 > file 2>&1
	./prog-a p1 p2 p3 > filea 2>&1
	LD_LIBRARY_PATH=`pwd` ./prog-so p1 p2 p3 > fileso 2>&1
	cmp file filea
	cmp filea fileso

test: test_no_params test_one_param test_three_params
	echo "All tests are passed"

clean:
	rm -f $(TRASH)

distclean: clean
	rm -f $(GENERATES)
