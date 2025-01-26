/* Written by Albert Zhou <albert.zhou.50@gmail.com>
 * GPLv3
 *
 * Implementation:
 *
 * See paper by Cartwright, Journal of Mathematical Sciences & Mathematics Education Vol. 12 No. 2, and
 * https://en.wikipedia.org/wiki/Simpson%27s_rule#Composite_Simpson's_rule_for_irregularly_spaced_data
 * SciPy code doc also useful:
 * https://github.com/scipy/scipy/blob/df134eab5a500c2146ed4552c8674a78d8154ee9/scipy/integrate/_quadrature.py#L495
 */

#include <iostream>
#include <vector>
#include <cassert>

template<typename Float>
Float simpson(std::vector<Float>& x, std::vector<Float>& y) {
  std::cout.precision(10);
  std::cout << "Integrating data using simpson\n";
  std::cout << "x values go from " << x.front() << " to " << x.back() << std::endl;
  std::cout << "y values go from " << y.front() << " to " << y.back() << std::endl;

  if (x.size() != y.size()) {
    std::cerr << "x and y data not same size" << std::endl;
    return 0;
  }

  std::vector<Float> h;
  h.reserve(x.size()-1);
  for (size_t i=0; i<x.size()-1; ++i) {
    assert(x[i]<x[i+1]);
    h.push_back(x[i+1]-x[i]);
  }

  Float res = 0;
  size_t i;
  for (i=0; i+2<x.size(); i+=2) {
    Float dx = x[i+2]-x[i];
    assert(dx > 0);
    res += dx/6. * (
        (2 - h[i+1]/h[i])*y[i] + 
        dx*dx / (h[i+1]*h[i]) * y[i+1] +
        (2 - h[i]/h[i+1])*y[i+2]
        );
  }
  if (x.size()%2) {
    assert(h.size()%2 == 0);
    return res;
  }
  // Handle final interval
  assert(i == x.size()-2);
  assert(h.size()%2 == 1);
  Float h1 = h.back(), h2 = h[h.size()-2];
  res += h1/6 * (
      (2*h1 + 3*h2) / (h1 + h2) * y.back() +
      (h1 + 3*h2) / h2 * y[y.size()-2] -
      h1*h1 / (h2*(h1 + h2)) * y[y.size()-3]
      );
  return res;
}
