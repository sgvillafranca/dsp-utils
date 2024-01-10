# En este caso, ya que utils no contiene más subdirectorios, se procesan los archivos directamente desde aquí

# 1.  VINCULAMOS LOS ARCHIVOS CORRESPODIENTES A LA LIBRERIA 'UTILS'
add_library(${UTILS}
    SHARED
    dsp_operations.cpp
    FFTW_Convolver.cpp
    FFTW_Correlator.cpp
)

# 2. INDICAR A CMAKE DÓNDE BUSCAR LAS CABECERAS, DOS OPCIONES POSIBLES:
# -  Opción A: Solo se referencia hasta src. En este caso: #include "utils/utils.hpp"
target_include_directories(
    ${UTILS} 
    PRIVATE
    ${CMAKE_SOURCE_DIR}/src
    ${CMAKE_SOURCE_DIR}/include
)
##  - Opción B: Referenciar hasta donde está la cabecera. En este caso: #include "utils.hpp"
# target_include_directories(${UTILS} 
#     PUBLIC
#     $(CMAKE_CURRENT_LIST_DIR)
#)
