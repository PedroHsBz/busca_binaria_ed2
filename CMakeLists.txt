cmake_minimum_required(VERSION 3.16)
project(busca_binaria_ed2 CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
add_compile_options(-Wall -Wextra)

# Cada arquivo tem seu próprio main()
add_executable(buscas     src/buscas.cpp)
add_executable(exercicio1 src/exercicio1.cpp)
add_executable(exercicio2 src/exercicio2.cpp)
