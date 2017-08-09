all: test

test: test.cpp
	# dynamic link
	g++ $^ -o $@ -std=c++14 -I  /usr/include/boost/ -L /usr/lib/x86_64-linux-gnu -lboost_unit_test_framework -pthread 
	# static link
	# g++ $^ -o $@ -std=c++14 -static -I  /usr/include/boost/ -L /usr/lib/x86_64-linux-gnu -lboost_unit_test_framework -pthread 



