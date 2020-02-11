CCPP:=g++

CXXFLAGS = $(shell pkg-config --cflags cairo gtk+-3.0 librsvg-2.0 tinyxml2)
LDFLAGS = $(shell pkg-config --libs cairo gtk+-3.0 librsvg-2.0 tinyxml2)

all : test
test : test.o
	$(CCPP) $(CAIROPATH) -o $@ $< $(LDFLAGS)
%.o : %.cpp
	$(CCPP) $(CXXFLAGS) -o $@ -c $< $(LDFLAGS)
clean:
	rm -f *.o *~ test
