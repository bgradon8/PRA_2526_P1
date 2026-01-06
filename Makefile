bin/testListArray: testListArray.cpp ListArray.h List.h
	@mkdir -p bin
	g++ -o bin/testListArray testListArray.cpp

bin/testNode: testNode.cpp Node.h
	@mkdir -p bin
	g++ -o bin/testNode testNode.cpp

bin/testListLinked: testListLinked.cpp ListLinked.h List.h Node.h
	@mkdir -p bin
	g++ -o bin/testListLinked testListLinked.cpp

bin/testPoint2D: testPoint2D.cpp Point2D.o Point2D.h
	@mkdir -p bin
	g++ -o bin/testPoint2D testPoint2D.cpp Point2D.o

bin/testRectangle: testRectangle.cpp Rectangle.o Shape.o Point2D.o
	@mkdir -p bin
	g++ -o bin/testRectangle testRectangle.cpp Rectangle.o Shape.o Point2D.o

bin/testCircle: testCircle.cpp Circle.o Shape.o Point2d.o
	@mkdir -p bin
	g++ -o bin/testCircle testCircle.cpp Circle.o Shape.o Point2D.o

bin/testDrawing: testDrawing.cpp Circle.o Shape.o Point2d.o Drawing.o Rectangle.o
	@mkdir -p bin
	g++ -o bin/testDrawing testDrawing.cpp Drawing.o Circle.o Rectangle.o Point2D.o Shape.o

clean:
	rm -rf *.o *.gcf bin

