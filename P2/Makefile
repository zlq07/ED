SRC = src
INC = include

OBJ = obj
BIN = bin
CXX = g++
CPPFLAGS = -Wall -g  -I$(INC) -c --std=c++11 
all:$(BIN)/test $(BIN)/tipo_texto

# ************ Generación de documentación ******************
documentacion:
	doxygen doc/doxys/Doxyfile

	
# ************ Compilación de módulos ************

$(BIN)/test: $(OBJ)/test.o $(OBJ)/palabra.o $(OBJ)/palabras.o
	$(CXX) -o $(BIN)/test $(OBJ)/test.o $(OBJ)/palabra.o $(OBJ)/palabras.o 

$(BIN)/test1: $(OBJ)/test1.o $(OBJ)/palabra.o 
	$(CXX) -o $(BIN)/test1 $(OBJ)/test1.o $(OBJ)/palabra.o 

$(BIN)/tipo_texto: $(OBJ)/tipo_texto.o $(OBJ)/palabra.o $(OBJ)/palabras.o
	$(CXX) -o $(BIN)/tipo_texto $(OBJ)/tipo_texto.o $(OBJ)/palabra.o $(OBJ)/palabras.o 

$(OBJ)/tipo_texto.o: $(SRC)/tipo_texto.cpp $(INC)/palabra.h $(INC)/palabras.h
	$(CXX) $(CPPFLAGS)  $(SRC)/tipo_texto.cpp -o  $(OBJ)/tipo_texto.o 

$(OBJ)/test.o: $(SRC)/test.cpp $(INC)/palabra.h $(INC)/palabras.h 
	$(CXX) $(CPPFLAGS)  $(SRC)/test.cpp -o  $(OBJ)/test.o 
	
$(OBJ)/test1.o: $(SRC)/test.cpp $(INC)/palabra.h 
	$(CXX) $(CPPFLAGS)  $(SRC)/test.cpp -o  $(OBJ)/test1.o 
	
$(OBJ)/palabra.o: $(SRC)/palabra.cpp $(INC)/palabra.h $(INC)/vd.h $(SRC)/vd.cpp 
	$(CXX) $(CPPFLAGS)  $(SRC)/palabra.cpp -o  $(OBJ)/palabra.o 
		
$(OBJ)/palabras.o: $(SRC)/palabras.cpp $(INC)/palabras.h $(INC)/palabra.h $(INC)/vd.h $(SRC)/vd.cpp 
	$(CXX) $(CPPFLAGS)  $(SRC)/palabras.cpp -o  $(OBJ)/palabras.o	

# ************ Limpieza ************
clean :
	-rm $(OBJ)/* $(SRC)/*~ $(INC)/*~ ./*~

mrproper : clean
	-rm $(BIN)/* doc/html/*




