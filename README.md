# Airport_Simulator
Assume you have a small airline that flies planes between a small number of airports. This program is a travel network simulator.

Program that simulates airports and all of it's incoming and outgoing flights
Please read the PDF for a better understanding of the program.

Input:

q - quit the program

? - display a list of commands the user can enter for the program

# - ignore this line of input

t - display a message stating whether a person can travel from airport to airport in one or more flights

r - remove all values from the traffic network and resize the array to contain the number of aiports as indicated by the given integer value. The value of the integer must be greater than zero.

i - insert the edge to indicate a plane flies from airport to airport

d - delete the edge that indicates a plane flying from airport to airport

l - list all the items contained in the travel network. First display all of the airports (if any) that can be reached from the aiport #1 in one flight (that have an edge in the network), followed by all the airports (if any) that can be reachede from airport #2 in one flight, etc.

f - open the file indicates by the (assume it is in the current directory) and read commands from this file. When the end of the file is reached, continue reading commands from previous input source.
