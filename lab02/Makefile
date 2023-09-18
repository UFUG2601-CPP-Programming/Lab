# Compiler
CXX := g++

# Source file
SOURCE := lab02.cpp

# Executable name
EXECUTABLE := lab02

# Compile and link
$(EXECUTABLE): $(SOURCE)
	$(CXX) -o $@ $<

run: $(EXECUTABLE)
	./$^

clean:
	rm -f $(EXECUTABLE)

all: $(EXECUTABLE)

.PHONY: clean