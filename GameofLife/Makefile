GameofLife: main.o generator.o rules.o grid.o genpng.o lodepng.o txt.o
	gcc main.o generator.o rules.o grid.o genpng.o lodepng.o txt.o -o GameofLife

main.o: main.c
	gcc -c main.c -o main.o

generator.o: generator.c rules.o
	gcc -c generator.c -o generator.o
 
rules.o: rules.c
	gcc -c rules.c -o rules.o

grid.o: grid.c
	gcc -c grid.c -o grid.o
	
genpng.o: genpng.c
	gcc -c genpng.c -o genpng.o

lodepng.o: lodepng.c
	gcc -c lodepng.c -o lodepng.o
txt.o: txt.c
	gcc -c txt.c -o txt.o