Project	: MTFMag
Author 	: Jakub Banaszewski

Main target of project is to compare modifications of MTF (Move To Front) 
algorithm with original one.

1. Problem :

Lets take single mobile phone. Every one of as uses contacts do call our friends. But which contacts
should be available at hand? Move To Front is one of the best algorithms in this subject, but can it works better?  
Aim of project is to create MTF modifications, which can be better than MTF itself.
Another example are contacts in GMail, Facebook and so on.

2. Requirements

Program is written in c++ using c++11 standard.
To build project gcc with version 4.8+ is suggested.
Tests are supported with boost library.
In moment program will use autotools to run it easiesr.

3. Folders :

-> src (source code)

- algorithms	 - Contains all method implementation with interface for them.
- controller	 - Classes with control over program run and object creation.
- data_managment - Contains classes to manage algorithms and provides them data.
- elements 		 - Containers for objects (user, id, contacts) 
- exceptions 	 - Own implementation of exceptions that can be thrown by program
- headers		 - Headers collecting all classes from one folder of project
- tools			 - Classes needed to connect algorithms with data and judge their work
- utils			 - Place for useful methods and classes (converters etc.)

-> man
 Folder for documentation created with Doxygen.

4. Structure
 
 Heart of program is ResultCollector. It exchange data from input (DataCollector) to
 algorithms, which are evaluated (JudgeCollector) to data output as results (DataCollector again).
 Important element of project is Database. It's container of algorithm instances for every user.
 
5. Ideas
 Now program is testing 3 methods :
 - TreeMTF			- Move to front that uses tree structure
 - MTFMatrix		- Move to front that exchange elements between rows with constant size
 - Move to front 	- Original Move to front implementation
 
This methods are supported with randomization. Random with TreeMTF is still available,
but RandomMTFMatrix gives no better results and it's implementation was removed.
 
Additional information can be found in files and documentations