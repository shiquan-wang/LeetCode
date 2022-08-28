import math
import pandas
import numpy as npdef kmeans(k):


    m, n = 100, 20#样本构造， 100行20列
    x = 10 * np.random.random(m, n)#训练集

    #创建k个初始点作为初始中心点
    init_cent_sample = set()
    while len(init_cent_sample) < k:
        init_cent_sample.add(np.random.random(0, m))# [low, high)  # 中心点/质心 在这里仅用其idx表示，后面还会处
    
    # 保存簇中心点（聚类中心点），k个聚类中心点（每个中心点都是一个n维的向量）
    cent_pos = x[list(init_cent_sample)]#第i个质心的坐标为：cent_pos[i]

    # 记录每个样本的类归属和（距离其所属簇质心的）距离    [每个样本所归属的簇中心点idx， 该样本距离此簇中心点的距离]
    sample_belong_to = np.zeros((m, 2))
    # 记录每个类的中心点在本次迭代后是否有过改变
    cent_changed = True
    # 当任意一个点的簇分配结果发生改变时
    while cent_changed:
        cent_changed = False

        # 对数据集中的每个样本点
        for i in range(m):
            # 记录每个样本距离最近的类
            min_idx = -1
            # 记录每个样本的最小类距
            min_dist = math.inf

            # 对数据集中的每个数据点，计算其与k个质心的距离
            for j in range(k):
                d = distance(x[i], cent_pos[j])
                if d < min_dist:
                    min_idx = j
                    min_dist = d

            # 记录此样本（即第i个样本）所对应的中心点是否发生变化（只有所有样本所归属的簇类中心点都不变时，才停止迭代）
            if min_idx != sample_belong_to[i][0]:
                sample_belong_to[i] = np.array([min_idx, min_dist])  # [每个样本所归属的簇中心点idx， 该样本距离此簇中心点的距离]
                cent_changed = True

        print(sample_belong_to)

        # 更新每个类/簇的中心点：均值
        for i in range(k):
            samples_of_curr_cluster = np.where(sample_belong_to[:, 0] == i)  # 只有条件(condition)，没有x和y，则输出满足条件（即非0）元素的坐标（等价于numpy.nonzero）。
            if len(samples_of_curr_cluster) > 0:
                print(samples_of_curr_cluster)
                cent_pos[i] = np.mean(x[samples_of_curr_cluster], axis = 0)


# 计算距离
def distance(a, b):
    return math.sqrt(sum(pow(a - b, 2)))
