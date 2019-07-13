
CC		:= gcc
# 指定了提示错误的级别，-g表示要进行debug，在发布的时候，可以将-g给去掉．
CFLAGS  := -Wall -Wextra -g
BIN		:= bin
SRC		:= src

# 下面三个现在还没有用
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

# 将src下的文件都编译了
$(BIN)/$(EXEC):$(SRC)/*
	gcc $^ -o $@  $(CFLAGS)
	