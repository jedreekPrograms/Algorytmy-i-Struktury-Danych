import matplotlib.pyplot as plt
import numpy as np
from collections import defaultdict


# =========================
# Wczytywanie + grupowanie
# =========================
def load_data(filename, only_found=None):
    grouped = defaultdict(list)

    with open(filename, 'r') as f:
        for line in f:
            parts = line.strip().split()
            if len(parts) != 4:
                continue

            n = int(parts[0])
            comparisons = int(parts[2])
            found = int(parts[3])

            if only_found is not None and found != only_found:
                continue

            grouped[n].append(comparisons)

    if not grouped:
        return np.array([]), np.array([])

    # 🔥 MEDIANA zamiast średniej (stabilniejsze!)
    n_vals = sorted(grouped.keys())
    comp_vals = [np.median(grouped[n]) for n in n_vals]

    return np.array(n_vals), np.array(comp_vals)


# =========================
# Wygładzanie (FIX EDGE BUG)
# =========================
def smooth(y, window=15):
    if len(y) < window:
        return y

    kernel = np.ones(window) / window

    # 🔥 padding usuwa spadki na końcach
    y_pad = np.pad(y, (window // 2, window // 2), mode='edge')

    return np.convolve(y_pad, kernel, mode='valid')


# =========================
# Wykres podstawowy
# =========================
def plot_pair(binary_file, myfind_file, title,
              only_found=None, smooth_data=False, save=False):

    n_b, c_b = load_data(binary_file, only_found)
    n_m, c_m = load_data(myfind_file, only_found)

    if len(n_b) == 0 or len(n_m) == 0:
        print(f"Brak danych: {title}")
        return

    if smooth_data:
        c_b = smooth(c_b)
        c_m = smooth(c_m)

    plt.figure(figsize=(8, 5))

    plt.plot(n_b, c_b, label="BinarySearch", linewidth=2)
    plt.plot(n_m, c_m, label="MyFind", linewidth=2)

    plt.xlabel("n")
    plt.ylabel("Liczba porównań")
    plt.title(title)
    plt.legend()
    plt.grid(alpha=0.3)

    if save:
        filename = title.replace(" ", "_") + ".png"
        plt.savefig(filename, dpi=150, bbox_inches='tight')
        print(f"Zapisano: {filename}")
        plt.close()
    else:
        plt.show()


# =========================
# BONUS: wykres różnicy
# =========================
def plot_diff(binary_file, myfind_file, title):
    n_b, c_b = load_data(binary_file)
    n_m, c_m = load_data(myfind_file)

    if len(n_b) == 0 or len(n_m) == 0:
        return

    plt.figure(figsize=(8, 5))
    plt.plot(n_b, c_b - c_m, linewidth=2)

    plt.xlabel("n")
    plt.ylabel("Binary - MyFind")
    plt.title(title)
    plt.grid(alpha=0.3)

    filename = title.replace(" ", "_") + ".png"
    plt.savefig(filename, dpi=150, bbox_inches='tight')
    plt.close()


# =========================
# MAIN
# =========================
if __name__ == "__main__":

    # ALL
    plot_pair("binary_1.txt", "myfind_1.txt",
              "f1 (delta=10) - ALL", save=True)

    plot_pair("binary_2.txt", "myfind_2.txt",
              "f2 (delta=50) - ALL", save=True)

    # FOUND
    plot_pair("binary_1.txt", "myfind_1.txt",
              "f1 (delta=10) - FOUND", only_found=1, save=True)

    plot_pair("binary_2.txt", "myfind_2.txt",
              "f2 (delta=50) - FOUND", only_found=1, save=True)

    # NOT FOUND
    plot_pair("binary_1.txt", "myfind_1.txt",
              "f1 (delta=10) - NOT FOUND", only_found=0, save=True)

    plot_pair("binary_2.txt", "myfind_2.txt",
              "f2 (delta=50) - NOT FOUND", only_found=0, save=True)

    # SMOOTH
    plot_pair("binary_1.txt", "myfind_1.txt",
              "f1 (delta=10) - SMOOTH", smooth_data=True, save=True)

    plot_pair("binary_2.txt", "myfind_2.txt",
              "f2 (delta=50) - SMOOTH", smooth_data=True, save=True)
