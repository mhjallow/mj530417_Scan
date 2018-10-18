all:
	make clean
	make build

clean:
	-rm *.o
	-rm *.class
	-rm a.out
	-rm myexe

collegemain.o: collegemain.cc node.h college.h course.h
	g++ -c collegemain.cc
	
course.o: course.cc course.h 
	g++ -c course.cc

college.o: college.cc college.h course.h node.h
	g++ -c college.cc
	
build: collegemain.o course.o college.o
	g++ *.o -o myexe

myexe: collegemain.o course.o college.o
	g++ *.o -o myexe

	
