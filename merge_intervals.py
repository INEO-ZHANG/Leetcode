
from typing import List

class Solution:
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:
        intervals_sorted = sorted(intervals, key = lambda x: x[0])
        flag = 0
        curleft = 0
        while flag != -1:
            if curleft >= len(intervals_sorted):
                break
            flag = -1
            poplist = []
            n = len(intervals_sorted)
            curmax = intervals_sorted[curleft][1]
            for i in range(curleft + 1,n):
                if intervals_sorted[i][0] <= curmax:
                    curmax = max(intervals_sorted[i][1],curmax)
                    poplist.append(i)
                    if flag == -1:
                        flag = i - 1
                        curleft = i - 1
                elif flag != -1:
                    #合并一次
                    break
                elif flag == -1:
                    curmax = intervals_sorted[i][1]
            if flag != -1:
                intervals_sorted[flag][1] = curmax
                poplist_len = len(poplist)
                for j in range(poplist_len - 1, -1,-1):
                    intervals_sorted.pop(poplist[j])
 
        return intervals_sorted
    
def main():
    intervals = [[2,3],[2,2],[3,3],[1,3],[5,7],[2,2],[4,6]]
    sol = Solution()
    print(sol.merge(intervals))

if __name__ == "__main__":
    main()