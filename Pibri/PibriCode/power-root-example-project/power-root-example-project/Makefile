OPTIONS=-O3

all: build/theanswer

debug: OPTIONS=-O0 -g
debug: build/theanswer

build/theanswer: root power tools/main.cpp
	g++ ${OPTIONS} tools/main.cpp -o build/theanswer -I include/ build/root.o build/power.o

root: src/root.cpp include/myfunctions.hpp
	g++ ${OPTIONS} -c src/root.cpp -o build/root.o -I include/

power: src/power.cpp include/myfunctions.hpp
	g++ ${OPTIONS} -c src/power.cpp -o build/power.o -I include/

clean:
	rm -rf build/*.o build/theanswer
