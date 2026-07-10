.PHONY: run runi flags clangd

# CXX = g++-16
# CXX = clang++
BREW_LLVM = $(shell brew --prefix llvm)
CXX = $(BREW_LLVM)/bin/clang++

ifneq (,$(findstring clang++,$(CXX)))
	CXXFLAGS_DBG = -gdwarf-4 -O0 -fno-omit-frame-pointer -fsanitize=address -fsanitize=undefined -DLOCAL
	CXXFLAGS = $(CXXFLAGS_DBG) -std=c++23 -nostdinc++ -isystem$(BREW_LLVM)/include/c++/v1 -L$(BREW_LLVM)/lib/c++ -Wl,-rpath,$(BREW_LLVM)/lib/c++ -Wall -Wextra -Wpedantic -Wfloat-equal -Wconversion -Wshift-overflow -Wcast-qual -Wcast-align -isystem/usr/local/include/fakebits -isystem/usr/local/include
else ifneq (,$(findstring g++,$(CXX)))
	CXXFLAGS_DBG = -gdwarf-4 -O0 -D_GLIBCXX_DEBUG -D_GLIBCXX_DEBUG_PEDANTIC -fsanitize=undefined -fno-sanitize-recover -fstack-protector -DLOCAL -lstdc++exp
	CXXFLAGS = $(CXXFLAGS_DBG) -std=c++23 -stdlib=libstdc++ -Wall -Wextra -Wpedantic -Wshadow -Wformat=2 -Wfloat-equal -Wconversion -Wlogical-op -Wshift-overflow=2 -Wduplicated-cond -Wcast-qual -Wcast-align -Wno-variadic-macros -isystem/usr/local/include -isystem/opt/homebrew/Cellar/gcc/16.1.0/include/c++/16 -isystem/opt/homebrew/Cellar/gcc/16.1.0/include/c++/16/aarch64-apple-darwin24
endif

flags: Makefile
	rm -f compile_flags.txt
	for flag in $(CXXFLAGS); do \
		echo "$$flag" >> compile_flags.txt; \
	done

clangd: Makefile
	echo "CompileFlags:" > .clangd
	echo "  Add:" >> .clangd
	for flag in $(CXXFLAGS); do \
		echo "    - \"$$flag\"" >> .clangd; \
	done
	echo "  Compiler: $(CXX)" >> .clangd

FILE ?= a.cpp
EXT = $(suffix $(FILE))
BIN = /tmp/$(notdir $(basename $(FILE)))

$(BIN): $(FILE) Makefile
	$(CXX) $(CXXFLAGS) $(FILE) -o $(BIN)

run: $(BIN) 
	$(BIN) < /tmp/in.txt

runi: $(BIN)
	$(BIN)



