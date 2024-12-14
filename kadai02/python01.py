#********************************************************
#
# Python Poolの実験プログラム
#
#---------------------------------------------------------
#
# 実行コマンド
# $python3 python01.py
#
#********************************************************

import numpy as np
import os
from multiprocessing import Pool


#{{{
def function(arg_value):

    pool_num, num = arg_value
    print(">> PID:", os.getpid(), " arg_value:", num, "/", pool_num)

    return num
#}}}


if(__name__ == '__main__'):

    loop_num = 10
    pool_num = 4

    p = Pool(pool_num)
    arg_value = [(pool_num , i) for i in range(loop_num)]
    result = p.map(function, arg_value)
    print(">> result:", result)

    #p.terminate()
    #p.join()

