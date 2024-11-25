all: bin/dna
	./bin/dna

bin/dna: lib/Dna.o lib/Kromozom.o lib/Gen.o lib/main.o
	g++ -std=c++11 -Iinclude -o bin/dna lib/Dna.o lib/Kromozom.o lib/Gen.o lib/main.o

lib/Dna.o: src/Dna.cpp include/Dna.hpp
	g++ -std=c++11 -Iinclude -c src/Dna.cpp -o lib/Dna.o

lib/Kromozom.o: src/Kromozom.cpp include/Kromozom.hpp
	g++ -std=c++11 -Iinclude -c src/Kromozom.cpp -o lib/Kromozom.o

lib/Gen.o: src/Gen.cpp include/Gen.hpp
	g++ -std=c++11 -Iinclude -c src/Gen.cpp -o lib/Gen.o

lib/main.o: src/main.cpp include/Dna.hpp
	g++ -std=c++11 -Iinclude -c src/main.cpp -o lib/main.o

clean:
	del /q /f lib\*.o bin\dna
