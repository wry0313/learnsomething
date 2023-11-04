import timeit

def disasterCode():
    primes = []
    for i in range (2,2500):
        if len(primes) == 0:
            primes.append(i)
            continue
        isPrime = True
        for prime in primes:
            if i % prime == 0: # number is not prime
                isPrime = False
                break
        if isPrime:
            primes.append(i)
            # print(i)
    factorizations = [[], []]
    for i in range (2,2500):
        factorizations.append([])
        for j in range (0, len(primes)):
            if i % primes[j] == 0:
                tmp = i / primes[j]
                factorizations[i] = [primes[j]] + factorizations[int(tmp)]
                print(i, factorizations[i])
                break
    return factorizations

# Benchmark the code
if __name__ == "__main__":
    benchmark_code = "disasterCode()"
    setup_code = "from __main__ import disasterCode"

    # Measure the execution time of disasterCode function
    times = []
    for i in range(0,5):
        times.append(timeit.timeit(benchmark_code, setup=setup_code, number=1))

    res = sum(times)/5

    print(f"Average execution time after 5 runs: {res:.6f} seconds")
