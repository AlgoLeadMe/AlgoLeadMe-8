s = input()
ex = input()

stack = []

for i in range(len(s)):
  stack.append(s[i])
  if ex == ''.join(stack[-len(ex):]):
    for j in range(len(ex)):
      stack.pop()

if not stack:
  print("FRULA")
else:
  print(''.join(stack))