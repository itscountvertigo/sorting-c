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

    return a, b, c

def plot(x_data, y_data):
    plt.title("Quicksort times using C")
    plt.xlabel("Number of integers")
    plt.ylabel("Sorting time (ms)")

    plt.ticklabel_format(useOffset=True)

    plt.xticks(range(0, int(max(x_data)), 500000))
    plt.yticks(range(0, int(max(y_data)), 500))

    plt.plot(x_data, y_data)

    x = range(max(x_data))
    best_fit = best_fit_line(x_data, y_data)
    plt.plot(x, best_fit[0] * x * x + best_fit[1] * x + best_fit[2], color="red", linestyle="--", linewidth=1)
    
    plt.show()

if __name__ == "__main__":
    data = read_file("data/run_1.txt")

    data = remove_outliers(data, threshold=2)

    x_data = []
    y_data = []

    for i in data:
        x_data.append(i[0])
        y_data.append(i[1])

    plot(x_data, y_data)