# plot.sage - Génération des graphiques

def readFile(filename):
    """Lit un fichier .data et retourne une liste de points [n, temps]"""
    v = []
    try:
        with open(filename) as f:
            for line in f:
                parts = line.split()
                if len(parts) == 2:
                    v.append([float(parts[0]), float(parts[1])])
    except:
        pass
    return v

# Couleurs pour chaque algorithme
colors = {
    'selection': 'red',
    'bubble': 'blue',
    'insertion': 'green',
    'stable': 'purple',
    'quickdet': 'orange',
    'quickrand': 'brown'
}

# Styles de ligne : solide (type 1), tirets (type 2), pointillés (type 3)
linestyles = {
    1: '-',      # solide
    2: '--',     # tirets
    3: ':'       # pointillés
}

print("=== Création du graphique 1 : Algorithmes O(n²) ===")

# Graphique 1 : Algorithmes lents (O(n²))
p1 = Graphics()
for alg in ['selection', 'bubble', 'insertion']:
    for t in [1, 2, 3]:
        filename = f'{alg}_type{t}.data'
        data = readFile(filename)
        if data:
            label = f'{alg} type{t}'
            p1 += line(data, color=colors[alg], linestyle=linestyles[t], 
                      legend_label=label, thickness=2)
            print(f"  Ajouté: {filename} ({len(data)} points)")

p1.axes_labels(['n (taille)', 'Temps (μs)'])
p1.save('graph_slow.pdf', title='Algorithmes de tri O(n²)', 
        legend_loc='upper left', figsize=10)
print("✓ Graphique sauvegardé : graph_slow.pdf")

print("\n=== Création du graphique 2 : Algorithmes O(n log n) ===")

# Graphique 2 : Algorithmes rapides (O(n log n))
p2 = Graphics()
for alg in ['stable', 'quickdet', 'quickrand']:
    for t in [1, 2, 3]:
        filename = f'{alg}_type{t}.data'
        data = readFile(filename)
        if data:
            label = f'{alg} type{t}'
            p2 += line(data, color=colors[alg], linestyle=linestyles[t], 
                      legend_label=label, thickness=2)
            print(f"  Ajouté: {filename} ({len(data)} points)")

p2.axes_labels(['n (taille)', 'Temps (μs)'])
p2.save('graph_fast.pdf', title='Algorithmes de tri O(n log n)', 
        legend_loc='upper left', figsize=10)
print("✓ Graphique sauvegardé : graph_fast.pdf")

print("\n=== Terminé ! ===")
print("Fichiers créés : graph_slow.pdf et graph_fast.pdf")