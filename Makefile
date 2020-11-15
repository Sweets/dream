FLAGS=`pkg-config --cflags --libs libdrm`

all:
	g++ $(FLAGS) test.cpp
