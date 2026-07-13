# graph_select_groups.py

import matplotlib.pyplot as plt
from collections import defaultdict


# =========================================================
# WCZYTYWANIE + ŚREDNIE
# =========================================================

def read_and_average(filename):

    data = defaultdict(lambda: {
        "comparisons": [],
        "swaps": [],
        "time": []
    })

    with open(filename, "r") as f:

        for line in f:

            parts = line.strip().split()

            # oczekujemy:
            # n k swaps comparisons time

            if len(parts) != 5:
                continue

            try:
                n, k, swaps, comparisons, time = map(int, parts)

            except ValueError:
                continue

            data[n]["comparisons"].append(comparisons)
            data[n]["swaps"].append(swaps)
            data[n]["time"].append(time)

    n_values = sorted(data.keys())

    avg_comparisons = []
    avg_swaps = []
    avg_time = []

    for n in n_values:

        avg_comparisons.append(
            sum(data[n]["comparisons"]) /
            len(data[n]["comparisons"])
        )

        avg_swaps.append(
            sum(data[n]["swaps"]) /
            len(data[n]["swaps"])
        )

        avg_time.append(
            sum(data[n]["time"]) /
            len(data[n]["time"])
        )

    return (
        n_values,
        avg_comparisons,
        avg_swaps,
        avg_time
    )


# =========================================================
# RYSOWANIE
# =========================================================

def make_plot(
        files,
        metric_index,
        title,
        ylabel,
        output_name
):

    plt.figure(figsize=(10, 6))

    for filename, label in files:

        n, comparisons, swaps, time = read_and_average(filename)

        metrics = [
            comparisons,
            swaps,
            time
        ]

        y = metrics[metric_index]

        plt.plot(
            n,
            y,
            linewidth=2,
            label=label
        )

    plt.xlabel("n", fontsize=12)

    plt.ylabel(ylabel, fontsize=12)

    plt.title(title, fontsize=14)

    plt.legend()

    plt.grid(True)

    plt.tight_layout()

    plt.savefig(output_name)

    plt.close()


# =========================================================
# PLIKI
# =========================================================

files = [
    ("select_3.txt", "k = 3"),
    ("select_5.txt", "k = 5"),
    ("select_7.txt", "k = 7"),
    ("select_9.txt", "k = 9"),
    ("select_19.txt", "k = 19"),
    ("select_21.txt", "k = 21")
]


# =========================================================
# COMPARISONS
# =========================================================

make_plot(
    files=files,

    metric_index=0,

    title="SELECT - Comparisons",

    ylabel="Średnia liczba porównań",

    output_name="select_comparisons.png"
)


# =========================================================
# SWAPS
# =========================================================

make_plot(
    files=files,

    metric_index=1,

    title="SELECT - Swaps",

    ylabel="Średnia liczba przestawień",

    output_name="select_swaps.png"
)


# =========================================================
# TIME
# =========================================================

make_plot(
    files=files,

    metric_index=2,

    title="SELECT - Time",

    ylabel="Średni czas [μs]",

    output_name="select_time.png"
)


print("Wykresy zapisane ✅")
print(" - select_comparisons.png")
print(" - select_swaps.png")
print(" - select_time.png")
