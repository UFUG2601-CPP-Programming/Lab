# Compiler
CXX := g++

# Source file
SOURCE := lab04.cpp

# Executable name
EXECUTABLE := lab04

# Compile and link
$(EXECUTABLE): $(SOURCE)
	$(CXX) -o -g $@ $<

run: $(EXECUTABLE)
	./$^

clean:
	rm -f $(EXECUTABLE)

all: $(EXECUTABLE)

.PHONY: clean