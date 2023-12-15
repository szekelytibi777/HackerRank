def fizzBuzz(n):
    for i in range(1, n+1):
        if i % 3 == 0 and i % 5 != 0:
                print("Fizz")
        elif i % 5 == 0 and i % 3 != 0:
                print("Buzz")
        elif i % 15 == 0:
            print("FizzBuzz")
        else:
            print(i)

        
               



if __name__ == '__main__':
    n = int(input().strip())

    fizzBuzz(n)
