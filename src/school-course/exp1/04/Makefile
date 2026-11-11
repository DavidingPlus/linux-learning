CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++11

school-course-exp1-04: main.o add.o
	$(CXX) $(CXXFLAGS) -o $@ $^

main.o: main.cpp add.h
	$(CXX) $(CXXFLAGS) -c -o $@ main.cpp

add.o: add.cpp config.h
	$(CXX) $(CXXFLAGS) -c -o $@ add.cpp

.PHONY: clean
clean:
	rm -f school-course-exp1-04 main.o add.o
