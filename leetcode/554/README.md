* 20190901
cut each row with 1 and paint, then loop for each col. not work for
+ wall width maybe very high
+ lost O(1) cap to find lap of each row
+ may alloc plenty of memory

another work way:
+ loop for each row and lap
+ use lap postion, loop for other row to see if it's cut through or also lap
+ default to row size, if less than it, update the count
+ no extra space, but time performace is low
