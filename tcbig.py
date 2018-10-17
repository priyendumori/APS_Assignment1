import random
import string

t=random.randint(1, 10)
print t

for i in range(t):
    if i%5==0:
        x = ''.join(random.choice(string.digits) for _ in range(random.randint(5, 10)))
        x = '-'+x
    else:
        x = ''.join(random.choice(string.digits) for _ in range(random.randint(5,10)))

    if i%3==0:
        y = ''.join(random.choice(string.digits) for _ in range(random.randint(5,10)))    
        y = '-'+y
    else: 
        y = ''.join(random.choice(string.digits) for _ in range(random.randint(5,10)))

    print x
    print y
    print(random.randint(1,5))