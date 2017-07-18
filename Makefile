all: hello

hello: hello.o

clean:
	-rm -f hello.o
	-rm -f hello

.PHONY: clean
