import pandas as pd
import matplotlib.pyplot as plt

df = pd.read_csv(
    "../data/results.csv"
)

plt.figure(figsize=(10,6))

plt.plot(
    df["n"],
    df["min"],
    marker='o',
    markersize=4,
    label="Min"
)

plt.plot(
    df["n"],
    df["avg"],
    marker='o',
    markersize=4,
    label="Average"
)

plt.plot(
    df["n"],
    df["max"],
    marker='o',
    markersize=4,
    label="Max"
)

plt.xlabel(
    "Number of vertices"
)

plt.ylabel(
    "Rounds"
)

plt.title(
    "Broadcast time in MST"
)

plt.legend()

plt.grid()

plt.tight_layout()

plt.savefig(
    "../plots/broadcast.png",
    dpi=300
)



plt.close()