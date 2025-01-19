CXXFLAGS:= -std=gnu++17 -Wall -O -MMD -MP -pthread
CPPFLAGS:= -Wall -O -MMD -MP -pthread

PROGRAMS = utcparse

all: $(PROGRAMS)

clean:
	rm -f *~ *.o *.d test $(PROGRAMS)

-include *.d

utcparse: utcparse.o utcstr2epoch.o
	$(CXX) $^ -o $@ 
