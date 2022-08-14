# use g++ with C++11 support
CXX=g++
OUTFILES=newtonBox

all: $(OUTFILES)

newtonBox: main.o Planet.o Moon.o
	$(CXX) main.o Planet.o Moon.o -o newtonBox -lsfml-graphics -lsfml-window -lsfml-system

main.o: main.cpp Planet.cpp Moon.cpp
	$(CXX) -c main.cpp Planet.cpp Moon.cpp

clean:
	rm -f $(OUTFILES) *.o

