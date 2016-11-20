DEBUG=yes

CC=g++
ifeq ($(DEBUG),yes)
    CFLAGS=-W -Wall -ansi -pedantic -I ../common/inc/ -I ./inc/ -g
else
    CFLAGS=-W -Wall -ansi -pedantic -I ../common/inc/ -I ./inc/
endif
    
LDFLAGS=
EXEC=release/t1
SRC=$(wildcard src/*.cpp ../common/src/*.cpp)
OBJ=$(SRC:.cpp=.o)
DEPS:=$(OBJ:.o=.d)
-include $(DEPS)

all: $(EXEC)
ifeq ($(DEBUG),yes)
	@echo "debug mode generation"
else
	@echo "release mode generation"
endif
$(EXEC): $(OBJ)
	@$(CC) -o $@ $? $(LDFLAGS)  ##$@ est le target , release/t1 dans ce cas. $? est la liste des dependences + recente que le target

../common/src/appli.o: ../common/src/appli.cpp 
	@$(CC) $(CFLAGS) -MM -MT $@ -MF $(patsubst %.o,%.d,$@) $<
	@$(CC) -o $@ -c $< $(CFLAGS) ##$< nom de la premiere dependance

src/t1.o: src/t1.cpp
	@$(CC) $(CFLAGS) -MM -MT $@ -MF $(patsubst %.o,%.d,$@) $<
	@$(CC) -o $@ -c $< $(CFLAGS)  ##$< nom de la premiere dependance

clean:
	rm -rf src/*.o ../common/src/*.o

mrproper: clean
	rm -rf $(EXEC)

##http://gl.developpez.com/tutoriel/outil/makefile/

##output dir    http://stackoverflow.com/questions/1814270/gcc-g-option-to-place-all-object-files-into-separate-directory
##http://gl.developpez.com/tutoriel/outil/makefile/
##http://stackoverflow.com/questions/1139271/makefiles-with-source-files-in-different-directories
##test
