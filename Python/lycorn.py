#works fine for age >= 3 ... less good for < 3
age = int(input('Age:'))
l=[" _oO^____","(._,     \\","   \\  _\\ /\\","    || ||","~~~~~~~~~~~~~"]
s=" "*(age-5)
for i in range(age):
    print((" "*i if age>2 else "   ")+"\\")
for i in l:print(s,i)
