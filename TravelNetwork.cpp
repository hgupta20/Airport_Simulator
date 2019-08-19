#include "proj6Decl.h"


	// Use a constructor to initialize the Data Members for Travel Network
	TravelNetwork::TravelNetwork()
	{
		files = new StrList();
		length = 10;
		network = new  Airport*[length];
		int i = 0;
		while (i<length) {
			network[i] = new Airport();
			i++;
		}
	}


	// The main loop for reading in input
	void TravelNetwork::processCommandLoop(FILE* inFile)
	{
		char  buffer[300];
		char* input;

		input = fgets(buffer, 300, inFile);   // get a line of input

											  // loop until all lines are read from the input
		while (input != NULL)
		{
			// process each line of input using the strtok functions 
			char* command;
			command = strtok(input, " \n\t");

			printf("*%s*\n", command);

			if (command == NULL)
				printf("Blank Line\n");

			else if (strcmp(command, "q") == 0)
				exit(1);

			else if (strcmp(command, "?") == 0)
				showCommands();

			else if (strcmp(command, "t") == 0)
				doTravel();

			else if (strcmp(command, "r") == 0)
				doResize();

			else if (strcmp(command, "i") == 0)
				doInsert();

			else if (strcmp(command, "d") == 0)
				doDelete();

			else if (strcmp(command, "l") == 0)
				doList();

			else if (strcmp(command, "f") == 0)
				doFile();

			else if (strcmp(command, "#") == 0)
				;

			else
				printf("Command is not known: %s\n", command);

			input = fgets(buffer, 300, inFile);   // get the next line of input

		}
	}

	void TravelNetwork::showCommands()
	{
		printf("The commands for this project are:\n");
		printf("  q \n");
		printf("  ? \n");
		printf("  # \n");
		printf("  t <int1> <int2> \n");
		printf("  r <int> \n");
		printf("  i <int1> <int2> \n");
		printf("  d <int1> <int2> \n");
		printf("  l \n");
		printf("  f <filename> \n");
	}

	void TravelNetwork::doTravel()
	{
		int val1 = 0;
		int val2 = 0;

		// get an integer value from the input
		char* next = strtok(NULL, " \n\t");
		if (next == NULL)
		{
			printf("Error: Integer value expected\n");
			return;
		}
		val1 = atoi(next);
		if (val1 == 0 && strcmp(next, "0") != 0)
		{
			printf("Error: Integer value expected\n");
			return;
		}

		// get another integer value from the input
		next = strtok(NULL, " \n\t");
		if (next == NULL)
		{
			printf("Error: Integer value expected\n");
			return;
		}
		val2 = atoi(next);
		if (val2 == 0 && strcmp(next, "0") != 0)
		{
			printf("Error: Integer value expected\n");
			return;
		}

		printf("Performing the Travel Command from %d to %d\n", val1, val2);

		int i;
		for (i = 0; i < length; i++) {
			network[i]->setIsvisited(false);
		}
		network[val1 - 1]->setIsvisited(true);
		if (dfs(val1, val2) == true) {
			printf("You can get from airport %d to airport %d in one or more flights.\n", val1, val2);
		}
		else
			printf("Error: You can not get from airport %d to airport %d in one or more flights.\n", val1, val2);

	}

	bool TravelNetwork::dfs(int a, int b)
	{
		List * tmp = network[a - 1]->getList();
		int len = tmp->getLength();
		for (int i = 0; i<len; i++) {
			int x = tmp->getNthElement(i);
			network[a - 1]->setIsvisited(true);

			if (x == b)
				return true;
			if (!network[x - 1]->getIsvisited()) {
				if (dfs(x, b) == true)
					return true;
			}
		}
		return false;

	}

	void TravelNetwork::doResize()
	{
		int val1 = 0;
		char* next = strtok(NULL, " \n\t");
		if (next == NULL)
		{
			printf("Error: Integer value expected\n");
			return;
		}
		val1 = atoi(next);
		if (val1 == 0 && strcmp(next, "0") != 0)
		{
			printf("Error: Integer value expected\n");
			return;
		}
		printf("Performing the Resize Command with %d\n", val1);
		Airport** tmp = new Airport*[val1];
		int i = 0;
		if (val1 < length) {
			while (i < val1) {
				tmp[i] = network[i];
				i++;
			}
			while (i < length) {
				network[i]->clear();
				delete network[i];
				i++;
			}
		}
		else if (val1 >= length) {
			while (i < val1) {
				tmp[i] = new Airport();
				i++;
			}
			while (i < length) {
				tmp[i] = network[i];
				i++;
			}

		}
		length = val1;
		delete network;
		network = tmp;
	}

	void TravelNetwork::doInsert()
	{
		int val1 = 0;
		int val2 = 0;

		// get an integer value from the input
		char* next = strtok(NULL, " \n\t");
		if (next == NULL)
		{
			printf("Error: Integer value expected\n");
			return;
		}
		val1 = atoi(next);
		if (val1 == 0 && strcmp(next, "0") != 0)
		{
			printf("Error: Integer value expected\n");
			return;
		}

		// get another integer value from the input
		next = strtok(NULL, " \n\t");
		if (next == NULL)
		{
			printf("Error: Integer value expected\n");
			return;
		}
		val2 = atoi(next);
		if (val2 == 0 && strcmp(next, "0") != 0)
		{
			printf("Error: Integer value expected\n");
			return;
		}
		if (val1>length || val2>length) {
			printf("Error: Input is out of bounds.\n");
			return;
		}
		printf("Performing the Insert command from %d to %d\n", val1, val2);
		List * tmp = network[val1 - 1]->getList();
		if (tmp->numExist(val2)) {
			return;
		}
		network[val1 - 1]->pushPort(val2);
	}

	void TravelNetwork::doDelete()
	{
		int val1 = 0;
		int val2 = 0;

		// get an integer value from the input
		char* next = strtok(NULL, " \n\t");
		if (next == NULL)
		{
			printf("Integer value expected\n");
			return;
		}
		val1 = atoi(next);
		if (val1 == 0 && strcmp(next, "0") != 0)
		{
			printf("Integer value expected\n");
			return;
		}

		// get another integer value from the input
		next = strtok(NULL, " \n\t");
		if (next == NULL)
		{
			printf("Integer value expected\n");
			return;
		}
		val2 = atoi(next);
		if (val2 == 0 && strcmp(next, "0") != 0)
		{
			printf("Error: Integer value expected\n");
			return;
		}

		printf("Performing the Delete command from %d to %d\n", val1, val2);

		network[val1 - 1]->deletePort(val2);
	}

	void TravelNetwork::doList()
	{
		printf("Performing the List Command\n");
		int i = 0;
		while (i < length) {
			printf("Destinations from airport %d : \n", i + 1);
			network[i]->display(); // display the list
			i++; // increase the counter
		}

	}

	void TravelNetwork::doFile()
	{
		// get a filename from the input

		char* fname = strtok(NULL, " \n\t");
		if (fname == NULL)
		{
			printf("Error: Filename expected\n");
			return;
		}

		printf("Performing the File command with file: %s\n", fname);

		string newFile = fname;


		FILE* newInput;
		bool nameexist = files->nameExist(newFile);
		if (nameexist) {
			printf("Error: The file name is already in use.\n");
			return;
		}

		files->addName(newFile);

		newInput = fopen(fname, "r");
		processCommandLoop(newInput);
		//close the file 
		fclose(newInput);
		files->remove(newFile);
	}

