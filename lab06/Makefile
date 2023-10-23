# Compiler
CXX := g++

# Source file
SOURCE := lab06.cpp

# Executable name
EXECUTABLE := lab06

# Compile and link
$(EXECUTABLE): $(SOURCE)
	$(CXX) -g $< -o $@

run: $(EXECUTABLE)
	./$^

clean:
	rm -f $(EXECUTABLE)

all: $(EXECUTABLE)

.PHONY: clean