all: clean test
test:
	g++ -std=c++17 -pedantic -pthread ./Calculator/main_test.cpp ./Calculator/Model.cpp -lgtest_main -lgtest -lpthread -o test
	./test
clean:
	rm -rf ./test
	rm -rf ./s21_calc
	rm -rf ./Calculator/build

install: build
	cd s21_calc; make

build: Calculator
	rm -rf s21_calc
	mkdir s21_calc
	cd s21_calc; cmake ../Calculator

uninstall: clean

dvi:
	open Calculator/pics/Instruction.pdf
leaks: test
	clang-format -i Calculator/*.cpp
	clang-format -i Calculator/*.h
	CK_FORK=no leaks --atExit -- ./test
	clean
dist:
	tar --totals -cvf s21_calc.tar Calculator