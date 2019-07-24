CC      := gcc
BIN		:= bin
SRC		:= src


CFLAGS := -Wall -W -O -g
LDLIBS := 

# 从外部传入一个文件名字，进行编译, CFILES 是要编译的c文件，如果要编辑多个c，那么就要通过if判断，来生成多个c编译内容．
F  :=first
CFILES :=$(F).c

# 判断文件名如果等于first，就需要添加一个进程的包
ifeq ($(F),first)
	LDLIBS += -lpthread
endif	


.PHONY : all


all:$(BIN)/$(F)
	@echo "\nmake all ok:" $(BIN)/$(F)

run:all
	$(BIN)/$(F) 

clean:
	rm -rf $(BIN)/$(F)
	@echo "clean ok"

cleanAll:
	rm -rf $(BIN)/*
	@echo "clean all ok"	
	
$(BIN)/$(F):$(SRC)/$(CFILES)
	$(CC) $^  $(CFLAGS) $(LDLIBS)   -o $@ 