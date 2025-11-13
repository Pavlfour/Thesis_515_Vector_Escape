# === CONFIGURATION ===
CXX ?= g++
INCLUDE = -I"../SFML-3.0.0/include" \
          -I"headers"

# Search both SFML
LIBDIR = -L"../SFML-3.0.0/lib"

# === FILES ===
SRC = main.cpp Bitron.cpp Game.cpp platform.cpp coin.cpp laser.cpp Health.cpp \
      Voltwing.cpp Beamlok.cpp mapManager.cpp linearPlatform.cpp circularPlatform.cpp \
      Sounds.cpp Window.cpp
OBJ = $(SRC:.cpp=.o)
RES = appicon.res
EXE = VectorEscape.exe

# === FLAGS ===
CXXFLAGS = -g -DSFML_STATIC -static -static-libgcc -static-libstdc++ -mwindows -fdiagnostics-color=always
LDFLAGS = $(LIBDIR) \
           -lsfml-graphics-s -lsfml-window-s -lsfml-audio-s -lsfml-system-s \
           -lopengl32 -lfreetype -ljpeg -lopenal -lflac -lvorbisenc -lvorbisfile -lvorbis -logg \
           -lwinmm -lgdi32 -ldsound -luser32 -lkernel32

# === TARGETS ===
all: $(EXE)

$(EXE): $(OBJ) $(RES)
	$(CXX) $(OBJ) $(RES) -o $(EXE) $(CXXFLAGS) $(LDFLAGS)
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
