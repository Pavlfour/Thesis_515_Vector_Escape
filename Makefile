# configuration
CXX ?= g++

INCLUDE = -I"../SFML-3.0.0/include" \
          -I"headers"

# search SFML lib for flags
LIBDIR = -L"../SFML-3.0.0/lib"

# files
SRC = main.cpp Bitron.cpp Game.cpp platform.cpp coin.cpp laser.cpp Health.cpp \
      Voltwing.cpp Beamlok.cpp mapManager.cpp linearPlatform.cpp circularPlatform.cpp \
      Sounds.cpp Window.cpp
OBJ = $(SRC:.cpp=.o)
RES = appicon.res
EXE = VectorEscape.exe

# compiler flags (c++17 standard by default in minGW-w64)
CXXFLAGS = -g -DSFML_STATIC -Wall -Wextra -Wpedantic -fdiagnostics-color=always

# linker flags
LDFLAGS = $(LIBDIR) \
			-static -static-libgcc -static-libstdc++ -mwindows \
           -lsfml-graphics-s -lsfml-window-s -lsfml-audio-s -lsfml-system-s \
           -lopengl32 -lfreetype -ljpeg -lopenal -lflac -lvorbisenc -lvorbisfile -lvorbis -logg \
           -lwinmm -lgdi32 -ldsound -luser32 -lkernel32

# targets
all: $(EXE)

$(EXE): $(OBJ) $(RES)
	$(CXX) $(OBJ) $(RES) -o $(EXE) $(LDFLAGS)
	del /Q $(OBJ) 2>nul

%.o: %.cpp
	$(CXX) -c $< -o $@ $(CXXFLAGS) $(INCLUDE)

clean:
	del /Q $(OBJ) $(EXE) 2>nul

run: all
	./$(EXE)

rebuild:
	$(MAKE) clean
	$(MAKE) all
