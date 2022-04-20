run: Sourcedeque.o funkcijosdeque.o
 g++ Sourcedeque.cpp funkcijosdeque.cpp -o
run

funkcijos.o: funkcijosdeque.cpp
 g++ -c funkcijosdeque.cpp

Source.o: Sourcedeque.cpp
 g++ -c Sourcedeque.cpp

clean: rm *.o run