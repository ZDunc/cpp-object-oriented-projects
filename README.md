# Object-Oriented-Projects
Compilation of Project Code for Object-Oriented Programming (C++)

## (1) Triangle Class - Class Implementation
### (class) Triangle stores the side length for an equilateral triangle, as well as a border char and fill char for the traingle. The class can return the side length of the triangle, its perimeter, and its area. It can also grow the triangle (increase side length by 1), shrink the traingle (decrement side length), set the traingle's border char, set the triangle's fill char, draw the triangle (print to screen), and summarize all triangle contents.
- triangle.h
- triangle.cpp

## (2) Temperature Class - Further Class Implementation Practice
### (class) Temperature objects represent a temperature in terms of degree and scales, along with stored format setting. The object will always represent a valid temperature (cannot be lower than 0 degrees Kelvin). The class can appropriately create and update temperature objects, convert between Farenheit, Celsuis, and Kelvin scales, and compare two temperature objects.
- temperature.h
- temperature.cpp

## (3) Rational Number Class - Basic Operator Overloading
### (class) Mixed stores and manages rational numbers in a mixed number format (integer part and a fraction part).
- mixed.h
- mixed.cpp

## (4) Book Class - "Has-a Relationship"
### (class) Book represents a book object manipulated within (class) Store, an object representing a bookstore inventory. Store objects can add books to the inventory, sells books, grow or shrink the inventory capacity, print the full inventory, prints the inventory by genre, searches for books by title, and tracks a monetary balance of the store register. Menu.cpp provides a menu for "Bookstore Inventory Manager," which initializes a new store object and allows a user to modify it until program exit.
- book.h
- book.cpp
- store.h
- store.cpp
- menu.cpp

## (5) Building a larger integer class - More Operator Overloading & Managing Dynamic Memory Allocation Inside a Class
### (class) MyInt allows storage of any non-negative integer (theoretically without an upper limit -- although there naturally is an eventual limit to storage in a program). MyInt consists of necessary operator overloads, so that objects of type MyInt will act like regular integers, to some extent. This program requires dynamic memory allocation.
- myint.h
- myint.cpp

## (6) Student & StudentList Classes - Base and derived classes, virtual functions, applications of polymorphism; further practice with file I/O, as well as dynamic allocation
### (class) Student stores student grade information in a base class and three derived classes simulating different school majors. Data is private or protected, and data access must happen through public member functions. (class) StudentList then stores a list of pointers to Student objects using a dynamically-managed array. Main.cpp creates a single StudentList object and then implements a menu interface to allow interaction with the objects. Sample txt files are included.
- student.h
- studentlist.h
- student.cpp
- studentlist.cpp
- main.cpp
- studentsample1.txt
- studentsample2.txt
- makefile

## (7) List Class - Templated Linked List (Looking Ahead to Data Structures)
### (class) List expands on a templated linked list class studied in this course. Additional functions were implemented and tested: insertMiddle, removeMiddle, copy constructor, and assignment operator. A test program is also provided.
- listnode.h
- list.h
- test.cpp
