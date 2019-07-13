
CC		:= gcc
CFLAGS  := -Wall -Wextra -g
BIN		:= bin
SRC		:= src

# 下面三个没有用
INCLUDE	:= include
LIB		:= lib
LIBRARIES	:=

# 指定生成的文件名称
ifeq ($(OS),Windows_NT)
EXEC	:= main.exe
else
EXEC	:= main
endif




all:$(BIN)/$(EXEC)

run:all
	$(BIN)/$(EXEC) 

clean:
	rm -rf $(BIN)/$(EXEC)

$(BIN)/$(EXEC):$(SRC)/*
	gcc $^ -o $@  $(CFLAGS)
	