# Busca la librería catch2 para testing
find_package(Catch2 3.0.0 REQUIRED)

# Tratamos a cada bloque de testing de manera independiente
add_subdirectory(utils)
