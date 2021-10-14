run:main
	rm *.o
	./main 
main: linked_list.o main.o
	g++ linked_list.o main.o -o main
main.o: main.cpp
	g++ -c main.cpp
linked_list-o: linked_list.cpp
	g++ -c linked_list.cpp
