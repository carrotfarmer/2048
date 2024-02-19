#pragma once

// movements
void down(int grid[4][4], int *score);
void up(int grid[4][4], int *score);
void left(int grid[4][4], int *score);
void right(int grid[4][4], int *score);

bool isGameOver(int grid[4][4], int *score);
void incrScore(int *score, int value);

void genTile(int grid[4][4]);
