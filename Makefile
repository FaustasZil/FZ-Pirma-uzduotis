run: Sourcelist.o funkcijoslist.o
 g++ Sourcelist.cpp funkcijoslist.cpp -o
run

funkcijos.o: funkcijoslist.cpp
 g++ -c funkcijoslist.cpp

Source.o: Sourcelist.cpp
 g++ -c Sourcelist.cpp

clean: rm *.o run
