* 20190908:
+ 同62题
+ obstacleGrid[i][j]为1时，f[i*col+j] 刷为0，表示道路不通
+ 结果为f[row*col-1]
+ 缺点是空间占用比较大。
+ 使用int会有signed interge overflow, 改为unsigned int
+ 需要先判断障碍，比如用例[[1]]
