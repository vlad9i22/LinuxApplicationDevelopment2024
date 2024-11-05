SRC=move.c
GENERATES = move
TRASH = *.o

all: $(GENERATES)

move: move.o

test_normal_run:
	cp inp test_inp
	./move inp out
	cmp test_inp out
	cp test_inp inp

test_perm_denied:
	cp inp test_inp
	strace -e read -e fault=read:error=EACCES:when=2 ./move inp out; test $$? -eq 13
	cmp test_inp inp
	ls | grep out; test $$? -eq 1
	ls | grep inp; test $$? -eq 0

		

test: move test_normal_run test_perm_denied
	printf "Tests passed\n"

clean:
	rm -f *.o $(GENERATES) $(TRASH) test_inp
