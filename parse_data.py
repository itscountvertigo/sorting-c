import matplotlib.pyplot as plt
import numpy as np

def read_file(file_path):
    with open(file_path) as f:
        lines = f.readlines()

    parsed_lines = []

    for i in lines:
        parsed_lines.append(i.rstrip().split())

    return parsed_lines

def remove_outliers(data, threshold=3):
    data = np.array(data).astype(int)

    filtered_data = []

    for i in data:
        z_score = abs((i[1] - np.mean(data)) / np.std(data))

        if z_score < threshold:
            filtered_data.append(i)

    return filtered_data

def best_fit_line(x_data, y_data):
    a, b, c = np.polyfit(x_data, y_data, 2)

    print(f"Best fit line: ({a})x^2 + ({b})x + {c}")

    return a, b, c

def plot(x_data, y_data):
    plt.title("Best-fit lines of C and C# Quicksort times")
    plt.xlabel("Number of integers")
    plt.ylabel("Sorting time (ms)")

    plt.ticklabel_format(useOffset=True)

    plt.xticks(range(0, int(max(x_data)), 500000))
    plt.yticks(range(0, int(max(y_data)), 100))

    plt.plot(x_data, y_data)

    x = range(max(x_data))
    best_fit = best_fit_line(x_data, y_data)
    plt.plot(x, best_fit[0] * x * x + best_fit[1] * x + best_fit[2], linestyle="--", linewidth=1)

if __name__ == "__main__":
    data_cs = read_file("data/csharp_data.txt")
    data_cs = remove_outliers(data_cs, threshold=2)

    x_data_cs = []
    y_data_cs = []

    for i in data_cs:
        x_data_cs.append(i[0])
        y_data_cs.append(i[1])

    data_c = read_file("data/c_data.txt")
    data_c = remove_outliers(data_c, threshold=2)

    x_data_c = []
    y_data_c = []

    for i in data_c:
        x_data_c.append(i[0])
        y_data_c.append(i[1])

    plot(x_data_cs, y_data_cs)
    plot(x_data_c, y_data_c)
    plt.show()