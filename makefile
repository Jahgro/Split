# g++ -fPIC -g -c libmy.cc
# g++ -shared -o libmy.so libmy.o

CC = g++
CXXFLAGS = -O2 -Wall
#LDLIBS = -lrt

all: main.o splitfile.o usage.o optparse.o filesplit

filesplit: main.o splitfile.o usage.o optparse.o
	$(CC) $(CXXFLAGS) -o $@ $+

main.o: main.cc main.h
	$(CC) $(CXXFLAGS) -c -o $@ main.cc

splitfile.o: splitfile.cc main.h buffer.h
	$(CC) $(CXXFLAGS) -c -o $@ splitfile.cc

optparse.o: optparse.cc main.h
	$(CC) $(CXXFLAGS) -c -o $@ optparse.cc

usage.o: usage.cc
	$(CC) $(CXXFLAGS) -c -o $@ usage.cc

clean:
	rm filesplit *.o
