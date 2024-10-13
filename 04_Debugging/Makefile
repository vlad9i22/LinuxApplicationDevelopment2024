GENERATES = range
TRASH = *.o *.a test_output*
CFLAGS = -O0 -g -Wall

all : $(GENERATES)

range: range.o

test1:
	rm -f gdb.output
	gdb --batch-silent -x gdb_script1 --args ./range 1 10 > /dev/null
	grep "@@@" gdb.output > test_output1
	cmp test_output1 correct_test_output1


test2:
	rm -f gdb.output
	gdb --batch-silent -x gdb_script2 --args ./range -100 100 3 > /dev/null
	grep "@@@" gdb.output > test_output2
	cmp test_output2 correct_test_output2

test: range test1 test2 
	printf "TESTS PASSED\n"

clean:
	rm -f $(TRASH) gdb.output $(GENERATES)
