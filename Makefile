run: Source.o funkcijos.o
 g++ Source.cpp funkcijos.cpp -o
run

funkcijos.o: funkcijos.cpp
 g++ -c funkcijos.cpp

Source.o: Source.cpp
 g++ -c Source.cpp

clean: rm *.o run