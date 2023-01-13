hashTable: hashTable.o
	g++ hashTable.o -o hashTable

hashTable.o: hashTable.cpp
	g++ -c hashTable.cpp

clean:
	rm *.o
	rm hashTable

run: hashTable
	./hashTable
