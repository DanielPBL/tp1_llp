HDR_DIR = header
HEADER = $(addprefix -I,$(HDR_DIR))
CCOPTION = g Wall Werror Wextra
FLAGS = $(addprefix -,$(CCOPTION))
CC = g++
OBJ_DIR = obj
OBJ = main.o scanner.o 
BUILD_DIR = build
SRC_DIR = /home/daniel/Dropbox/LLP/TP1/src

$(BUILD_DIR)/main.out: $(addprefix $(OBJ_DIR)/,$(OBJ)) 
	 $(CC) $(FLAGS) $(addprefix $(OBJ_DIR)/,$(OBJ)) -o $(BUILD_DIR)/main.out 

$(OBJ_DIR)/main.o: $(SRC_DIR)/main.cpp 
	 $(CC) $(FLAGS) -c $(SRC_DIR)/main.cpp -o $(OBJ_DIR)/main.o $(HEADER)

$(OBJ_DIR)/scanner.o: $(SRC_DIR)/scanner.cpp 
	 $(CC) $(FLAGS) -c $(SRC_DIR)/scanner.cpp -o $(OBJ_DIR)/scanner.o $(HEADER)


clean: 
	rm $(OBJ_DIR)/*.o
	rm $(BUILD_DIR)/*.out
