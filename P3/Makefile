SRC = src
INC = include

OBJ = obj
BIN = bin
CXX = g++
CPPFLAGS = -Wall -g  -I$(INC) -c --std=c++11 
all:$(BIN)/test1

# ************ Generación de documentación ******************
documentacion:
	doxygen doc/doxys/Doxyfile

	
# ************ Compilación de módulos ************

$(BIN)/test: $(OBJ)/test.o $(OBJ)/palabra.o $(OBJ)/palabras.o
	$(CXX) -o $(BIN)/test $(OBJ)/test.o $(OBJ)/palabra.o $(OBJ)/palabras.o 

$(BIN)/test1: $(OBJ)/test1.o $(OBJ)/palabra.o 
	$(CXX) -o $(BIN)/test1 $(OBJ)/test1.o $(OBJ)/palabra.o 


$(OBJ)/test.o: $(SRC)/test.cpp $(INC)/palabra.h $(INC)/palabras.h 
	$(CXX) $(CPPFLAGS)  $(SRC)/test.cpp -o  $(OBJ)/test.o 
	
$(OBJ)/test1.o: $(SRC)/test.cpp $(INC)/palabra.h 
	$(CXX) $(CPPFLAGS)  $(SRC)/test.cpp -o  $(OBJ)/test1.o 
	
$(OBJ)/palabra.o: $(SRC)/palabra.cpp $(INC)/palabra.h  
	$(CXX) $(CPPFLAGS)  $(SRC)/palabra.cpp -o  $(OBJ)/palabra.o 
		
$(OBJ)/palabras.o: $(SRC)/palabras.cpp $(INC)/palabras.h $(INC)/palabra.h 
	$(CXX) $(CPPFLAGS)  $(SRC)/palabras.cpp -o  $(OBJ)/palabras.o	


$(OBJ)/traductor.o: $(SRC)/traductor.cpp $(INC)/traductor.h $(INC)/palabras.h $(INC)/palabra.h 
	$(CXX) $(CPPFLAGS)  $(SRC)/traductor.cpp -o  $(OBJ)/traductor.o	

$(OBJ)/conca_traductor.o: $(SRC)/conca_traductor.cpp $(INC)/traductor.h 
	$(CXX) $(CPPFLAGS)  $(SRC)/conca_traductor.cpp -o  $(OBJ)/conca_traductor.o	


$(BIN)/conca_traductor: $(OBJ)/conca_traductor.o $(OBJ)/palabra.o $(OBJ)/palabras.o $(OBJ)/traductor.o
	$(CXX) -o $(BIN)/conca_traductor $(OBJ)/conca_traductor.o $(OBJ)/palabra.o $(OBJ)/palabras.o $(OBJ)/traductor.o


# ************ Limpieza ************
clean :
	-rm $(OBJ)/* $(SRC)/*~ $(INC)/*~ ./*~

mrproper : clean
	-rm $(BIN)/* doc/html/*




