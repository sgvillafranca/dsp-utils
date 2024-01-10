
# Librerias (subdirectorios) a compilar dentro de src
add_subdirectory(utils)

##################################################################################################
##### COMPILE MAIN FILE (Debbuging purposes) ##################################################### 
##################################################################################################

# - Vinculamos el ejecutable main al código contenido en main.cpp
add_executable(
  ${MAIN}
  main.cpp
)

# - Indicamos donde buscar las cabeceras (Opción A: Veáse CMakeLists de utils)
target_include_directories(
  ${MAIN}
  PUBLIC
    ${CMAKE_SOURCE_DIR}/include
  PRIVATE    
    ${CMAKE_SOURCE_DIR}/src   
)

# - Añadimos opciones de compilación
target_compile_options(
  ${MAIN}
  PRIVATE
    "-Wall" "-pedantic" "-Wextra"
)

# - Linkeamos con main los objetos (librerias compiladas) que queramos usar desde dicho ejecutable
target_link_libraries(
  ${MAIN}
  ${UTILS}
)