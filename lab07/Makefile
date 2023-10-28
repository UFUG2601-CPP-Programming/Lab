# Compiler
CXX := g++

# Source file
SOURCE := lab07.cpp

# Executable name
EXECUTABLE := lab07

# Compile and link
$(EXECUTABLE): $(SOURCE)
	$(CXX) -g $< -o $@

run: $(EXECUTABLE)
	./$^

clean:
	rm -f $(EXECUTABLE)

all: $(EXECUTABLE)

.PHONY: clean