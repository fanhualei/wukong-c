CC      := gcc
BIN		:= bin
SRC		:= src

# 使用pkg-config得到ffmpeg的头文件与lib
FFMPEG_LIBS=    libavdevice                        \
                libavformat                        \
                libavfilter                        \
                libavcodec                         \
                libswresample                      \
                libswscale                         \
                libavutil                          \
# CFLAGS例如：-I/usr/local/include -Wall -g
# https://www.jianshu.com/p/70858c4e6f5e
# LDLIBS例如：-L/usr/local/lib -lavdevice -lm -ldl -lz -pthread -lavfilter -lm -ldl -lz -pthread -lavformat -lm -ldl -lz -pthread -lavcodec -lm -ldl -lz -pthread -lswresample -lm -lswscale -lm -lavutil -lm

CFLAGS := $(shell pkg-config --cflags $(FFMPEG_LIBS))
CFLAGS += -Wall -g
LDLIBS := $(shell pkg-config --libs $(FFMPEG_LIBS)) $(LDLIBS)

# 从外部传入一个文件名字，进行编译, CFILES 是要编译的c文件，如果要编辑多个c，那么就要通过if判断，来生成多个c编译内容．
F  :=avio_dir_cmd
CFILES :=$(F).c


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
