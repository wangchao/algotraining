* 20190908:
+ 每个点i对应坐标为y*m+x
+ f[i]记录为从start点到i点的路径数量
+ 非第一列时，到达f[i]的路径数量包含f[i-1]: 从左边的点移动过来。
+ 非第一行时，到达f[i]的路径数量包含i点同列上一行的路径数量：从上方的点移动过来。
+ 结果为f[m*n-1]
+ 缺点是空间占用比较大。