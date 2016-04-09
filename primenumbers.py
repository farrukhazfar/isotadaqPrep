# File: python primenumbers.py

#Function definition and implementation..note it comes before the line of code
#that calls it

def primes(n):
     for m in range(2, n):
       for x in range(2,m):
         if m % x == 0:
           print m, 'equals', x, '*', m/x
           break
       else:
          print m, 'is a prime number'



#screen io, asks the user for screen input...

n = int(raw_input("Please enter an integer upto which you want all the prime numbers: "))

primes(n)

          

