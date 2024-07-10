import math

n = int(input())
for i in range(n):
    cnt = 0
    k = int(input())
    j = 2 # 적어도 2개 이상의 연속된 자연수의 합
    while True:
        center_first = math.floor(k / j)  # center 값을 초기화
        div = j // 2
        if center_first < div:
          break
        if j % 2 == 0:
            if ((center_first + center_first + 1) * div == k):
                cnt += 1
        elif j % 2 == 1:
            if ((center_first * 2 * div + center_first) == k):
                cnt += 1
        j += 1
    print(cnt)
