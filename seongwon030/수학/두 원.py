import math

x1, y1, r1, x2, y2, r2 = map(float, input().split())

# 중심 간 거리
d = math.sqrt((x1 - x2)**2 + (y1 - y2)**2)


if r1+r2 <= d:
  print(format(0,".3f")) 
elif abs(r1-r2) >= d :
  result = math.pi*min(r1,r2)**2
  print( format(result,".3f"))
else:
  t1 = math.acos((d**2+r1**2-r2**2) / (d*r1*2.0)) * 2.0
  t2 = math.acos((d**2+r2**2-r1**2) / (d*r2*2.0)) * 2.0

  result = (t1 * r1 * r1 + t2 * r2 * r2 - r1 * r1 * math.sin(t1) - r2 * r2 * math.sin(t2)) * 0.5
  print(format(result,".3f"))

