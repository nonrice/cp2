.PHONY: run runi flags

CXX = clang++
CXXFLAGS_DBG = -gdwarf-4 -O0 -fno-omit-frame-pointer -fsanitize=address -fsanitize=undefined -DLOCAL
CXXFLAGS = $(CXXFLAGS_DBG) -std=c++23 -Wall -Wextra -Wpedantic -Wfloat-equal -Wconversion -Wshift-overflow -Wcast-qual -Wcast-align

flags: Makefile
	rm -f compile_flags.txt
	for flag in $(CXXFLAGS); do \
		echo "$$flag" >> compile_flags.txt; \
	done

FILE ?= a.cpp
EXT = $(suffix $(FILE))
BIN = /tmp/$(notdir $(basename $(FILE)))

$(BIN): $(FILE) Makefile
	$(CXX) $(CXXFLAGS) $(FILE) -o $(BIN)

run: $(BIN) 
	$(BIN) $@ < ~/.in.txt

runi: $(BIN)
	$(BIN) $@



