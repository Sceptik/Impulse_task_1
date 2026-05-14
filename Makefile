CXX      := g++
CXXFLAGS := -std=c++17 -O2 -Wall -Wextra -Iinclude

SRC_DIR  := src
BIN      := qam_simulation

SRCS := $(SRC_DIR)/main.cpp \
        $(SRC_DIR)/qam_demodulator.cpp \
        $(SRC_DIR)/qam_modulator.cpp \
        $(SRC_DIR)/awgn.cpp \
        $(SRC_DIR)/utils.cpp

all: $(BIN)

$(BIN): $(SRCS)
	$(CXX) $(CXXFLAGS) -o $@ $^

clean:
	rm -f $(BIN)

run: $(BIN)
	./$(BIN)

.PHONY: all clean run