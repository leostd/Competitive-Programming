def f(x):
    ans = 1
    while(x >= 1):
        ans = ans * x
        x = x - 1
    
    return ans

if __name__ == "__main__":
    print(f(16) / f(11) / f(5))