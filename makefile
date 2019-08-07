#	Compiler:
CC	= g++
CPPFLAGS = -I$(IDIR) -Wall -Wextra -Wno-unused

#	Source files, Headers, etc...:
LIBS	=
IDIR 	=	include
VPATH	=	src

DEPS	=	Cell.h ObserverBase.h ObserverBoard.h \
		ObserverBox.h ObserverColumn.h ObserverFill.h \
		ObserverRow.h ObserverSudoku.h SubjectBase.h \
		SubjectSudoku.h SudokuParser.h

OBJ	=	Cell.o ObserverBase.o ObserverBoard.o \
		ObserverBox.o ObserverColumn.o ObserverFill.o \
		ObserverRow.o ObserverSudoku.o SubjectBase.o \
		SubjectSudoku.o SudokuParser.o Main.o

#	Product:
%.o: %.c $(DEPS)
	$(CC) $(CPPFLAGS) -c -o $@ $<
SolveDoku.exe: $(OBJ)
	$(CC) -o $@ $^ $(CPPFLAGS) $(LIBS)
clean:
	$(RM) $(OBJ)
