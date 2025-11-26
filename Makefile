
SRC_DIR = src

# Arquivos gerados
PARSER_C = $(SRC_DIR)/rascal.tab.c
PARSER_H = $(SRC_DIR)/rascal.tab.h
LEX_C    = $(SRC_DIR)/lex.yy.c

# Arquivos de entrada
YFILE = $(SRC_DIR)/rascal.y
LFILE = $(SRC_DIR)/rascal.l


TARGET = rascal



all: $(TARGET)

$(TARGET): $(PARSER_C) $(LEX_C)
	@gcc -o $(TARGET) $(PARSER_C) $(LEX_C) -I$(SRC_DIR) -lfl
	@echo "✔ Build completo: ./$(TARGET)"


$(PARSER_C) $(PARSER_H): $(YFILE)
	@bison -d $(YFILE) -o $(PARSER_C)
	@echo "✔ Bison gerou: rascal.tab.c / rascal.tab.h"


$(LEX_C): $(LFILE) $(PARSER_H)
	@flex -o $(LEX_C) $(LFILE)
	@echo "✔ Flex gerou: lex.yy.c"


clean:
	@rm -f $(PARSER_C) $(PARSER_H) $(LEX_C) $(TARGET)
	@echo "✔ Limpeza realizada"



run: $(TARGET)
	@./$(TARGET)

.PHONY: all clean run
