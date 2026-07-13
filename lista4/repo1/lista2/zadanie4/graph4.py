import numpy as np
import matplotlib.pyplot as plt
from collections import defaultdict


def load_and_group(filename):
    data = np.loadtxt(filename)

    groups = defaultdict(list)

    for m, n, c, result in data:
        size = m * n
        ratio = m / n

        if 0.5 <= ratio <= 2:
            shape = "square"
        elif ratio < 0.5:
            shape = "wide"
        else:
            shape = "tall"

        groups[(shape, size)].append(c)

    result = defaultdict(lambda: ([], []))

    for (shape, size), values in groups.items():
        result[shape][0].append(size)
        result[shape][1].append(np.mean(values))

    for shape in result:
        sizes = np.array(result[shape][0])
        comps = np.array(result[shape][1])

        order = np.argsort(sizes)
        result[shape] = (sizes[order], comps[order])

    return result


def plot_group(data_stair, data_bin, data_hyb, title_suffix):
    for shape in ["square", "wide", "tall"]:
        if shape not in data_stair:
            continue

        # ===== WYKRES 1: comparisons =====
        plt.figure()

        ns, cs = data_stair[shape]
        plt.plot(ns, cs, label="Staircase")

        ns, cs = data_bin[shape]
        plt.plot(ns, cs, label="Binary")

        ns, cs = data_hyb[shape]
        plt.plot(ns, cs, label="Hybrid")

        plt.xlabel("m * n")
        plt.ylabel("comparisons")
        plt.title(f"Comparisons vs size ({shape}, {title_suffix})")
        plt.legend()
        plt.grid()

        filename = f"comparisons_{shape}_{title_suffix}.png"
        plt.savefig(filename)
        plt.close()

        # ===== WYKRES 2: c/(m*n) =====
        plt.figure()

        ns, cs = data_stair[shape]
        plt.plot(ns, cs / ns, label="Staircase")

        ns, cs = data_bin[shape]
        plt.plot(ns, cs / ns, label="Binary")

        ns, cs = data_hyb[shape]
        plt.plot(ns, cs / ns, label="Hybrid")

        plt.xlabel("m * n")
        plt.ylabel("c / (m*n)")
        plt.title(f"c/(m*n) vs size ({shape}, {title_suffix})")
        plt.legend()
        plt.grid()

        filename = f"ratio_{shape}_{title_suffix}.png"
        plt.savefig(filename)
        plt.close()


# ===== MAŁE DANE =====

data_stair = load_and_group("staircase_small.txt")
data_bin = load_and_group("binary_small.txt")
data_hyb = load_and_group("hybrid_small.txt")

plot_group(data_stair, data_bin, data_hyb, "small")


# ===== DUŻE DANE =====

data_stair = load_and_group("staircase_big.txt")
data_bin = load_and_group("binary_big.txt")
data_hyb = load_and_group("hybrid_big.txt")

plot_group(data_stair, data_bin, data_hyb, "large")