# CMakeList.txt : projet CMake pour chaisse, incluez la source et définissez
# la logique spécifique au projet ici.
#
cmake_minimum_required (VERSION 3.8)
set(CMAKE_CXX_STANDARD 17)

project ("chaisse")

# Ajoutez une source à l'exécutable de ce projet.
add_executable (chaisse "src/main.cpp" "src/game/pieces/Piece.hpp" "src/game/pieces/Pawn.cpp"  "src/game/chess.cpp" "src/game/chess.hpp"   "src/game/pieces/Queen.hpp"      "src/game/logic.cpp" "src/game/logic.hpp"   "src/game/templates.hpp" "src/game/pieces/Queen.cpp"  "src/game/pieces/Pawn.hpp")

# Définit le dossier de sortie
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# TODO: Ajoutez des tests et installez des cibles si nécessaire.