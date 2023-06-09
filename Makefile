# Premier Makefile

all: cpp java salut.dll

cpp: hello.exe hello2.exe

java: Hello.class

hello.exe: hello.o
	g++ -o hello.exe hello.o

hello.o: hello.cpp
	g++ -c hello.cpp

hello2.exe: hello2.o
	g++ -o hello2.exe hello2.o

hello2.o: hello2.cpp
	g++ -c hello2.cpp

Hello.class: Hello.java
	javac Hello.java

clean:
	rm -f *.class *.o *.exe
