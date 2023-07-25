import sys, heapq
input = sys.stdin.readline
T = int(input())
for _ in range(T):
    q = int(input())
    di = {}
    heap1 = [] # 최소
    heap2 = [] # 최대
    for _ in range(q):
        a, num = input().split()
        num = int(num)
        if a == 'I':
            heapq.heappush(heap1, num)
            heapq.heappush(heap2, -num)
            if num in di:
                di[num] += 1
            else:
                di[num] = 1

        elif a == 'D':
            if num == -1:
                try : 
                    while 1:
                        s = heapq.heappop(heap1)
                        if s in di:
                            di[s] -= 1
                            if di[s] == 0:
                                del di[s]
                            break
                except:
                    continue
                
            else:
                try : 
                    while 1:
                        s = heapq.heappop(heap2)
                        if -s in di:
                            di[-s] -= 1
                            if di[-s] == 0:
                                del di[-s]
                            break
                except:
                    continue

    di_cp = di.copy()
    for i in di_cp:
        if di[i]<0:
            del di[i]

    if di:
        print(max(di), min(di))
    else:
        print('EMPTY')