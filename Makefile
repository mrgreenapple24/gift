# --- Compiler settings ---
CC      := gcc
CFLAGS  := -Wall -Wextra -Iinclude
LDFLAGS := 

# --- Project structure ---
SRC_DIR := commands
OBJ_DIR := build
BIN     := gift

# --- Source files ---
SRCS := gift.c $(wildcard $(SRC_DIR)/*.c)
OBJS := $(patsubst %.c, $(OBJ_DIR)/%.o, $(SRCS))

# --- Default target ---
all: $(BIN)

# --- Link executable ---
$(BIN): $(OBJS)
	@echo "🔗 Linking $@"
	$(CC) $(CFLAGS) -o $@ $(OBJS) $(LDFLAGS)

# --- Compile each .c file into build/ directory ---
$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	@echo "🧱 Compiling $<"
	$(CC) $(CFLAGS) -c $< -o $@

# --- Clean build artifacts ---
clean:
	@echo "🧹 Cleaning up..."
	rm -rf $(OBJ_DIR) $(BIN)

# --- Run the program ---
run: all
	./$(BIN)

.PHONY: all clean run

