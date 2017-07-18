all: hello

hello: hello.o

clean:
	-rm -f hello.o
	-rm -f hello

test: hello
	gdb -batch -ex "run" -ex "bt" hello 2>&1 | grep -v ^"No stack."$

debug: hello
	gdb ./hello

.PHONY: clean test debug
