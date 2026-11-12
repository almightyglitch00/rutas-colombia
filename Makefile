all:
	g++ -std=c++17 src/main.cpp src/passenger.cpp src/graph.cpp src/queue.cpp -o sitrac

clean:
	rm -f sitrac

run: all
	./sitrac
