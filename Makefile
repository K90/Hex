##
# Raylib
#
# @file
# @version 0.1
GCC := g++-16
GCCFLAGS := -std=c++23 -fmodules -Wall -Wextra -Wpedantic -Wconversion -Wshadow -Werror -time
LDFLAGS := -Lvendor/raylib
LDLIBS := -lraylib -lGL -lm -lpthread -ldl -lrt -lX11
main: main.cpp
	$(GCC) $(GCCFLAGS) main.cpp -o main $(LDFLAGS) $(LDLIBS)

run: main
	./main

# end
