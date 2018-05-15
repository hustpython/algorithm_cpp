# coding:utf-8

# 可支配的总人数
total_people_num = 0
# 金矿总数
total_mine_num = 0
# 开采每个金矿所需的人数列表
needed_people_num = []
# 开采每个金矿可以获取到的金子数列表
gold_num = []
# 缓存数组，是一个二维数组，有total_people_num+1行，total_mine_num+1列
# 使用缓存数组是为了减少重复计算，cache[i][j]表示用i个人开采第0~j座金矿一共能开采到的金子总数最大值
# cache的所有元素都在一开始被初始化为-1，表示未知
# cache的使用可以极大地提高效率，减少很多重复计算
cache = []

# 初始化数据
def init():
    global total_people_num
    global total_mine_num
    global needed_people_num
    global gold_num
    global cache

    # 从gold.in文件中读取数据
    '''
    文件内容：
    100 5
    77 92
    22 22
    29 87
    50 46
    99 90
    '''
    datas = []
    with open('gold.in','r') as f_in:
        datas = f_in.readlines()

    # 解析出总人数和金矿数
    line1 = datas[0]
    total_people_num = int(line1.split()[0])
    total_mine_num = int(line1.split()[1])

    # 解析出needed_people_num和gold_num列表
    for line in datas[1:]:
        needed_people_num.append(int(line.split()[1]))
        gold_num.append(int(line.split()[0]))

    # 初始化cache数组，下面这种方式是有问题的：
    # cache_row = [-1] * (total_mine_num + 1)
    # cache = [cache_row] * (total_people_num + 1)
    # 要用这种方式（为了防止数组越界，都加了1）：
    cache = [([-1] * (total_mine_num + 1)) for i in range(total_people_num + 1)]

# 求最大金子数的函数
# get_max_gold_num(i,j)表示用i个人开采第0~j座金矿可以开采到的最大金子总数
def get_max_gold_num(people_n,mine_n):
    max_num = 0

    # 1. 如果缓存数组中有对应值，直接从中取
    if cache[people_n][mine_n] != -1:
        max_num = cache[people_n][mine_n]
    # 2. 如果只开采第0座金矿
    elif mine_n == 0:
        # 2.1 如果人数小于开采第0座金矿所需人数，那么结果就是0
        if people_n < needed_people_num[mine_n]:
            max_num = 0
        # 2.2 否则最终结果就是开采第0座金矿所能获取到的金子数     
        else:
            max_num = gold_num[mine_n]
    # 3. 如果不是第0座金矿且人数足够开采第mine_n座金矿，那么取下面两种开采策略所能获取到的最大金子数的较大值
    elif people_n >= needed_people_num[mine_n]:
        # 用people_n个人去开采第0~mine_n - 1座金矿所能获取到的最大金子数
        m = get_max_gold_num(people_n,mine_n - 1)
        # 用people_n个人去开采第0~mine_n座金矿所能获取到的金子数的最大值
        n = gold_num[mine_n] + get_max_gold_num(people_n - needed_people_num[mine_n],mine_n - 1)
        max_num = max(m,n)
    # 4. 如果不是第0座金矿且人数不够开采第mine_n座金矿，那只能采取第一种策略了：使用people_n个人开采其他的mine_n - 1座金矿
    else:
        max_num = get_max_gold_num(people_n,mine_n - 1)

    # 5. 给缓存数组对应元素赋值
    cache[people_n][mine_n] = max_num
    return max_num

def main():
    init()
    print(get_max_gold_num(total_people_num,total_mine_num - 1))

main()