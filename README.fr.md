<div align="center">
  <img src="https://raw.githubusercontent.com/ayogun/42-project-badges/main/covers/cover-fract-ol.png" alt="fract'ol" />
</div>

# fract'ol - Explorateur de Fractales

Le projet `fract'ol` est un projet graphique qui consiste a creer un explorateur de fractales en temps reel avec la librairie **MLX42**. Ce projet est une excellente introduction aux **nombres complexes**, au **graphisme informatique** et a la **programmation evenementielle**.

## Statut
<div align="center">

![42 Bangkok](https://img.shields.io/badge/42-Bangkok-000000?style=for-the-badge&logo=42&logoColor=white)
![C](https://img.shields.io/badge/C-00599C?style=for-the-badge&logo=c&logoColor=white)
![Norminette](https://img.shields.io/badge/Norminette-passing-success?style=for-the-badge)

<br>

### Langue / Language

[![English](https://img.shields.io/badge/Read_in_English-red?style=for-the-badge&logoColor=white)](README.md)

</div>

---

## Apercu

L'objectif est de rendre des fractales en temps reel, permettant a l'utilisateur de zoomer, naviguer et changer de palettes de couleurs de maniere interactive. Cet exercice ameliore la comprehension de la visualisation mathematique et du rendu pixel par pixel avec la librairie graphique MLX42.

## Ressources Utiles

- [Notion's Oceano - fract'ol](https://suspectedoceano.notion.site)
- [Documentation MLX42](https://github.com/codam-coding-college/MLX42)

---

## Partie Obligatoire

<table>
  <tr>
    <th>Nom du programme</th>
    <td>fractol</td>
  </tr>
  <tr>
    <th>Fichiers a rendre</th>
    <td>Makefile, *.h, *.c</td>
  </tr>
  <tr>
    <th>Makefile</th>
    <td>Oui</td>
  </tr>
  <tr>
    <th>Fonctions ext.</th>
    <td>open, close, read, write, malloc, free, perror, strerror, exit, librairie math, MLX42</td>
  </tr>
  <tr>
    <th>Libft autorisee</th>
    <td>Oui</td>
  </tr>
  <tr>
    <th>Description</th>
    <td>Creer un explorateur graphique de fractales avec zoom et navigation.</td>
  </tr>
</table>

### Regles Importantes
- Les variables globales sont interdites.
- Les sous-fonctions doivent etre definies en `static`.
- Tous les fichiers .c doivent compiler avec les flags `-Wall -Wextra -Werror`.
- Le programme ne doit pas avoir de fuites memoire.

---

## Structure du Projet

```
fractol/
├── Makefile                  # Compilation -> binaire fractol
├── include/
│   └── fractol.h             # Header (prototypes + includes)
│
├── src/                      # Fichiers sources (9 fichiers)
│   ├── 1_main.c              # Point d'entree + parsing des arguments
│   ├── 2_utils.c             # Fonctions utilitaires (atof, verifications)
│   ├── 3_keys.c              # Gestion des evenements clavier & scroll
│   ├── 4_init.c              # Initialisation des fractales
│   ├── 5_image.c             # Gestion d'image & animation
│   ├── 6_rendering.c         # Boucle de rendu des fractales
│   ├── 7_color.c             # Palettes de couleurs
│   ├── 8_help.c              # Messages d'aide/utilisation
│   └── 9_fractols.c          # Formules des fractales
│
├── my_lib/                   # Libft + ft_printf + GNL
└── MLX42/                    # Librairie graphique MLX42
```

---

## Fractales Implementees

<details open>
<summary><b>Cliquez pour voir les fractales</b></summary>

| Fractale | Formule | Lancement |
|:--------:|:--------|:----------|
| **Mandelbrot** | `z(n+1) = z(n)² + c` ou z₀ = 0 | `./fractol mandelbrot` |
| **Julia** | `z(n+1) = z(n)² + c` ou c = constante | `./fractol julia -0.4 0.6` |
| **Burning Ship** | `z(n+1) = (\|Re(z)\| + i\|Im(z)\|)² + c` | `./fractol burningship` |
| **Tricorn** | `z(n+1) = conj(z(n))² + c` | `./fractol tricorn` |

</details>

---

## Controles

### Clavier

| Touche | Action |
|:------:|:-------|
| **ESC** | Quitter le programme |
| **Fleches directionnelles** | Se deplacer |
| **+** / **-** | Augmenter / Diminuer les iterations |
| **Espace** | Reinitialiser la vue |
| **C** | Changer de palette de couleurs |
| **1 2 3 4** | Changer de fractale |

### Souris

| Action | Effet |
|:------:|:------|
| **Scroll Haut** | Zoomer |
| **Scroll Bas** | Dezoomer |
| **Mouvement souris** (Julia) | Modifier les parametres en temps reel |

---

## Compilation et Utilisation

### Compiler le Programme

```bash
# Compiler (construit MLX42 + libft + fractol)
make

# Nettoyer les fichiers objets
make clean

# Tout nettoyer
make fclean

# Recompiler completement
make re
```

### Exemples de Lancement

```bash
# Mandelbrot
./fractol mandelbrot

# Julia avec parametres
./fractol julia -0.4 0.6
./fractol julia 0.285 0.01

# Burning Ship
./fractol burningship

# Tricorn
./fractol tricorn
```

---

## Points Forts de l'Implementation

<details>
<summary><b>Presets de Parametres Julia</b></summary>

```bash
# Spirale
./fractol julia -0.4 0.6

# Flocon de neige
./fractol julia 0.285 0.01

# Dragon
./fractol julia -0.8 0.156

# Dentelle
./fractol julia -0.7269 0.1889
```

</details>

<details>
<summary><b>Palettes de Couleurs</b></summary>

4 palettes de couleurs differentes sont disponibles, changeables avec la touche `C` :

```c
// Exemples de palettes
color = create_trgb(0, i * 9, i * 15, i * 20);   // Degrade bleu-rouge
hue = (i * 360.0 / max_iter);                      // Arc-en-ciel
color = (i * 255 / max_iter) % 256;                // Psychedelique
```

</details>

<details>
<summary><b>Zoom Fluide</b></summary>

Le zoom suit la position du curseur de la souris, permettant une navigation precise dans les details de la fractale. Le facteur de zoom et le decalage sont recalcules par rapport aux coordonnees du curseur.

</details>

---

## Limitations

Cette implementation **NE supporte PAS** :

- Pas de multi-threading (rendu mono-thread)
- Pas d'acceleration GPU
- Taille de fenetre fixe (800x800)

---

## Statistiques

<div align="center">

| Metrique | Valeur |
|:--------:|:------:|
| **Fichiers sources** | 9 .c |
| **Lignes** | ~790 |
| **Fractales** | 4 |
| **Palettes de couleurs** | 4 |
| **Lib graphique** | MLX42 |

</div>

---

## Avertissement

**Ce projet a un but educatif et vous ne devez en aucun cas faire du copier-coller.**
**Tricher c'est mal. Ne trichez pas.**

**This project has an educational purpose and you should under no circumstances copy and paste.**
**Cheat is bad. Don't cheat.**

---

<div align="center">

**Fait avec amour pour 42 Bangkok**

[![Retour en haut](https://img.shields.io/badge/Retour_en_haut-blue?style=for-the-badge)](#fractol---explorateur-de-fractales)

</div>
