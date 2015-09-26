CC=gcc
CFLAGS=-Iheader -Wall -Werror -g -ggdb
LDFLAGS=

CXX=g++
CXXFLAGS=-Iheader -Wall -Werror -g -ggdb
LDXXFLAGS=

RM=rm
RMFLAGS=-rf

TARGET=build/main.out
OBJS=obj/lexico.o obj/sintatico.o obj/main.o obj/nota.o obj/tocarcmd.o \
     obj/comando.o obj/globals.o obj/termo.o obj/variavel.o obj/tempocmd.o \
		 obj/constint.o obj/exprint.o obj/exprints.o obj/exprintd.o obj/exprlog.o \
		 obj/exprlogd.o obj/atribcmd.o obj/pausarcmd.o obj/blococmd.o obj/secmd.o \
		 obj/repetecmd.o obj/duracao.o

all: $(TARGET)

clean:
	$(RM) $(RMFLAGS) $(OBJS) $(TARGET)

run:	$(TARGET)
	./build/main.out cai-cai.dts

$(TARGET):	$(OBJS)
		$(CXX) -o $(TARGET) $(OBJS) $(LDXXFLAGS)

obj/lexico.o: header/lexico.h src/lexico.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ src/lexico.cpp

obj/termo.o: header/termo.h src/termo.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ src/termo.cpp

obj/variavel.o: header/variavel.h src/variavel.cpp obj/termo.o
	$(CXX) $(CXXFLAGS) -c -o $@ src/variavel.cpp

obj/globals.o: header/globals.h obj/termo.o obj/variavel.o
	$(CXX) $(CXXFLAGS) -c -o $@ src/globals.cpp

obj/nota.o: header/nota.h src/nota.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ src/nota.cpp

obj/duracao.o: header/duracao.h src/duracao.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ src/duracao.cpp

obj/comando.o: header/comando.h src/comando.cpp obj/globals.o
	$(CXX) $(CXXFLAGS) -c -o $@ src/comando.cpp

obj/constint.o: header/constint.h src/constint.cpp obj/termo.o
	$(CXX) $(CXXFLAGS) -c -o $@ src/constint.cpp

obj/expr.o: header/expr.h src/expr.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ src/expr.cpp

obj/exprint.o: header/exprint.h src/exprint.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ src/exprint.cpp

obj/exprints.o: header/exprints.h src/exprints.cpp obj/exprint.o
	$(CXX) $(CXXFLAGS) -c -o $@ src/exprints.cpp

obj/exprintd.o: header/exprintd.h src/exprintd.cpp obj/exprint.o
	$(CXX) $(CXXFLAGS) -c -o $@ src/exprintd.cpp

obj/exprlog.o: header/exprlog.h src/exprlog.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ src/exprlog.cpp

obj/exprlogd.o: header/exprlogd.h src/exprlogd.cpp obj/exprlog.o
	$(CXX) $(CXXFLAGS) -c -o $@ src/exprlogd.cpp

obj/tempocmd.o: header/tempocmd.h src/tempocmd.cpp obj/comando.o obj/constint.o
	$(CXX) $(CXXFLAGS) -c -o $@ src/tempocmd.cpp

obj/tocarcmd.o: header/tocarcmd.h src/tocarcmd.cpp obj/nota.o obj/comando.o \
								obj/duracao.o
	$(CXX) $(CXXFLAGS) -c -o $@ src/tocarcmd.cpp

obj/atribcmd.o: header/atribcmd.h src/atribcmd.cpp obj/exprintd.o obj/exprints.o \
								obj/exprlog.o
	$(CXX) $(CXXFLAGS) -c -o $@ src/atribcmd.cpp

obj/pausarcmd.o: header/pausarcmd.h src/pausarcmd.cpp obj/comando.o obj/constint.o \
								 obj/globals.o
	$(CXX) $(CXXFLAGS) -c -o $@ src/pausarcmd.cpp

obj/blococmd.o: header/blococmd.h src/blococmd.cpp obj/comando.o
	$(CXX) $(CXXFLAGS) -c -o $@ src/blococmd.cpp

obj/secmd.o: header/secmd.h src/secmd.cpp obj/blococmd.o obj/exprlogd.o
	$(CXX) $(CXXFLAGS) -c -o $@ src/secmd.cpp

obj/repetecmd.o: header/repetecmd.h src/repetecmd.cpp obj/blococmd.o obj/exprlogd.o
	$(CXX) $(CXXFLAGS) -c -o $@ src/repetecmd.cpp

obj/sintatico.o: header/sintatico.h src/sintatico.cpp obj/lexico.o obj/nota.o \
	               obj/tocarcmd.o obj/tempocmd.o obj/constint.o obj/atribcmd.o \
								 obj/pausarcmd.o obj/secmd.o obj/repetecmd.o
	$(CXX) $(CXXFLAGS) -c -o $@ src/sintatico.cpp

obj/main.o: src/main.cpp obj/sintatico.o
	$(CXX) $(CXXFLAGS) -c -o $@ src/main.cpp
