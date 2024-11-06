SRC=move.c
GENERATES = move
TRASH = *.o test_inp *.so out_prot out test_inp_PROTECT

all: $(GENERATES)

move: move.o

test_normal_run: 
	cp inp test_inp
	./move test_inp out
	cmp inp out

test_perm_denied:
	cp inp test_inp
	strace -e read -e fault=read:error=EACCES:when=2 ./move test_inp out; test $$? -eq 13
	cmp test_inp inp
	test ! -f out
	test -f test_inp
		
test_LD_PRELOAD_trick:
	cp inp_PROTECT test_inp_PROTECT
	gcc -shared -fPIC  remove.c -o remove.so -ldl
	LD_PRELOAD=$$PWD/remove.so ./move test_inp_PROTECT out_prot
	test -f test_inp_PROTECT
	test -f out_prot
	cp inp test_inp
	./move test_inp out
	test ! -f test_inp
	test -f out
	cmp inp out


test: move test_normal_run test_perm_denied test_LD_PRELOAD_trick
	printf "Tests passed\n"

clean:
	rm -f *.o $(GENERATES) $(TRASH)
