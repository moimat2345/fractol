<div align="center">
  <img src="https://raw.githubusercontent.com/ayogun/42-project-badges/main/covers/cover-fract-ol.png" alt="fract'ol" />
</div>

# fract'ol - Fractal Explorer

The `fract'ol` project is a graphical project that consists of creating a real-time fractal explorer using the **MLX42** library. This project is an excellent introduction to **complex numbers**, **computer graphics**, and **event-driven programming**.

## Status
<div align="center">

![42 Bangkok](https://img.shields.io/badge/42-Bangkok-000000?style=for-the-badge&logo=42&logoColor=white)
![C](https://img.shields.io/badge/C-00599C?style=for-the-badge&logo=c&logoColor=white)
![Norminette](https://img.shields.io/badge/Norminette-passing-success?style=for-the-badge)

<br>

### Language / Langue

[![Francais](https://img.shields.io/badge/Lire_en_Francais-blue?style=for-the-badge&logoColor=white)](README.fr.md)

</div>

---

## Overview

The goal is to render fractals in real-time, allowing the user to zoom, navigate, and change color palettes interactively. This exercise improves understanding of mathematical visualization and pixel-level rendering with the MLX42 graphics library.

## Useful Resources

- [Notion's Oceano - fract'ol](https://suspectedoceano.notion.site)
- [MLX42 Documentation](https://github.com/codam-coding-college/MLX42)

---

## Mandatory Part

<table>
  <tr>
    <th>Program name</th>
    <td>fractol</td>
  </tr>
  <tr>
    <th>Turn in files</th>
    <td>Makefile, *.h, *.c</td>
  </tr>
  <tr>
    <th>Makefile</th>
    <td>Yes</td>
  </tr>
  <tr>
    <th>External functs.</th>
    <td>open, close, read, write, malloc, free, perror, strerror, exit, math library, MLX42</td>
  </tr>
  <tr>
    <th>Libft authorized</th>
    <td>Yes</td>
  </tr>
  <tr>
    <th>Description</th>
    <td>Create a graphical fractal explorer with zoom and navigation.</td>
  </tr>
</table>

### Important Rules
- Global variables are forbidden.
- Subfunctions should be defined as `static`.
- All .c files must compile with the flags `-Wall -Wextra -Werror`.
- The program must not leak memory.

---

## Project Structure

```
fractol/
├── Makefile                  # Compilation -> fractol binary
├── include/
│   └── fractol.h             # Header (prototypes + includes)
│
├── src/                      # Source files (9 files)
│   ├── 1_main.c              # Entry point + argument parsing
│   ├── 2_utils.c             # Utility functions (atof, checks)
│   ├── 3_keys.c              # Keyboard & scroll event handling
│   ├── 4_init.c              # Fractal initialization
│   ├── 5_image.c             # Image management & animation
│   ├── 6_rendering.c         # Fractal rendering loop
│   ├── 7_color.c             # Color palettes
│   ├── 8_help.c              # Help/usage messages
│   └── 9_fractols.c          # Fractal formulas
│
├── my_lib/                   # Libft + ft_printf + GNL
└── MLX42/                    # MLX42 graphics library
```

---

## Implemented Fractals

<details open>
<summary><b>Click to see fractals</b></summary>

| Fractal | Formula | Launch |
|:-------:|:--------|:-------|
| **Mandelbrot** | `z(n+1) = z(n)² + c` where z₀ = 0 | `./fractol mandelbrot` |
| **Julia** | `z(n+1) = z(n)² + c` where c = constant | `./fractol julia -0.4 0.6` |
| **Burning Ship** | `z(n+1) = (\|Re(z)\| + i\|Im(z)\|)² + c` | `./fractol burningship` |
| **Tricorn** | `z(n+1) = conj(z(n))² + c` | `./fractol tricorn` |

</details>

---

## Controls

### Keyboard

| Key | Action |
|:---:|:-------|
| **ESC** | Quit program |
| **Arrow keys** | Move around |
| **+** / **-** | Increase / Decrease iterations |
| **Space** | Reset view |
| **C** | Change color palette |
| **1 2 3 4** | Switch fractal |

### Mouse

| Action | Effect |
|:------:|:-------|
| **Scroll Up** | Zoom in |
| **Scroll Down** | Zoom out |
| **Mouse Move** (Julia) | Modify parameters in real-time |

---

## Compilation and Usage

### Compile the Program

```bash
# Compile (builds MLX42 + libft + fractol)
make

# Clean object files
make clean

# Clean everything
make fclean

# Recompile completely
make re
```

### Launch Examples

```bash
# Mandelbrot
./fractol mandelbrot

# Julia with parameters
./fractol julia -0.4 0.6
./fractol julia 0.285 0.01

# Burning Ship
./fractol burningship

# Tricorn
./fractol tricorn
```

---

## Implementation Highlights

<details>
<summary><b>Julia Parameter Presets</b></summary>

```bash
# Spiral
./fractol julia -0.4 0.6

# Snowflake
./fractol julia 0.285 0.01

# Dragon
./fractol julia -0.8 0.156

# Lace
./fractol julia -0.7269 0.1889
```

</details>

<details>
<summary><b>Color Palettes</b></summary>

4 different color palettes are available, switchable with the `C` key:

```c
// Palette examples
color = create_trgb(0, i * 9, i * 15, i * 20);   // Blue-red gradient
hue = (i * 360.0 / max_iter);                      // Rainbow
color = (i * 255 / max_iter) % 256;                // Psychedelic
```

</details>

<details>
<summary><b>Smooth Zoom</b></summary>

Zoom follows the mouse cursor position, allowing precise navigation into fractal details. The zoom factor and offset are recalculated relative to the cursor coordinates.

</details>

---

## Limitations

This implementation **DOES NOT support**:

- No multi-threading (single-threaded rendering)
- No GPU acceleration
- Fixed window size (800x800)

---

## Statistics

<div align="center">

| Metric | Value |
|:------:|:-----:|
| **Source files** | 9 .c |
| **Lines** | ~790 |
| **Fractals** | 4 |
| **Color palettes** | 4 |
| **Graphics lib** | MLX42 |

</div>

---

## Disclaimer

**This project has an educational purpose and you should under no circumstances copy and paste.**
**Cheat is bad. Don't cheat.**

**Ce projet a un but educatif et vous ne devez en aucun cas faire du copier-coller.**
**Tricher c'est mal. Ne trichez pas.**

---

<div align="center">

**Made with love for 42 Bangkok**

[![Back to top](https://img.shields.io/badge/Back_to_top-red?style=for-the-badge)](#fractol---fractal-explorer)

</div>
