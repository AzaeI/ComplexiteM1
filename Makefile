CC = gcc

INCLUDE = -I/usr/local/include -I/usr/include -I ./header
CCFLAGS = -Wall -W -std=c99

all: algo1 algo2 algo3 algo4 EvalTime

algo1: ./src/algo1.c ./src/util.c ./src/startAlgo1.c
	$(CC) -o algo1 $(INCLUDE) ./src/startAlgo1.c ./src/algo1.c ./src/util.c $(CCFLAGS)

algo2: ./src/algo2.c ./src/util.c ./src/startAlgo2.c
	$(CC) -o algo2 $(INCLUDE) ./src/algo2.c ./src/util.c ./src/startAlgo2.c $(CCFLAGS)

algo3: ./src/algo3.c ./src/util.c ./src/startAlgo3.c
	$(CC) -o algo3 $(INCLUDE) ./src/algo3.c ./src/util.c ./src/startAlgo3.c $(CCFLAGS)

algo4: ./src/algo4.c ./src/util.c ./src/startAlgo4.c
	$(CC) -o algo4 $(INCLUDE) ./src/algo4.c ./src/util.c  ./src/startAlgo4.c $(CCFLAGS)

EvalTime: ./src/main.c ./src/util.c  ./src/algo1.c ./src/algo2.c ./src/algo3.c ./src/algo4.c
	$(CC) -o EvalTime $(INCLUDE) ./src/main.c ./src/util.c ./src/algo1.c ./src/algo2.c ./src/algo3.c  ./src/algo4.c $(CCFLAGS)

clean:
	-rm *.o *~
	-rm algo1
	-rm algo2
	-rm algo3
	-rm algo4
	-rm EvalTime
