all: hello

hello: hello.o

clean:
	-rm -f hello.o
	-rm -f hello

test: hello
	gdb ./hello

.PHONY: clean test
