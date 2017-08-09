INCLUDE:= -I /home/ytan/Dev/boost_1_64_0
LIBDIR:= -L /usr/local/lib
# INCLUDE:= -I /usr/include/boost/
# LIBDIR:= -L /usr/lib/x86_64-linux-gnu
all: test

test: test.cpp
	# dynamic link
	g++ $^ -o $@ -std=c++14 $(INCLUDE) $(LIBDIR) -lboost_unit_test_framework -pthread 
	# static link
	# g++ $^ -o $@ -std=c++14 -static $(INCLUDE) $(LIBDIR) -lboost_unit_test_framework -pthread 




