from  matplotlib import pyplot as plt
import numpy as np

f = open('C:/Users/Jiaho/OneDrive/Documents/C++/Proj1/build-Proj1-Desktop_Qt_5_5_1_MinGW_32bit-Debug/5000 integration point.txt', 'r')
r=[]
actu=[]
Gau=[]
LU=[]
lg=[]
for line in f:
    for ch in line:
        if ch=='x':
            index=line.index(ch)
            r.append(line[index+3:index+9])
        elif ch=='A':
            index=line.index(ch)
            actu.append(line[index+8:index+15])
        elif ch=='U':
            index=line.index(ch)
            LU.append(line[index+4:index+12])
        elif ch=='n': 
            index=line.index(ch)
            Gau.append(line[index+4:index+12])
        elif ch=='g':
            index=line.index(ch)
            lg.append(line[index+2:index+9])        
f.close()
print r
print actu


#print actu
plt.plot(r, LU ,'b',r, Gau ,'g',r, actu,'y-')
plt.axis([0,1,0.0, 0.8])
plt.xlabel(r'$x$')
plt.ylabel(r'$y$')
plt.title(r'derivative')
plt.savefig('second-order differential.pdf')
plt.show()

#
#plt.plot(r, lg ,'r-')
#plt.axis([0,1,-2,2.0])
#plt.xlabel(r'$r$')
#plt.ylabel(r'$y$')
#plt.title(r'log')
#plt.savefig('Error approxmation.pdf')
#plt.show()
#plt.close()