# Introduction
I needed to integrate irregularly spaced data. I wanted something more precise that trapezoid, so I made this. The functionality is in SciPy, but I neede to use C++. Feel free to use if you need it.
  
To ensure it worked reasonably I simply integrated $x^{-1}$ from $10^{-n}$ to $10^n$ using logarithmically spaced points. Convergence seemed reasonable and precision for <100 points and low n also seemed reasonable.

Bug reports and comments welcome.
