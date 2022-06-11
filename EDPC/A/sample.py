from math import gcd


def main():
    # N = int(input())
    # h = list(map(int, input().split()))
    N = 4
    h = [10,30,40,20,0,0,0]

    dp = [9999999999]*(N+3)
    dp[0] = 0

    for i in range(0, N):
        dp[i+1] = min(dp[i+1], dp[i]+abs(h[i+1]-h[i]))
        # input(dp)
        dp[i+2] = min(dp[i+2], dp[i]+abs(h[i+2]-h[i]))
        # input(dp)
    print(dp[N-1])


if __name__ == '__main__':
    main()
