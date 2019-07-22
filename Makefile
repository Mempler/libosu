CC=gcc
BUILD=build
ARGS=-Iinclude -Wall -g#-O3

all : clean make_dirs lib

lib : clean make_dirs
	@$(CC) -c src/buffer.c -o $(BUILD)/buffer.o $(ARGS)
	@$(CC) -c src/packet.c -o $(BUILD)/packet.o $(ARGS)
	@$(CC) -c src/_packets.c -o $(BUILD)/_packets.o $(ARGS)

	@ar rcs build/libosu.a $(BUILD)/buffer.o $(BUILD)/packet.o $(BUILD)/_packets.o 

make_dirs : clean
	@mkdir -p $(BUILD)

clean :
	@rm -rf $(BUILD)
