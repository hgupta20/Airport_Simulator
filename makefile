proj6: hgupta20Proj6.o Airport.o TravelNetwork.o
	g++ -o proj6 hgupta20Proj6.o Airport.o TravelNetwork.o

hgupta20Proj6.o: hgupta20Proj6.cpp proj6Decl.h
	g++ -c hgupta20Proj6.cpp

TravelNetwork.o: TravelNetwork.cpp proj6Decl.h
	g++ -c TravelNetwork.cpp

Airport.o: Airport.cpp proj6Decl.h
	g++ -c Airport.cpp

clean:
	rm proj6*.o proj6
