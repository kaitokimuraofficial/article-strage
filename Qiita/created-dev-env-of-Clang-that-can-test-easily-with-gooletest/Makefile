singlylist:		main.o node.o
				gcc main.o node.o && ./a.out
				make clean

main.o:			src/main.c
				gcc -c src/main.c

node.o:			src/node.c
				gcc -c src/node.c

clean:;         rm -f *.o a.out

test:
				docker build . -t clang_unit_test
				docker rmi clang_unit_test 
