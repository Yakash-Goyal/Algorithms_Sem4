import matplotlib.pyplot as plt
def plot_graph_from_file(filename):
    try:
        with open(filename, 'r') as file:
            lines = file.readlines()
            x_label, y_label = lines[0].strip().split(',')
            x_values = []
            y_values = []
            for line in lines[1:]:
                x, y = line.strip().split(',')
                x_values.append(float(x)) 
                y_values.append(float(y))

            plt.figure(figsize=(8, 5))
            plt.plot(x_values, y_values, marker='o', linestyle='-', color='b', label="Data")
            plt.xlabel(x_label)
            plt.ylabel(y_label)
            plt.title(f"{y_label} vs {x_label}")
            plt.legend()
            plt.grid(True)
            plt.show()

    except Exception as e:
        print("Error:", e)
filename = "F:\coding\DSA\Algorithms_Sem4\Graphs\data.txt"
plot_graph_from_file(filename)
