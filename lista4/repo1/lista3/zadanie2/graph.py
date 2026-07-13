import matplotlib.pyplot as plt
from collections import defaultdict


def read_and_average(filename):
    data = defaultdict(lambda: {"comp": [], "swap": []})

    with open(filename) as f:
        for line in f:
            n, k, comp, swap = map(int, line.split())
            data[n]["comp"].append(comp)
            data[n]["swap"].append(swap)

    n_values = sorted(data.keys())
    avg_comp = []
    avg_swap = []

    for n in n_values:
        avg_c = sum(data[n]["comp"]) / len(data[n]["comp"])
        avg_s = sum(data[n]["swap"]) / len(data[n]["swap"])
        avg_comp.append(avg_c)
        avg_swap.append(avg_s)

    return n_values, avg_comp, avg_swap


# 🔹 rysowanie jednego typu (comparisons albo swaps)
def plot_group(files, title, ylabel, index):
    plt.figure()

    for filename, label in files:
        n, comp, swap = read_and_average(filename)
        y = comp if index == 0 else swap
        plt.plot(n, y, label=label)

    plt.xlabel("n")
    plt.ylabel(ylabel)
    plt.title(title)
    plt.legend()
    plt.grid()

    # zapis do pliku
    plt.savefig(title.replace(" ", "_") + ".png")
    plt.close()


# =========================
# 🔹 RANDOM
# =========================
random_files = [
    ("random_k1.txt", "k = 1"),
    ("random_kmid.txt", "k = mid"),
    ("random_kn.txt", "k = n"),
]

plot_group(random_files,
           "Random - Comparisons",
           "Średnia liczba porównań",
           0)

plot_group(random_files,
           "Random - Swaps",
           "Średnia liczba przestawień",
           1)


# =========================
# 🔹 SELECT
# =========================
select_files = [
    ("select_k1.txt", "k = 1"),
    ("select_kmid.txt", "k = mid"),
    ("select_kn.txt", "k = n"),
]

plot_group(select_files,
           "Select - Comparisons",
           "Średnia liczba porównań",
           0)

plot_group(select_files,
           "Select - Swaps",
           "Średnia liczba przestawień",
           1)


print("Wykresy zapisane jako PNG ✅")