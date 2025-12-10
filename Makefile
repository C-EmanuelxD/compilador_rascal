SRC_DIR = src

# Detecção de Windows (adiciona .exe se for Windows)
ifdef OS
   EXT = .exe
else
   EXT = 
endif

# Definições de Compilador
CXX = g++
CXXFLAGS = -std=c++17 -I$(SRC_DIR) -Wno-write-strings

# Arquivos gerados por Flex e Bison
ANALISADOR_LEX  = $(SRC_DIR)/lex.yy.c
PARSER_C        = $(SRC_DIR)/rascal.tab.c
PARSER_H        = $(SRC_DIR)/rascal.tab.h

# Arquivos fontes do projeto (C++)
# ATUALIZADO: Adicionado gerador_mepa.cpp na lista
CPP_SOURCES     = $(SRC_DIR)/main.cpp \
                  $(SRC_DIR)/ast.cpp \
                  $(SRC_DIR)/printer.cpp \
                  $(SRC_DIR)/visitador_semantico.cpp \
                  $(SRC_DIR)/gerador_mepa.cpp

# Arquivos de entrada das ferramentas
LEXICO_L = $(SRC_DIR)/rascal.l
PARSER_Y = $(SRC_DIR)/rascal.y

# Target final (Executável)
TARGET = $(SRC_DIR)/rascal$(EXT)

# Define um arquivo de teste padrão caso ARGS não seja passado
ARGS ?= testes_rascal/errosemantico10.ras

# ==========================================
# REGRAS
# ==========================================

all: $(TARGET)

$(TARGET): $(PARSER_C) $(ANALISADOR_LEX) $(CPP_SOURCES)
	@echo "Compilando tudo..."
	$(CXX) $(CXXFLAGS) $(CPP_SOURCES) $(PARSER_C) $(ANALISADOR_LEX) -o $(TARGET)
	@echo "Build completo! Executavel gerado em: $(TARGET)"

$(ANALISADOR_LEX): $(LEXICO_L) $(PARSER_H)
	flex -o $(ANALISADOR_LEX) $(LEXICO_L)

$(PARSER_C) $(PARSER_H): $(PARSER_Y)
	bison -d $(PARSER_Y) -o $(PARSER_C)

clean:
	@rm -f $(ANALISADOR_LEX) $(TARGET) $(PARSER_C) $(PARSER_H) *.mep
	@echo "Limpeza concluida!"

run: $(TARGET)
	@echo "--- Executando o Parser ---"
	./$(TARGET) $(ARGS)

.PHONY: all clean run