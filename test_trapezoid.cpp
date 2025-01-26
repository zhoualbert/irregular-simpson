#include <iostream>
#include <cmath>
#include <cassert>
#include <vector>

using VecDbl = std::vector<double>;
using std::pow, std::log;

double trapezoid(std::vector<double> &x, std::vector<double> &y) {
  assert(x.size() == y.size());
  double res = 0;
  for (size_t i=1; i<x.size(); ++i) {
    assert(x[i]>x[i-1]);
    res += 0.5*(y[i]+y[i-1])*(x[i]-x[i-1]);
  }
  return res;
}

int main() {
  std::cout.precision(10);
  { // Test even number of intervals case
    VecDbl x, y;
    for (int i=-4; i<=16; ++i) {
      x.push_back(pow(10, 0.25*i));
      y.push_back(1/x.back());
    }
    std::cout << "Number of x: " << x.size() << std::endl;
    double expected = 5*log(10);
    double actual = trapezoid(x, y);
    std::cout << "Expected = " << expected << "; actual = " << actual << std::endl;
    std::cout << "Relative error = " << 1 - actual/expected << std::endl;
    std::cout << "Relative error * num points = " << (1 - actual/expected)*x.size() << std::endl;
  }
  { // Test even number of intervals case
    VecDbl x, y;
    for (int i=-5; i<=20; ++i) {
      x.push_back(pow(10, 0.2*i));
      y.push_back(1/x.back());
    }
    std::cout << "Number of x: " << x.size() << std::endl;
    double expected = 5*log(10);
    double actual = trapezoid(x, y);
    std::cout << "Expected = " << expected << "; actual = " << actual << std::endl;
    std::cout << "Relative error = " << 1 - actual/expected << std::endl;
    std::cout << "Relative error * num points = " << (1 - actual/expected)*x.size() << std::endl;
  }
  { // Test even number of intervals case
    VecDbl x, y;
    for (int i=-8; i<=32; ++i) {
      x.push_back(pow(10, 0.125*i));
      y.push_back(1/x.back());
    }
    std::cout << "Number of x: " << x.size() << std::endl;
    double expected = 5*log(10);
    double actual = trapezoid(x, y);
    std::cout << "Expected = " << expected << "; actual = " << actual << std::endl;
    std::cout << "Relative error = " << 1 - actual/expected << std::endl;
    std::cout << "Relative error * num points = " << (1 - actual/expected)*x.size() << std::endl;
  }
  { // Test even number of intervals case
    VecDbl x, y;
    for (int i=-100; i<=100; ++i) {
      x.push_back(pow(10, 0.1*i));
      y.push_back(1/x.back());
    }
    std::cout << "Number of x: " << x.size() << std::endl;
    double expected = 20*log(10);
    double actual = trapezoid(x, y);
    std::cout << "Expected = " << expected << "; actual = " << actual << std::endl;
    std::cout << "Relative error = " << 1 - actual/expected << std::endl;
    std::cout << "Relative error * num points = " << (1 - actual/expected)*x.size() << std::endl;
  }
  { // Test even number of intervals case
    VecDbl x, y;
    for (int i=-1000; i<=1000; ++i) {
      x.push_back(pow(10, 0.01*i));
      y.push_back(1/x.back());
    }
    std::cout << "Number of x: " << x.size() << std::endl;
    double expected = 20*log(10);
    double actual = trapezoid(x, y);
    std::cout << "Expected = " << expected << "; actual = " << actual << std::endl;
    std::cout << "Relative error = " << 1 - actual/expected << std::endl;
    std::cout << "Relative error * num points = " << (1 - actual/expected)*x.size() << std::endl;
  }

  std::cout << "--------------------------------------------------------------------------\n";

  { // Test odd number of intervals case
    VecDbl x, y;
    for (int i=-4; i<16; ++i) {
      x.push_back(pow(10, 0.25*i));
      y.push_back(1/x.back());
    }
    std::cout << "Number of x: " << x.size() << std::endl;
    double expected = (15./4+1)*log(10);
    double actual = trapezoid(x, y);
    std::cout << "Expected = " << expected << "; actual = " << actual << std::endl;
    std::cout << "Relative error = " << 1 - actual/expected << std::endl;
    std::cout << "Relative error * num points = " << (1 - actual/expected)*x.size() << std::endl;
  }
  { // Test odd number of intervals case
    VecDbl x, y;
    for (int i=-5; i<20; ++i) {
      x.push_back(pow(10, 0.2*i));
      y.push_back(1/x.back());
    }
    std::cout << "Number of x: " << x.size() << std::endl;
    double expected = (19./5+1)*log(10);
    double actual = trapezoid(x, y);
    std::cout << "Expected = " << expected << "; actual = " << actual << std::endl;
    std::cout << "Relative error = " << 1 - actual/expected << std::endl;
    std::cout << "Relative error * num points = " << (1 - actual/expected)*x.size() << std::endl;
  }
  { // Test odd number of intervals case
    VecDbl x, y;
    for (int i=-8; i<32; ++i) {
      x.push_back(pow(10, 0.125*i));
      y.push_back(1/x.back());
    }
    std::cout << "Number of x: " << x.size() << std::endl;
    double expected = (31./8+1)*log(10);
    double actual = trapezoid(x, y);
    std::cout << "Expected = " << expected << "; actual = " << actual << std::endl;
    std::cout << "Relative error = " << 1 - actual/expected << std::endl;
    std::cout << "Relative error * num points = " << (1 - actual/expected)*x.size() << std::endl;
  }
  { // Test odd number of intervals case
    VecDbl x, y;
    for (int i=-99; i<=100; ++i) {
      x.push_back(pow(10, 10./99.*i));
      y.push_back(1/x.back());
    }
    std::cout << "Number of x: " << x.size() << std::endl;
    double expected = (1e3/99 + 10)*log(10);
    double actual = trapezoid(x, y);
    std::cout << "Expected = " << expected << "; actual = " << actual << std::endl;
    std::cout << "Relative error = " << 1 - actual/expected << std::endl;
    std::cout << "Relative error * num points = " << (1 - actual/expected)*x.size() << std::endl;
  }
  { // Test odd number of intervals case
    VecDbl x, y;
    for (int i=-999; i<=1000; ++i) {
      x.push_back(pow(10, 10./999.*i));
      y.push_back(1/x.back());
    }
    std::cout << "Number of x: " << x.size() << std::endl;
    double expected = (1e4/999 + 10)*log(10);
    double actual = trapezoid(x, y);
    std::cout << "Expected = " << expected << "; actual = " << actual << std::endl;
    std::cout << "Relative error = " << 1 - actual/expected << std::endl;
    std::cout << "Relative error * num points = " << (1 - actual/expected)*x.size() << std::endl;
  }
}
