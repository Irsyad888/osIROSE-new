
link_directories(${EXTERNAL_BINARY_DIR})

set(PROJECT Bot)

project(${PROJECT})

add_compiler_flags($<$<CXX_COMPILER_ID:Clang>:-Wno-keyword-compat>)

SET( SOURCES_MAIN
  src/main.cpp )

SET( SOURCES_HEADER
    )

SET( SOURCES_BASE
    )

add_executable(${PROJECT} ${SOURCES_MAIN} ${SOURCES_BASE} ${SOURCES_HEADER})

target_include_directories(${PROJECT} PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>)
target_compile_options(${PROJECT} PRIVATE $<$<CXX_COMPILER_ID:GNU>:-Wno-packed-bitfield-compat -Wl,-Map=$<TARGET_NAME:${PROJECT}>.map>)

if(WITH_MYSQL)
  target_link_libraries(${PROJECT} ${MYSQL_LIBRARIES})
endif()

if(WITH_CRASH_REPORTS)
  if(NOT BREAKPAD_FOUND)
    add_dependencies(${PROJECT} breakpad-build)
  endif()
endif()

add_dependencies(${PROJECT} RoseCommon)
target_link_libraries(${PROJECT} RoseCommon)
target_link_libraries(${PROJECT} ${CMAKE_THREAD_LIBS_INIT})

if (MSVC)
  set_target_properties(${PROJECT} PROPERTIES COMPILE_FLAGS "/wd4503")
  target_link_libraries(${PROJECT} wsock32.lib)
endif()

generate_symbol_data(${PROJECT})

SET_PROPERTY(TARGET ${PROJECT}                PROPERTY FOLDER "Tools")
