numPaycodes = [1, 2, 3, 4, 5]
numDivisions = [6, 7, 8, 9, 10]
sum = 0
for i in numPaycodes:
    sum = sum + i
for j in numDivisions:
    sum = sum + j
    for i in numDivisions:
        sum = sum + i   
print(sum) 