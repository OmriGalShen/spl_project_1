# All Targets
all: cTrace

# Tool invocations
# Executable "main" depends on the file main.o
cTrace: bin/main.o
	@echo 'Building target: cTrace'
	@echo 'Invoking: C++ Linker'
	g++ -o bin/cTrace bin/main.o
	@echo 'Finished building target: cTrace'
	@echo ' '

# Depends on the source and header file
bin/main.o: src/main.cpp
	g++ -g -Wall -Weffc++ -std=c++11 -c -Iinclude -o bin/main.o src/main.cpp

#Clean the build directory
clean: 
	rm -f bin/*
