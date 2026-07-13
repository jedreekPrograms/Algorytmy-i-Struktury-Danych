import pandas as pd
import matplotlib.pyplot as plt

types=["complete","sparse","medium"]

for t in types:

    kr=pd.read_csv(f"../data/{t}_kruskal.csv")
    pr=pd.read_csv(f"../data/{t}_prim.csv")

    plt.figure(figsize=(10,6))

    plt.plot(
        kr["n"],
        kr["time"],
        marker='o',
        markersize=4,
        label="Kruskal"
    )

    plt.plot(
        pr["n"],
        pr["time"],
        marker='o',
        markersize=4,
        label="Prim"
    )

    plt.xlabel("Number of vertices")

    plt.ylabel("Average time [ms]")

    plt.title(f"{t.capitalize()} graph")

    plt.legend()

    plt.grid()

    plt.tight_layout()

    plt.savefig(
        f"../plots/{t}.png",
        dpi=300
    )

    plt.close()