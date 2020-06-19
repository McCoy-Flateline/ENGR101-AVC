SFML = /home/INSERT_USERNAME_HERE/Downloads/SFML/SFML-2.5.1
CFLAGS = -I ${SFML}/include
LFLAGS = -L ${SFML}/lib -Wl,-R ${SFML}/lib
LIBS = -lsfml-window  -lsfml-graphics -lsfml-system -lsfml-network
robot: robot.o
	g++ $(LFLAGS) -o robot robot.o ${LIBS}
robot.o: robot.cpp
	g++  -c $(CFLAGS) robot.cpp
