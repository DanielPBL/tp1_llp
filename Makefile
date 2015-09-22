CC=gcc
CFLAGS=-Iheader -Wall -Werror -g -ggdb
LDFLAGS=

CXX=g++
CXXFLAGS=-Iheader -Wall -Werror -g -ggdb
LDXXFLAGS=

RM=rm
RMFLAGS=-rf

TARGET=build/main.out
SRCS=src/lexico.cpp src/sintatico.cpp src/main.cpp src/nota.cpp
OBJS=obj/lexico.o obj/sintatico.o obj/main.o obj/nota.o

all: $(TARGET)

clean:
	$(RM) $(RMFLAGS) $(OBJS) $(TARGET)

run:	$(TARGET)
	./build/main.out cai-cai.dts

$(TARGET):	$(OBJS)
		$(CXX) -o $(TARGET) $(OBJS) $(LDXXFLAGS)

obj/lexico.o: header/lexico.h src/lexico.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ src/lexico.cpp

obj/nota.o: header/nota.h src/nota.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ src/nota.cpp

obj/sintatico.o: header/sintatico.h src/sintatico.cpp obj/lexico.o obj/nota.o
	$(CXX) $(CXXFLAGS) -c -o $@ src/sintatico.cpp

obj/main.o: src/main.cpp obj/sintatico.o
	$(CXX) $(CXXFLAGS) -c -o $@ src/main.cpp
