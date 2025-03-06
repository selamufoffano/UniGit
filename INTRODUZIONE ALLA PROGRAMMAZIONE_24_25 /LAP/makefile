OPTIONS=-O3

all: build/theanswer

debug: OPTIONS=-O0 -g
debug: build/theanswer

build/theanswer: root power tools/main.c
	g++ ${OPTIONS} tools/main.c -o build/theanswer -I include/ build/root.o build/power.o

root: src/root.c include/myfunction.hpp
	g++ ${OPTIONS} -c src/root.c -o build/root.o -I include/

power: src/power.c include/myfunction.hpp
	g++ ${OPTIONS} -c src/power.c -o build/power.o -I include/

clean:
	rm -rf build/*.o build/theanswer