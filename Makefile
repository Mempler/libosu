CC=gcc
BUILD=build
ARGS=-Iinclude -Wall -O3

CUSTOM_ARGS=

all : clean make_dirs lib

lib : clean make_dirs
	@$(CC) -c src/buffer.c -o $(BUILD)/buffer.o $(ARGS) $(CUSTOM_ARGS)
	@$(CC) -c src/packet.c -o $(BUILD)/packet.o $(ARGS) $(CUSTOM_ARGS)
	@$(CC) -c src/_packets.c -o $(BUILD)/_packets.o $(ARGS) $(CUSTOM_ARGS)
	@$(CC) -c src/_data.c -o $(BUILD)/_data.o $(ARGS) $(CUSTOM_ARGS)

	@ar rcs build/libosu.a $(BUILD)/buffer.o $(BUILD)/packet.o $(BUILD)/_packets.o $(BUILD)/_data.o

make_dirs : clean
	@mkdir -p $(BUILD)

clean :
	@rm -rf $(BUILD)
