run: Source.o zmogus.o
 g++ Source.cpp zmogus.cpp -o
run

zmogus.o: zmogus.cpp
 g++ -c zmogus.cpp

Source.o: Source.cpp
 g++ -c Source.cpp

clean: rm *.o run
