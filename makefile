# All Targets
all: cTrace

# Tool invocations
# Executable "main" depends on the file main.o
cTrace: bin/main.o bin/Agent.o bin/ContactTracer.o bin/Virus.o bin/CycleTree.o bin/MaxRankTree.o bin/RootTree.o bin/Tree.o bin/Graph.o bin/Session.o
	@echo 'Building target: cTrace'
	@echo 'Invoking: C++ Linker'
	g++ -o bin/cTrace bin/main.o bin/Aget.o bin/ContactTracer.o bin/Virus.o bin/CycleTree.o bin/MaxRankTree.o bin/RootTree.o bin/Tree.o bin/Graph.o bin/Session.o
	@echo 'Finished building target: cTrace'
	@echo ' '

# Depends on the source and header file
bin/main.o: src/main.cpp
	g++ -g -Wall -Weffc++ -std=c++11 -c -Iinclude -o bin/main.o src/main.cpp

# Depends on the source and header file
bin/Agent.o: src/classes/agents/Agent.cpp
	g++ -g -Wall -Weffc++ -std=c++11 -c -Iinclude -o bin/Agent.o src/classes/agents/Agent.cpp

# Depends on the source and header file
bin/ContactTracer.o: src/classes/agents/ContactTracer.cpp
	g++ -g -Wall -Weffc++ -std=c++11 -c -Iinclude -o bin/ContactTracer.o src/classes/agents/ContactTracer.cpp

# Depends on the source and header file
bin/Virus.o: src/classes/agents/Virus.cpp
	g++ -g -Wall -Weffc++ -std=c++11 -c -Iinclude -o bin/Virus.o src/classes/agents/Virus.cpp

# Depends on the source and header file
bin/CycleTree.o: src/classes/trees/CycleTree.cpp
	g++ -g -Wall -Weffc++ -std=c++11 -c -Iinclude -o bin/CycleTree.o src/classes/trees/CycleTree.cpp

# Depends on the source and header file
bin/MaxRankTree.o: src/classes/trees/MaxRankTree.cpp
	g++ -g -Wall -Weffc++ -std=c++11 -c -Iinclude -o bin/MaxRankTree.o src/classes/trees/MaxRankTree.cpp

# Depends on the source and header file
bin/RootTree.o: src/classes/trees/RootTree.cpp
	g++ -g -Wall -Weffc++ -std=c++11 -c -Iinclude -o bin/RootTree.o src/classes/trees/RootTree.cpp

# Depends on the source and header file
bin/Tree.o: src/classes/trees/Tree.cpp
	g++ -g -Wall -Weffc++ -std=c++11 -c -Iinclude -o bin/Tree.o src/classes/trees/Tree.cpp

# Depends on the source and header file
bin/Graph.o: src/classes/Graph.cpp
	g++ -g -Wall -Weffc++ -std=c++11 -c -Iinclude -o bin/Graph.o src/classes/Graph.cpp

# Depends on the source and header file
bin/Session.o: src/classes/Session.cpp
	g++ -g -Wall -Weffc++ -std=c++11 -c -Iinclude -o bin/Session.o src/classes/Session.cpp

#Clean the build directory
clean: 
	rm -f bin/*
