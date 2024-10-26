#********************************************************
#
# Python 並列処理(Pool)の実験プログラム
#
#---------------------------------------------------------
#
# 実行コマンド
# $python3 python.py
#
#********************************************************


from multiprocessing import Pool

#{{{
def function(arg_value):
    p_max, num = arg_value
    print(">> process", num, "/", p_max)
#}}}


if(__name__ == '__main__'):

    loop_num = 10
    p = Pool(loop_num)
    arg_value = [(loop_num , i) for i in range(loop_num)]
    tmp = p.map(function, arg_value)
    
    #p.terminate()
    #p.join()
