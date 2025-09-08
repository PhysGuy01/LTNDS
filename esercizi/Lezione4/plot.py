import numpy as np
import matplotlib.pyplot as mpl

# Carica i dati delle medie su medie
medie = np.loadtxt("medie.dat")
err = np.loadtxt("errori.dat")

anni = []
for i in range(1941,2024):
    anni.append(i)

# Crea un istogramma dai dati
mpl.errorbar(medie, anni, yerr = err, fmt ='o')

# Cosmetics
mpl.title("Andamento temperatura")
mpl.xlabel("Anni")
mpl.ylabel("Delta")
mpl.legend()

# Salva su una png
mpl.savefig("pyplot.png")

# Disegna
mpl.show()