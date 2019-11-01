#naive implementation of edit diatnace

def editDisatance(x,y,m,n):
    #insert all chars of second into first if first is empty
    if m == 0: return n

    #remove all chars of first if second is empty
    if n == 0: return m

    #if last chars are same, call function for remaining chars
    if(x[m-1] == y[n-1]):
        return editDisatance(x,y,m-1,n-1)
    
    return 1 + min (editDisatance(x,y,m,n-1), #insert 
                    editDisatance(x,y,m-1,n), #remove
                    editDisatance(x,y,m-1,n-1) #replace
    )

#Driver program for the func
x = "sunday"
y = "saturday"
print("Distance : {}".format(editDisatance(x,y,len(x),len(y))))