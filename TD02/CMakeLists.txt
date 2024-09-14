# Version minimale de CMake requise
cmake_minimum_required(VERSION 3.10)

# Nom du projet
project(TD02)

# include Eigen
find_package(Eigen3 REQUIRED)

if(${EIGEN3_FOUND})
    message(STATUS "lib EIGEN3 found")
    message(STATUS "  version " ${EIGEN3_VERSION_STRING})
    message(STATUS "  include " ${EIGEN3_INCLUDE_DIR})
else()
    message(FATAL_ERROR "lib EIGEN3 not found")
endif()

# Répertoire où se trouvent les fichiers sources
set(SRC_DIR "${CMAKE_SOURCE_DIR}/src")

# Ajout des fichiers sources
set(SOURCES_EXO_02 "${SRC_DIR}/exo_02.cpp" "${SRC_DIR}/utils.cpp")
set(SOURCES_EXO_03 "${SRC_DIR}/exo_03.cpp" "${SRC_DIR}/utils.cpp")
set(SOURCES_EXO_04 "${SRC_DIR}/exo_04.cpp" "${SRC_DIR}/utils.cpp")

# Inclusions des fichiers headers
include_directories("${SRC_DIR}")

# Déclaration de chaque exécutable (un pour chaque exercice)
add_executable(exo_02 ${SOURCES_EXO_02})
add_executable(exo_03 ${SOURCES_EXO_03})
add_executable(exo_04 ${SOURCES_EXO_04})

# compilation options
target_compile_features(exo_02 PRIVATE cxx_std_11) # use at least c++ 11
target_compile_features(exo_03 PRIVATE cxx_std_11) # use at least c++ 11
target_compile_features(exo_04 PRIVATE cxx_std_11) # use at least c++ 11

# lib include path
target_include_directories(exo_02 PRIVATE "${EIGEN3_INCLUDE_DIR}")
target_include_directories(exo_03 PRIVATE "${EIGEN3_INCLUDE_DIR}")
target_include_directories(exo_04 PRIVATE "${EIGEN3_INCLUDE_DIR}")