.PHONY: all clean rebuild tests
all: tests
tests: tests/test.cpp AndThen.h
	@g++ --std=c++14 -I/opt/homebrew/Cellar/boost/1.86.0_2/include -Igoogletest/googletest/include -lgtest tests/test.cpp -o tests/test
clean:
	@rm -f ./test
rebuild:
	@make clean all
