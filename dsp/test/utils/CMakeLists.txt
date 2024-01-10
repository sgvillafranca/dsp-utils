set(
  TEST_LIST
  ${CMAKE_CURRENT_SOURCE_DIR}/utils_test.cpp
)

##################################################################################################
##### COMPILE TEST EXECUTABLE FILE (LIBRARY SPECIFIC) ############################################ 
##################################################################################################

set(TEST utils_tests)       # Establece nombre del ejecutable de test
set(TARGET  tests_utils)    # Establece nombre del target de compilación

# Add tests source files after main
add_executable(
  ${TEST} 
  ${CMAKE_SOURCE_DIR}/test/test.cpp                  # This one goes first as it tells Catch to provide a main()
  ${TEST_LIST}
)

# - Vinculamos el ejecutable main al código contenido en main.cpp
target_include_directories(
  ${TEST}
  PRIVATE
    ${CMAKE_SOURCE_DIR}/src
    ${CMAKE_SOURCE_DIR}/test
    ${CMAKE_SOURCE_DIR}/include
)

# Link catch library for test running
# Link project library for testing
target_link_libraries(
  ${TEST}
  PRIVATE
    Catch2::Catch2WithMain
    ${UTILS}
    lapack
    openblas
    armadillo
    fftw3
)

target_compile_options(
  ${TEST}
  PRIVATE
    "-Wall" "-pedantic" "-Wextra"
)

# Configuramos tests como objetivo independiente en la compilación (cmake --build . --target TARGET)
add_custom_target(
  ${TARGET}
  DEPENDS
  ${TEST}
)

