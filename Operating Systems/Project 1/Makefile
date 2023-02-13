all: run

run: Project1Main.o
	g++ Project1Main.o -o project1.exe

main.o: Project1Main.cpp hist.h
	g++ -c Project1Main.cpp

clean:
	rm -rf *.o project1.exe