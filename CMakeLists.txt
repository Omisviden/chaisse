# CMakeList.txt : projet CMake pour chaisse, incluez la source et définissez
# la logique spécifique au projet ici.
#
cmake_minimum_required (VERSION 3.8)

project ("chaisse")

# Ajoutez une source à l'exécutable de ce projet.
add_executable (chaisse "src/main.cpp" "src/Piece.cpp" "src/Pawn.cpp"  "src/chess.cpp" "src/chess.hpp"   "src/Pawn.hpp"  )

#défini le dossier de sortie
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# TODO: Ajoutez des tests et installez des cibles si nécessaire.