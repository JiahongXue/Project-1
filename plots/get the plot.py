from  matplotlib import pyplot as plt
import numpy as np

#######################################################################################
##    These 2 parts of code gives the plots of the actual values Vs. Calc. values    ##
## For the first part, change the path of the txt file to find the coresponded data  ##
##   Second part gives a semi log error plot vs the log of steplength was taken      ##
##  Run the 2 parts of the codes seperately, or they will appear on the same plot    ##
#######################################################################################

f = open('C:/Users/Jiaho/OneDrive/Documents/GitHub/project1/datas/10 integration point.txt', 'r')
r=[]
actu=[]
Gau=[]
LU=[]
er=[]
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
            er.append(line[index+2:index+9])        
f.close()
#print actu
plt.plot(r, LU ,'b',r, Gau ,'g',r, actu,'y-')
plt.axis([0,1,0.0, 0.8])
plt.xlabel(r'$x$')
plt.ylabel(r'$y$')
plt.title(r'derivative')
plt.savefig('second-order differential.pdf')
plt.show()



##get the error plot code
#ff = open('C:/Users/Jiaho/OneDrive/Documents/GitHub/project1/datas/run time analyse.txt', 'r')
#points=[]
#size=[]
#error=[]
#TGau=[]
#TLU=[]
#
#for line in ff:
#    for ch in line:
#        if ch=='n':
#            index=line.index(ch)
#            points.append(line[index+4:index+9])
#        elif ch=='z':
#            index=line.index(ch)
#            size.append(line[index+3:index+7])
#        elif ch=='g':
#            index=line.index(ch)
#            error.append(line[index+1:index+9])
#        elif ch=='u':
#            index=line.index(ch)
#            TGau.append(line[index+3:index+11])
#        elif ch=='U': 
#            index=line.index(ch)
#            TLU.append(line[index+3:index+7])
#             
#ff.close()
#
#plt.plot(size, error ,'r-')
#plt.axis([-4,-3,-3.1,-2.0])
#plt.xlabel(r'$log of stepsize$')
#plt.ylabel(r'$error$')
#plt.title(r'Uncertainty as a function of log of stepsize')
#plt.savefig('Error approxmation.pdf')
#plt.show()