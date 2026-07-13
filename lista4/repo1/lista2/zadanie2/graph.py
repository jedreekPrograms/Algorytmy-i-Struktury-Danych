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
    avg_c = np.array([sums_c[n]/counts[n] for n in ns])
    avg_s = np.array([sums_s[n]/counts[n] for n in ns])

    return np.array(ns), avg_c, avg_s


# ===== SMALL =====
nq, cq, sq = load_and_average("quick_small.txt")
nh, ch, sh = load_and_average("hybrid_small.txt")
ni, ci, si = load_and_average("insertion_small.txt")

plt.figure()
plt.plot(nq, cq, label="Quick")
plt.plot(nh, ch, label="Hybrid")
plt.plot(ni, ci, label="Insertion")
plt.xlabel("n")
plt.ylabel("comparisons")
plt.title("Comparisons vs n (small)")
plt.legend()
plt.grid()
plt.savefig("comparisons_small.png")
plt.close()

plt.figure()
plt.plot(nq, sq, label="Quick")
plt.plot(nh, sh, label="Hybrid")
plt.plot(ni, si, label="Insertion")
plt.xlabel("n")
plt.ylabel("swaps")
plt.title("Swaps vs n (small)")
plt.legend()
plt.grid()
plt.savefig("swaps_small.png")
plt.close()

plt.figure()
plt.plot(nq, cq / nq, label="Quick")
plt.plot(nh, ch / nh, label="Hybrid")
plt.plot(ni, ci / ni, label="Insertion")
plt.xlabel("n")
plt.ylabel("c/n")
plt.title("c/n vs n (small)")
plt.legend()
plt.grid()
plt.savefig("cn_small.png")
plt.close()

plt.figure()
plt.plot(nq, sq / nq, label="Quick")
plt.plot(nh, sh / nh, label="Hybrid")
plt.plot(ni, si / ni, label="Insertion")
plt.xlabel("n")
plt.ylabel("s/n")
plt.title("s/n vs n (small)")
plt.legend()
plt.grid()
plt.savefig("sn_small.png")
plt.close()


# ===== BIG =====
nq, cq, sq = load_and_average("quick_big.txt")
nh, ch, sh = load_and_average("hybrid_big.txt")

plt.figure()
plt.plot(nq, cq, label="Quick")
plt.plot(nh, ch, label="Hybrid")
plt.xlabel("n")
plt.ylabel("comparisons")
plt.title("Comparisons vs n (large)")
plt.legend()
plt.grid()
plt.savefig("comparisons_big.png")
plt.close()

plt.figure()
plt.plot(nq, sq, label="Quick")
plt.plot(nh, sh, label="Hybrid")
plt.xlabel("n")
plt.ylabel("swaps")
plt.title("Swaps vs n (large)")
plt.legend()
plt.grid()
plt.savefig("swaps_big.png")
plt.close()

plt.figure()
plt.plot(nq, cq / nq, label="Quick")
plt.plot(nh, ch / nh, label="Hybrid")
plt.xlabel("n")
plt.ylabel("c/n")
plt.title("c/n vs n (large)")
plt.legend()
plt.grid()
plt.savefig("cn_big.png")
plt.close()

plt.figure()
plt.plot(nq, sq / nq, label="Quick")
plt.plot(nh, sh / nh, label="Hybrid")
plt.xlabel("n")
plt.ylabel("s/n")
plt.title("s/n vs n (large)")
plt.legend()
plt.grid()
plt.savefig("sn_big.png")
plt.close()

print("Wykresy zapisane do plików PNG ✅")