#include <iostream>
#include <cstdlib> // For abs()
using namespace std;

// Function to plot a pixel (here, we print '*' at the coordinates)
void plotPixel(int x, int y, char** grid, int width, int height) {
    if (x >= 0 && x < width && y >= 0 && y < height) {
        grid[y][x] = '*';
    }
}

// Bresenham's Line Drawing Algorithm
void bresenhamLine(int x0, int y0, int x1, int y1, char** grid, int width, int height) {
    int dx = abs(x1 - x0);
    int dy = abs(y1 - y0);
    int sx = x0 < x1 ? 1 : -1;
    int sy = y0 < y1 ? 1 : -1;
    int err = dx - dy;

    while (true) {
        // Plot the current pixel
        plotPixel(x0, y0, grid, width, height);

        // Check if we've reached the end point
        if (x0 == x1 && y0 == y1) break;

        int e2 = 2 * err;
        if (e2 > -dy) {
            err -= dy;
            x0 += sx;
        }
        if (e2 < dx) {
            err += dx;
            y0 += sy;
        }
    }
}

// Function to display the grid
void displayGrid(char** grid, int width, int height) {
    for (int y = height - 1; y >= 0; y--) { // Print from top to bottom
        for (int x = 0; x < width; x++) {
            cout << (grid[y][x] ? grid[y][x] : '.') << ' ';
        }
        cout << endl;
    }
}

int main() {
    // Define grid dimensions
    const int width = 20;
    const int height = 20;

    // Initialize grid with empty spaces
    char** grid = new char*[height];
    for (int i = 0; i < height; i++) {
        grid[i] = new char[width];
        for (int j = 0; j < width; j++) {
            grid[i][j] = 0; // Empty pixel
        }
    }

    // Define line endpoints
    int x0 = 2, y0 = 3;
    int x1 = 15, y1 = 10;

    // Draw the line using Bresenham's algorithm
    bresenhamLine(x0, y0, x1, y1, grid, width, height);

    // Display the grid
    cout << "Bresenham's Line from (" << x0 << "," << y0 << ") to (" << x1 << "," << y1 << "):" << endl;
    displayGrid(grid, width, height);

    // Clean up memory
    for (int i = 0; i < height; i++) {
        delete[] grid[i];
    }
    delete[] grid;

    return 0;
}