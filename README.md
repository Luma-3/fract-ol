<h1 align="center">
	42 Project - Fract-ol
</h1>

<p align="center">
	<b><i> Art Fractal !</i></b>
</p>

<p align="center">
	<img src="https://github.com/Luma-3/Luma-3/blob/main/badges/fract-olm.png" alt="fractol_logo" />
</p>

---
<p align="center">
	<img src="https://img.shields.io/badge/Score-125-blue?style=flat-square&logo=42" alt="Score project :125"/>
	<img alt="Static Badge" src="https://img.shields.io/badge/Outstanding-3-blue?style=flat-square&logo=42">
	<img alt="GitHub repo size" src="https://img.shields.io/github/repo-size/Luma-3/fract-ol?style=flat-square&logo=github">
</p>



## Overview

This project serves an educational purpose and is based on the **common core of 42 School**. Therefore, it is subject to educational restrictions. Please be aware of these restrictions before making any contributions.

Please note that due to the private nature of the subject, it cannot be publicly shared on this GitHub repository.


## 📄 Description

In this project, we aim to create a stunning fractal visualizer using the [MinilibX library](https://github.com/42Paris/minilibx-linux) in C!

This project marks the beginning of C graphical projects in the 42 Commun-Core! Key skills to learn here include memory management, algorithm optimization, and window handling.

My project offers three types of fractals as well as two color sets: [Julia](https://en.wikipedia.org/wiki/Julia_set), [Mandelbrot](https://en.wikipedia.org/wiki/Mandelbrot_set), and [Burning-ship](https://en.wikipedia.org/wiki/Burning_Ship_fractal).

For more information on fractals, you can check out this link to [Wikipedia](https://en.wikipedia.org/wiki/Fractal).

I have implemented an optimization system for calculating the Mandelbrot fractal, by computing central buds and main cardioids.

Additionally, optimization by pixel group has been implemented across all fractal sets.

## 📥 Installation

Installation and compilation commands :

```
git clone --recursive https://github.com/Luma-3/fract-ol.git
cd fract-ol
cd lib/minilibx && ./configure && cd -
make
```


## 🦆 Usage

For launch Fract-ol :
```
./fractol
```

An message appear and explain you how to use fract-ol. Have fun !
### Key bind : 

- Arrow key for move fractal.

- C and V to change colors.

- mouse scroll , + and - for zoom in fractal.

---

This work is published under the terms of **[42 Unlicense](https://github.com/gcamerli/42unlicense)**.
