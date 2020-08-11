from sys import stdin,stdout
import bisect
import math
import itertools


_INPUT=-1
input=[]
def I():
    global _INPUT
    _INPUT += 1
    INPUT = list(map(int,input[_INPUT].split()))
    if len(INPUT) == 1:
        return INPUT[0]
    else:
        return INPUT   

def IS():
    global _INPUT
    _INPUT += 1
    INPUT = list(map(str,input[_INPUT].split()))
    if len(INPUT) == 1:
        return INPUT[0]
    else:
        return INPUT 
       
def IA():
    global _INPUT
    _INPUT += 1
    INPUT = list(map(int,input[_INPUT].split()))
    return INPUT    

def IAS():
    global _INPUT
    _INPUT += 1
    INPUT = list(map(str,input[_INPUT].split()))
    return INPUT

stdin = open("input.txt","r")
ONLINE_JUDGE = not __debug__
if ONLINE_JUDGE:
    stdin = open("input.txt", "r")

input = stdin.readlines()
if __name__=="__main__":

    arr = IAS()
    print(arr)

