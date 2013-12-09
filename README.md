About
=====

This project has been developed as part of the "Commande par Ordinateur" course at [Polytech Nice Sophia](http://www.polytechnice.fr/), taught by [Joël Le Roux](http://users.polytech.unice.fr/~leroux/).

Dependencies
============

armadillo: C++ linear algebra library
gnuplot: Plotting package which outputs to X11, PostScript, PNG, GIF, and others

Usage
=====

Compile the project by using the `make` command in the main project directory.
You should get a `simulateur` executable.

Then, to plot the results, you can use something like:

    plot "radians.dat" using 1:2 title 'Simulation' with lines
