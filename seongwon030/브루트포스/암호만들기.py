from itertools import combinations

L,C = map(int,input().split())

k = list(map(str,input().split()))
vowels = 'aeiou'

vowel_cnt = 0
consonant_cnt = 0

result = []
for c in combinations(k,L):
  vowel_str = ''.join(sorted(c))
  vowel_cnt = sum(1 for char in vowel_str if char in vowels)
  consonant_cnt = L - vowel_cnt
  if vowel_cnt >=1 and consonant_cnt >=2:
    result.append(vowel_str)

result.sort()
for word in result:
    print(word)