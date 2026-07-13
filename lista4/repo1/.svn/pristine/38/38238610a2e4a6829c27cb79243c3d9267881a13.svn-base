import numpy as np
import matplotlib.pyplot as plt
from collections import defaultdict

def load_and_average(filename):
    data = np.loadtxt(filename)

    if data.ndim == 1:
        data = np.array([data])

    sums_c = defaultdict(float)
    sums_s = defaultdict(float)
    counts = defaultdict(int)

    for n, c, s in data:
        sums_c[n] += c
        sums_s[n] += s
        counts[n] += 1

    ns = sorted(sums_c.keys())
    avg_c = [sums_c[n]/counts[n] for n in ns]
    avg_s = [sums_s[n]/counts[n] for n in ns]

    return np.array(ns), np.array(avg_c), np.array(avg_s)


# ===== MAŁE DANE =====

nq, cq, sq = load_and_average("merge_small.txt")
nh, ch, sh = load_and_average("mydivide_small.txt")

# comparisons
plt.figure()
plt.plot(nq, cq, label="Merge")
plt.plot(nh, ch, label="MyDivide")
plt.xlabel("n")
plt.ylabel("comparisons")
plt.legend()
plt.title("Comparisons vs n (small)")
plt.grid()
plt.savefig("comparisons_small.png")
plt.close()

# swaps
plt.figure()
plt.plot(nq, sq, label="Merge")
plt.plot(nh, sh, label="MyDivide")
plt.xlabel("n")
plt.ylabel("swaps")
plt.legend()
plt.title("Swaps vs n (small)")
plt.grid()
plt.savefig("swaps_small.png")
plt.close()

# c/n
plt.figure()
plt.plot(nq, cq/nq, label="Merge")
plt.plot(nh, ch/nh, label="MyDivide")
plt.xlabel("n")
plt.ylabel("c/n")
plt.legend()
plt.title("c/n vs n (small)")
plt.grid()
plt.savefig("cn_small.png")
plt.close()

# s/n
plt.figure()
plt.plot(nq, sq/nq, label="Merge")
plt.plot(nh, sh/nh, label="MyDivide")
plt.xlabel("n")
plt.ylabel("s/n")
plt.legend()
plt.title("s/n vs n (small)")
plt.grid()
plt.savefig("sn_small.png")
plt.close()


# ===== DUŻE DANE =====

nq, cq, sq = load_and_average("merge_big.txt")
nh, ch, sh = load_and_average("mydivide_big.txt")

# comparisons
plt.figure()
plt.plot(nq, cq, label="Merge")
plt.plot(nh, ch, label="MyDivide")
plt.xlabel("n")
plt.ylabel("comparisons")
plt.legend()
plt.title("Comparisons vs n (large)")
plt.grid()
plt.savefig("comparisons_big.png")
plt.close()

# swaps
plt.figure()
plt.plot(nq, sq, label="Merge")
plt.plot(nh, sh, label="MyDivide")
plt.xlabel("n")
plt.ylabel("swaps")
plt.legend()
plt.title("Swaps vs n (large)")
plt.grid()
plt.savefig("swaps_big.png")
plt.close()

# c/n
plt.figure()
plt.plot(nq, cq/nq, label="Merge")
plt.plot(nh, ch/nh, label="MyDivide")
plt.xlabel("n")
plt.ylabel("c/n")
plt.legend()
plt.title("c/n vs n (large)")
plt.grid()
plt.savefig("cn_big.png")
plt.close()

# s/n
plt.figure()
plt.plot(nq, sq/nq, label="Merge")
plt.plot(nh, sh/nh, label="MyDivide")
plt.xlabel("n")
plt.ylabel("s/n")
plt.legend()
plt.title("s/n vs n (large)")
plt.grid()
plt.savefig("sn_big.png")
plt.close()

print("Wykresy zapisane do PNG ")