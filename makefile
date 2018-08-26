CXX = clang++
OBJS =  tests.o

all: main

main: $(OBJS)
	$(CXX) $(OBJS)  -o testcdllist

clean:
	$(RM) main $(OBJS) core *~