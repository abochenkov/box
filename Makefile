CPPFLAGS=-Wall -g
OBJECTS=main.o box.o hero.o
TARGET=box
%.o: %.cpp
	g++ -c $(CPPFLAGS) -o $@ $<
$(TARGET): $(OBJECTS)
	g++ $(OBJECTS) -o $(TARGET) -g -lglut -lGL
main.o: main.cpp field.hpp box.hpp hero.hpp
box.o: box.cpp box.hpp
hero.o: hero.cpp hero.hpp