CC=gcc
CFLAGS=-Iheader -Wall -Werror -g -ggdb
LDFLAGS=

CXX=g++
CXXFLAGS=-Iheader -Wall -Werror -g -ggdb
LDXXFLAGS=

RM=rm
RMFLAGS=-rf

TARGET=build/main.out
SRCS=src/scanner.cpp src/sintatico.cpp src/main.cpp
OBJS=obj/scanner.o obj/sintatico.o obj/main.o

all: $(TARGET)

clean:
	$(RM) $(RMFLAGS) $(OBJS) $(TARGET)

run:	$(TARGET)
	./build/main.out cai-cai.dts	

$(TARGET):	$(OBJS)
		$(CXX) -o $(TARGET) $(OBJS) $(LDXXFLAGS)

obj/scanner.o: header/scanner.h src/scanner.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ src/scanner.cpp

obj/sintatico.o: header/sintatico.h src/sintatico.cpp obj/scanner.o
	$(CXX) $(CXXFLAGS) -c -o $@ src/sintatico.cpp

obj/main.o: src/main.cpp obj/sintatico.o
	$(CXX) $(CXXFLAGS) -c -o $@ src/main.cpp
