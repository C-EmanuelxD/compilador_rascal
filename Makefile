SRC_DIR = src

# Detecção de Windows (adiciona .exe se for Windows)
ifdef OS
   EXT = .exe
else
   EXT = 
endif

# Arquivos gerados
ANALISADOR_LEX    = $(SRC_DIR)/lex.yy.c
PARSER            = $(SRC_DIR)/rascal.tab.c
PARSER_H          = $(SRC_DIR)/rascal.tab.h

# Arquivos de entrada
LEXICO_L = $(SRC_DIR)/rascal.l
PARSER_Y = $(SRC_DIR)/rascal.y

# Target final (Executável)
TARGET = $(SRC_DIR)/rascal$(EXT)

# Define um arquivo de teste padrão caso ARGS não seja passado
ARGS ?= testes_rascal/correto01.ras

all: $(TARGET)

# Build do Compilador (Linking)
$(TARGET): $(ANALISADOR_LEX) $(PARSER)
	@echo "Compilando tudo..."
	gcc $(PARSER) $(ANALISADOR_LEX) -o $(TARGET) -I $(SRC_DIR)
	@echo "Build completo! Executavel gerado em: $(TARGET)"

# Build do Léxico (Flex)
$(ANALISADOR_LEX): $(LEXICO_L) $(PARSER_H)
	flex -o $(ANALISADOR_LEX) $(LEXICO_L)

# Build do Parser (Bison)
# O Bison gera o .c E o .h (que o flex precisa)
$(PARSER) $(PARSER_H): $(PARSER_Y)
	bison -d $(PARSER_Y) -o $(PARSER)

clean:
	@rm -f $(ANALISADOR_LEX) $(TARGET) $(PARSER) $(PARSER_H)
	@echo "Limpeza concluida!"

# Regra de execução
# O '-' antes de $(TARGET) ignora erros de retorno do programa (caso seu main retorne 1)
run: $(TARGET)
	@echo "--- Executando o Parser ---"
	./$(TARGET) $(ARGS)

.PHONY: all clean run