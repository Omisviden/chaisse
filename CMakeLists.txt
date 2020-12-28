# CMakeList.txt : projet CMake pour chaisse, incluez la source et définissez
# la logique spécifique au projet ici.
#
cmake_minimum_required (VERSION 3.8)
set(CMAKE_CXX_STANDARD 17)

project ("chaisse")

#défini le dossier de sortie
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

set(COMMUNICATION "src/com/connection.hpp" "src/com/connection.cpp")

# Ajoutez une source à l'exécutable de ce projet.
add_executable (chaisse "src/chaisse.cpp")
add_executable (server ${COMMUNICATION} "src/srv/server.hpp" "src/srv/server.cpp")
add_executable (client ${COMMUNICATION} "src/cli/client.hpp" "src/cli/client.cpp")
# TODO: Ajoutez des tests et installez des cibles si nécessaire.
