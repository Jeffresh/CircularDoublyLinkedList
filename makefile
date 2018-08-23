CXX = clang++
OBJS =  cdllist.hpp

all: main

main: $(OBJS)
	$(CXX) $(OBJS)  

clean:
	$(RM) main $(OBJS) core *~