main: main.o student.o studentlist.o
	g++ -o main main.o student.o studentlist.o

main.o: main.cpp student.h studentlist.h
	g++ -c main.cpp

student.o: student.cpp student.h
	g++ -c student.cpp

studentlist.o: studentlist.cpp studentlist.h
	g++ -c studentlist.cpp

clean:
	rm -f main *.o
