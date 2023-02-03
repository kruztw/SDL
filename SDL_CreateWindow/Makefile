CXX = clang++
SDL = -I/usr/local/include/SDL2 -L/usr/local/lib -lSDL2
CXXFLAGS = -Wall -c
LDFLAGS = $(SDL)
EXE = Main

all: $(EXE)

$(EXE): main.o
	$(CXX) $(LDFLAGS) $< -o $@

main.o: main.cpp
	$(CXX) $(CXXFLAGS) $< -o $@

clean:
	rm *.o && rm $(EXE)
