SRC = src
INC = include

OBJ = obj
BIN = bin
CXX = g++
CPPFLAGS = -Wall -g  -I$(INC) -c --std=c++11 
all:$(BIN)/worddance 

# ************ Generación de documentación ******************
documentacion:
	doxygen doc/doxys/Doxyfile

	
# ************ Compilación de módulos ************

$(BIN)/worddance: $(OBJ)/worddance.o $(OBJ)/palabra.o $(OBJ)/palabras.o $(OBJ)/estrategia.o $(OBJ)/utilidades.o $(OBJ)/jugador.o $(OBJ)/juego.o  $(OBJ)/ranking.o
	$(CXX) -o $(BIN)/worddance $(OBJ)/worddance.o $(OBJ)/palabra.o $(OBJ)/palabras.o $(OBJ)/estrategia.o $(OBJ)/utilidades.o $(OBJ)/jugador.o $(OBJ)/juego.o  $(OBJ)/ranking.o


$(OBJ)/worddance.o: $(SRC)/worddance.cpp $(INC)/palabras.h $(INC)/jugador.h $(INC)/juego.h   
	$(CXX) $(CPPFLAGS)  $(SRC)/worddance.cpp -o  $(OBJ)/worddance.o 
	
$(OBJ)/palabra.o: $(SRC)/palabra1.cpp $(INC)/palabra.h  
	$(CXX) $(CPPFLAGS)  $(SRC)/palabra1.cpp -o  $(OBJ)/palabra.o 
		
$(OBJ)/palabras.o: $(SRC)/palabras.cpp $(INC)/palabras.h $(INC)/palabra.h 
	$(CXX) $(CPPFLAGS)  $(SRC)/palabras.cpp -o  $(OBJ)/palabras.o	

$(OBJ)/estrategia.o: $(SRC)/estrategia.cpp $(INC)/estrategia.h $(INC)/utilidades.h  $(INC)/ArbolGeneral.h  $(INC)/ArbolGeneral.cpp 
	$(CXX) $(CPPFLAGS)  $(SRC)/estrategia.cpp -o  $(OBJ)/estrategia.o 

$(OBJ)/utilidades.o: $(SRC)/utilidades.cpp $(INC)/utilidades.h $(INC)/ArbolGeneral.h  $(INC)/ArbolGeneral.cpp 
	$(CXX) $(CPPFLAGS)  $(SRC)/utilidades.cpp -o  $(OBJ)/utilidades.o 


$(OBJ)/jugador.o: $(SRC)/jugador.cpp $(INC)/jugador.h $(INC)/estrategia.h
	$(CXX) $(CPPFLAGS)  $(SRC)/jugador.cpp -o  $(OBJ)/jugador.o


$(OBJ)/ranking.o: $(SRC)/ranking.cpp $(INC)/ranking.h 
	$(CXX) $(CPPFLAGS)  $(SRC)/ranking.cpp -o  $(OBJ)/ranking.o
$(OBJ)/juego.o: $(SRC)/juego.cpp $(INC)/juego.h $(INC)/jugador.h $(INC)/palabras.h
	$(CXX) $(CPPFLAGS)  $(SRC)/juego.cpp -o  $(OBJ)/juego.o


# ************ Limpieza ************
clean :
	-rm $(OBJ)/* $(SRC)/*~ $(INC)/*~ ./*~

mrproper : clean
	-rm $(BIN)/* doc/html/*




