#**************************************************
# 「cuda01.cu」をコンパイルしたいときに使うmakefile
#
#--------------------------------------------
#  ・ファイル名の設定は10行目の「SRC=」
#  ・コンパイルオプションは15行目の「CFLAG+=」
#  ・16行目以降の「#」を消すとコンパイルオプションを追加
#**************************************************

SRC  = cuda01
CFLAG=

#--[ コンパイルオプションの設定 ]-----------------------

CFLAG += -lm -O3
#CFLAG += -g -G
#CFLAG += -pthread
#CFLAG += -fopenmp

#--[ deviceからprint関数を利用するためのオプション ]----

HOST_NAME = $(shell hostname)
GFLAG = -arch=sm_53 --ptxas-options=-v

ifeq ($(HOST_NAME), wss11)
	GFLAG = -arch=sm_61 --ptxas-options=-v
endif
ifeq ($(HOST_NAME), wss12)
	GFLAG = -arch=sm_61 --ptxas-options=-v
endif
ifeq ($(HOST_NAME), wss14)
	GFLAG = -arch=sm_86 --ptxas-options=-v
endif
ifeq ($(HOST_NAME), wss15)
	GFLAG = -arch=sm_70 --ptxas-options=-v
endif

#========================

$(SRC) : $(SRC).cu
	nvcc -o $@ $< $(CFLAG) $(GFLAG) 

#========================
# .cu拡張子でカラースキームが働かない場合は.cで編集しても大丈夫
%.cu: %.c
	cp $< $@
