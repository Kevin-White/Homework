default: myProg
myprog3: Length.h Question3.o
	g++ -std=c++11 Length.h Question3.o -o myProg3
Length.o: Length.cpp Length.h
	g++ -std=c++11 Length.cpp -c
Question3.o: Question3.cpp Length.h
	g++ -std=c++11 Question3.cpp -c
clean:
	rm -rf *.o myProg3