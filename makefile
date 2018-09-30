 
main: src/* 
	g++ -Wall -Wextra -std=c++11  -o main src/*.cpp 

mrproper:
	rm -f main
