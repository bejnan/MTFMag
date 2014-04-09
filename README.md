Project	: MTFMag
Author 	: Jakub Banaszewski

Main target of project is to compare modifications of MTF (Move To Front) 
algorithm with original one.

1. Problem :

Let take single mobile phone. Every one of as uses contacts do call our friends. But which contacts
should be available at hand? Move To Front is one of the best algorithms in this subject, but can it works better?  
Aim of project is to create MTF modifications, which can be better than MTF itself.

2. Common names : (* means part of class name)

Every file has similar name as class inside (data_output -> DataOutput)

	*Processor 			- Algorithm testers
	*ProcessorFactory 	- Generate algorithms instances
	*DataOutput 		- Classes to produce output
	*DataProvider 		- Classes to read input data
	*Element			- Classes to represent single object (user, id, contact)
	  

Classes with Data prefix are responsible for data deliver (DataProvider), handle data (DataCollector)
and prepare data output (DataOutput).

3. Folders :

- data_managment - Contains classes to manage algorithms and provides them data.
- elements 		 - Containers for objects (user, id, contacts) 
- exceptions 	 - Own implementation of exceptions that can be thrown by program
- headers		 - Headers collecting all classes from one folder of project
- matrix		 - Move To Front as matrix implementation
- tools			 - Classes needed to create and connect algorithms with data
- tree			 - Move To Front as tree implementation

4. Items not mentioned :

- Database		 - Contains Processors, manage them, find them
- DataCollector	 - Runs Processors and connect them with data
- Tester		 - Count penalties for bad guesses of algorithms

Additional information can be found in files and documentations