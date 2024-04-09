# Newton Fractals

The Newton Fractals program generates fractal images by depicting the attraction basins of Newton's method for a polynomial on the complex plane. The resulting images exhibit symmetrical patterns, wherein convergence to the nearest of the three roots occurs based on the quadrant of the complex plane.<br/>
The `matlab` folder contains all the functions used to compute the final image, execute the main `newtonfractal` function to display the image:
```matlab
newtonfractal();
```
In addition, there's a more efficient version of the program implemented in C. This version generates the fractal matrix and saves it into a file. A separate MATLAB script named `visualizer.m` is provided, which can read the matrix file and visualize the fractal image. To Execute it providing a polynomial represented as a coefficient vector:
```
gcc -o newton newton.c
./newton 2 -4 0 1 -3

visualizer();
```
![image](https://github.com/SeoDecre/newton-fractal/assets/49351323/1a965655-8c73-49b6-a363-b2fd563813c5)


## Implementation Details

### Polynomial Manipulation
The program manipulates polynomials by representing them as coefficient vectors. Horner's method is utilized to evaluate polynomials efficiently.

### Newton's Method
Newton's method is employed iteratively to approximate roots of polynomials.

### Visualization
The MATLAB `imagesc` function is utilized to visualize matrices, depicting them as images with color variations based on element magnitudes.<br/>

### Newton Fractal Generation
To generate Newton fractals, the program determines convergence to roots using a decision function. It then computes fractal images based on Newton's method iterations.

## Functions
The program consists of several functions:

1. `horner(p, x)`: Evaluates a polynomial represented by coefficient vector `p` at point `x` using Horner's method.
2. `derivative(p)`: Computes the derivative of a polynomial represented by coefficient vector `p`.
3. `newton(p, x0)`: Executes Newton's method on polynomial `p` starting from initial point `x0`.
4. `decide(x)`: Determines convergence to one of the three roots based on the complex number `x`.
5. `newtonfractal()`: Generates a 101x101 matrix representing the Newton fractal for the polynomial x^3 + 1.