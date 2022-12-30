import sys
import math
A,B = map(float, input().split())
deb = math.pow(float(A)/(2.0*float(B)), 1/3)
min_x = deb*deb - 1.0
ans = A 


if((1+math.ceil(min_x))>0):
    if(ans > (float(A)/math.sqrt((1+math.ceil(min_x))) + B*math.ceil(min_x))):
        ans = (float(A)/math.sqrt((1+math.ceil(min_x))) + B*math.ceil(min_x))
if((1+math.floor(min_x))>0):
    if(ans > (float(A)/math.sqrt((1+math.floor(min_x))) + B*math.floor(min_x))):
        ans = (float(A)/math.sqrt((1+math.floor(min_x))) + B*math.floor(min_x))
print('{:.10f}'.format(ans))