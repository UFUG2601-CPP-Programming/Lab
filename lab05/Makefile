# Compiler
CXX := g++

# Source file
SOURCE := lab05.cpp

# Executable name
EXECUTABLE := lab05

# Compile and link
$(EXECUTABLE): $(SOURCE)
	$(CXX) -o -g $@ $<

run: $(EXECUTABLE)
	./$^

clean:
	rm -f $(EXECUTABLE)

all: $(EXECUTABLE)

.PHONY: clean