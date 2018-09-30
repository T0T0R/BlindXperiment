 
BlindX: src/* 
	g++ -Wall -Wextra -std=c++11  -o BlindX src/*.cpp 

mrproper:
	rm -f BlindX
