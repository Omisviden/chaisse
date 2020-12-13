# CMakeList.txt : projet CMake pour chaisse, incluez la source et définissez
# la logique spécifique au projet ici.
#
cmake_minimum_required (VERSION 3.8)

project ("chaisse")

#défini le dossier de sortie
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# Ajoutez une source à l'exécutable de ce projet.
add_executable (chaisse "src/chaisse.cpp")
add_executable (server "src/srv/server.hpp" "src/srv/server.cpp")

# TODO: Ajoutez des tests et installez des cibles si nécessaire.
