# 2048

2048 game using Raylib

## usage

MacOS: Use the executable (`2048`)

### Linux

Make sure you have the raylib header files in your compiler's include path.

If you do not have `openssl` (Mac and Linux should have this pre-installed), run the executable with the `--disable-high-score` flag.
(High scores will not work without `openssl`)

```
./2048 --disable-high-score
```

```fish
# clone repo
git clone https://github.com/carrotfarmer/2048 2048
cd 2048

# compile and link w/ raylib
eval cc main.c utils.c game.c $(pkg-config --libs --cflags raylib) -o 2048

# run
./2048
```

### Windows

## screenshots

![image](https://i.imgur.com/Kq6KlWM.png)
