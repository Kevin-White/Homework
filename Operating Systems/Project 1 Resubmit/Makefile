all: run

run: project1.o
        g++ project1.o -o project1.exe

main.o: project1.cpp hist.h
        g++ -c project1.cpp

clean:
        rm -rf *.o project1.exe *.gch
