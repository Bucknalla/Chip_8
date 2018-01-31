CXX = gcc
SDL = -I/usr/local/Cellar/sdl2/2.0.7/include/SDL2 -L/usr/local/Cellar/sdl2/2.0.7/lib/ -lSDL2
# If your compiler is a bit older you may need to change -std=c++11 to -std=c++0x
CXXFLAGS = -Wall -c -g $(SDL)
LDFLAGS = $(SDL) 
EXE = SDL_Lesson0

all: $(EXE)

$(EXE): main.o
	$(CXX) $(LDFLAGS) $< -o $@

main.o: main.c
	$(CXX) $(LDFLAGS) $< -o $@

clean:
	rm *.o && rm $(EXE)