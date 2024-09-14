#include <iostream>

// void un_p(double const &un, int &i) {
//   if (i == 550)
//     return;
//   double result = 4 * un - 1;
//   std::cout << result << std::endl;
//   i++;
//   un_p(result, i);
// }

// int main() {
//   double u0 = 1 / double(3);
//   int i = 0;
//   un_p(u0, i);
//   return 0;
// }

int main() {

  int a = 13;
  int b = 320;
  int residu = 0;
  while (a != 1) {
    if ((1 & a)) // impair
      residu += b;
    a = a >> 1;
    b = b << 1;
  }
  std::cout << residu + b << std::endl;
}