"""
Closest Strings

You are given a array of string followed by two words. You have to find the 
minimum distance between the two words in the given array of string

For example:
(“the”, “quick”, “brown”, “fox”, “quick”)
distance(“fox”,”the”) = 3
distance(“quick”, “fox”) = 1

time complexity : O(n^n) brute force
	 	  O(n) - below used method

"""

#code

def distance(arr,w1,w2):
    if(w1 == w2):
        return 0
        
    n = len(arr)
    min_dist = n+1
    prev = 0
    for i in range(n):
        if(arr[i]==w1 or arr[i]==w2):
            prev = i
            break
        
    while(i<n):
        if(arr[i]==w1 or arr[i]==w2):
            if(arr[prev]!=arr[i] and (i-prev)<min_dist):
                min_dist = i-prev;
                prev = i
            else:
                prev = i
        i = i+1
    return min_dist

t = int(input())
while(t):
    t = t-1
    n = int(input())
    arr = [x for x in input().split()]
    w1,w2 = [x for x in input().split()]
    res = distance(arr,w1,w2)
    print(res,end="\n")
