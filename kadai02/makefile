#*******************************************
# cuda2.cu またはcuda2.cをコンパイルしたいときに使うmakefile
#
#--------------------------------------------
# ファイル名の設定は9行目の「SRC=」から
# 
#*******************************************

SRC = cuda2
CFLAGS=
CFLAG=

#--[ 設定反映 ]-----------------------------
HOST_NAME = $(shell hostname)
CFLAG += -lm -O3
#CFLAG += -g -G
#CFLAG += -pthread
#CFLAG += -fopenmp

# deviceからprint関数を利用するためのオプション
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
cuda2 : $(SRC).cu
	nvcc -o $@ $< $(CFLAG) $(GFLAG) 

#========================
%.cu: %.c
	cp $< $@
