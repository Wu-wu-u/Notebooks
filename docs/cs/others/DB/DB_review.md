# 数据库复习

## 确定不考的东西

- Embedded SQL，ODBC/JDBC, trigger, function都不考

## 题型

## 暗示

- 类似12306购票的ER图？


## 其他

19道多选 + 3道大题

--- 


1002: <T1, 6001.1, 11, 22>
1003: <T2, begin>
1004: <T2, 6001.2, 33, 44>
1005: <T3, begin>
1006: <T3, 6002.1, 55, 66>
1007: <T1 commit>
1008: <T2, 6001.3, 88, 99>
1009: checkpoint
|Txn|LastLSN|
|---|-----|
|T2|1008|
|T3|1006|

|PageId|PageLSN|RecLSN|
|-----|-------|-------|
|6001|1008|?|
|6002|1006|1006|

1010: <T3, 6002.2, 66, 77>
1011: <T3, 6003.1, 11, 22>
1012: <T2 commit>

问题：
1. What is the possible RecLSN for page 6001 in the dirty page table?

A. 1002
B. 1004
C. 1008
D. LSN less than 1002
E. 1009

2. During analysis phase, which of the following disk data pages will be read into the buffer?

A. 6001
B. 6002
C. 6003
D. none of 6001, 6002, 6003
E. none of some or all of 6001, 6002, 6003

3. During redo phase, which of the following disk data pages will be updated?

A. 6001
B. 6002
C. 6003
D. none of 6001, 6002, 6003
E. none of some or all of 6001, 6002, 6003

4. During undo phase, which of the following disk data pages will be updated?

A. 6001
B. 6002
C. 6003
D. none of 6001, 6002, 6003
E. none of some or all of 6001, 6002, 6003
