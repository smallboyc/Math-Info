#include <Eigen/Dense>
#include <chrono>
#include <iomanip> // std::setprecision
#include <iostream>

double dot_product(const Eigen::VectorXd &v1, const Eigen::VectorXd &v2) {
  double result = 0;
  for (int i = 0; i < v1.size(); i++)
    result += v1[i] * v2[i];
  return result;
}

int main() {
  // build a seed
  unsigned int seed =
      std::chrono::system_clock::now().time_since_epoch().count();
  srand(seed);

  // vectors dynamic size
  // Eigen::VectorXd v1(5);
  // v1 << 1, 2, 3, 4, 5;
  // v1(2) = 42;
  // std::cout << "v1 size : " << v1.size() << std::endl;
  // std::cout << "v1[2]   : " << v1(2) << std::endl;
  // std::cout << "v1 : " << v1.transpose() << std::endl << std::endl;

  // Eigen::VectorXd v2 = Eigen::VectorXd::Random(5);
  // std::cout << "v2 : " << v2.transpose() << std::endl << std::endl;

  // // vector static size
  // Eigen::Vector4f v3 = Eigen::Vector4f::Zero();
  // std::cout << "v3 : " << v3.transpose() << std::endl << std::endl;

  // v3 = Eigen::Vector4f::Ones();
  // std::cout << "v3 : " << v3.transpose() << std::endl << std::endl;

  // Eigen::Vector4f v4 = Eigen::Vector4f::Random();
  // std::cout << "v4 : " << v4.transpose() << std::endl << std::endl;
  // v4 = v4 + v3;
  // std::cout << "v4 : " << v4.transpose() << std::endl << std::endl;

  // // matrices dynamic size
  // Eigen::MatrixXd A = Eigen::MatrixXd::Random(3, 4);
  // std::cout << "A size : " << A.rows() << " x " << A.cols() << std::endl;
  // std::cout << "A(1,2) : " << A(1, 2) << std::endl;
  // std::cout << "A :\n" << A << std::endl << std::endl;

  // // matrices static size
  // Eigen::Matrix4d B = Eigen::Matrix4d::Random();
  // std::cout << "B :\n" << B << std::endl << std::endl;

  // // time computation
  // const unsigned int iter = 10000;
  // Eigen::MatrixXd C(3, 4);
  // auto start = std::chrono::steady_clock::now();
  // for (unsigned int i = 0; i < iter; ++i)
  //   C = A * B;
  // auto stop = std::chrono::steady_clock::now();
  // std::chrono::duration<double> elapsed_seconds = stop - start;
  // std::cout << "temps calcul du produit matriciel: " <<
  // elapsed_seconds.count()
  //           << " s" << std::endl;

  // // print samples
  // std::cout << "A + 2*A :\n" << A + 2 * A << std::endl << std::endl;
  // std::cout << "A * B :\n" << A * B << std::endl << std::endl;

  // TD02
  // EXO 02
  Eigen::VectorXd v1 = Eigen::VectorXd::Random(5);
  // v1 << 1, 2, 3, 4, 5;
  Eigen::VectorXd v2 = Eigen::VectorXd::Random(5);
  // v2 << 2, 3, 4, 5, 6;

  std::cout << "v1 : " << v1.transpose() << "\n";
  std::cout << "v2 : " << v2.transpose() << "\n";

  std::cout << "Produit scalaire (moi) : " << dot_product(v1, v2) << "\n";
  std::cout << "Produit scalaire (Eigen) : " << v1.dot(v2) << "\n";

  // time computation
  const unsigned int iter = 10000;

  // ME
  auto start = std::chrono::steady_clock::now();
  for (unsigned int i = 0; i < iter; ++i) {
    dot_product(v1, v2);
  }
  auto stop = std::chrono::steady_clock::now();

  std::chrono::duration<double> elapsed_seconds = stop - start;
  std::cout << "temps calcul du produit scalaire : " << elapsed_seconds.count()
            << " s" << std::endl;

  // EIGEN
  auto start_2 = std::chrono::steady_clock::now();
  for (unsigned int i = 0; i < iter; ++i) {
    v1.dot(v2);
  }
  auto stop_2 = std::chrono::steady_clock::now();

  std::chrono::duration<double> elapsed_seconds_2 = stop_2 - start_2;
  std::cout << "temps calcul du produit scalaire : "
            << elapsed_seconds_2.count() << " s" << std::endl;

  return 0;
}

// EXO 02
// 1 - Produit scalaire : m = n
// 2