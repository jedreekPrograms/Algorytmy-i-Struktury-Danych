import pandas as pd
import matplotlib.pyplot as plt

df = pd.read_csv("results.csv")

metrics = [
    ("avg_cmp", "Average comparisons"),
    ("max_cmp", "Maximum comparisons"),

    ("avg_read", "Average pointer reads"),
    ("max_read", "Maximum pointer reads"),

    ("avg_assign", "Average pointer assignments"),
    ("max_assign", "Maximum pointer assignments"),

    ("avg_rot", "Average rotations"),
    ("max_rot", "Maximum rotations"),

    ("avg_height", "Average tree height"),
    ("max_height", "Maximum tree height"),
]

for metric, title in metrics:

    # ==========================================
    # SORTED
    # ==========================================

    plt.figure(figsize=(10, 6))

    for operation in ["insert", "delete"]:

        subset = df[
            (df["scenario"] == "sorted")
            &
            (df["operation"] == operation)
            ]

        plt.plot(
            subset["n"],
            subset[metric],
            marker='o',
            linewidth=2,
            markersize=6,
            label=f"sorted-{operation}"
        )

    plt.xlabel("n")
    plt.ylabel(title)

    plt.title(f"{title} (sorted BST)")

    plt.grid(True)

    plt.legend()

    plt.tight_layout()

    plt.savefig(f"sorted_{metric}.png")

    plt.close()

    # ==========================================
    # RANDOM
    # ==========================================

    plt.figure(figsize=(10, 6))

    for operation in ["insert", "delete"]:

        subset = df[
            (df["scenario"] == "random")
            &
            (df["operation"] == operation)
            ]

        plt.plot(
            subset["n"],
            subset[metric],
            marker='o',
            linewidth=2,
            markersize=6,
            label=f"random-{operation}"
        )

    plt.xlabel("n")
    plt.ylabel(title)

    plt.title(f"{title} (random BST)")

    plt.grid(True)

    plt.legend()

    plt.tight_layout()

    plt.savefig(f"random_{metric}.png")

    plt.close()

print("DONE")