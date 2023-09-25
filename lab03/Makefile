# Compiler
CXX := g++

# Source file
SOURCE := lab03_1.cpp

# Executable name
EXECUTABLE := lab03

# Compile and link
$(EXECUTABLE): $(SOURCE)
	$(CXX) -o $@ $<

run: $(EXECUTABLE)
	./$^

clean:
	rm -f $(EXECUTABLE)

all: $(EXECUTABLE)

.PHONY: clean