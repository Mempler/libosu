CC=gcc
BUILD=build
ARGS=-Iinclude -Wall -O3

all : clean make_dirs lib

lib : clean make_dirs
	@$(CC) -c src/buffer.c -o $(BUILD)/buffer.o $(ARGS)
	@$(CC) -c src/packet.c -o $(BUILD)/packet.o $(ARGS)

	@ar rcs build/libosu.a $(BUILD)/buffer.o $(BUILD)/packet.o

make_dirs : clean
	@mkdir -p $(BUILD)

clean :
	@rm -rf $(BUILD)
