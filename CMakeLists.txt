cmake_minimum_required(VERSION 3.10)
project(manul VERSION 0.0.1)

list(APPEND CMAKE_MODULE_PATH ${CMAKE_BINARY_DIR})
list(APPEND CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/cmake)
list(APPEND CMAKE_PREFIX_PATH ${CMAKE_BINARY_DIR})

include(glib-resource-compiler)

find_package(PkgConfig REQUIRED)
pkg_check_modules(GTK4 REQUIRED gtk4)
pkg_check_modules(gmodule REQUIRED libgmodule-2)
pkg_check_modules(adwaita REQUIRED libadwaita-1)
pkg_check_modules(libpeas REQUIRED libpeas-2)
pkg_check_modules(gtksourceview REQUIRED gtksourceview-5)

include_directories(${GTK4_INCLUDE_DIRS} ${adwait_INCLUDE_DIRS} ${libpeas_INCLUDE_DIRS} ${gtksourceview_INCLUDE_DIRS} ${libgmodule_INCLUDE_DIRS})
link_directories(${GTK4_LIBRARY_DIRS} ${adwait_LIBRARY_DIRS} ${libpeas_LIBRARY_DIRS} ${gtksourceview_LIBRARY_DIRS} ${libgmodule_LIBRARY_DIRS})
add_definitions(${GTK_CFLAGS_OTHER} ${adawit_CFLAGS_OTHER} ${libpeas_CFLAGS_OTHER} ${gtksourceview_CFLAGS_OTHER} ${libgmodule_CFLAGS_OTHER})


set(UI_RESOURCE_TARGET ${CMAKE_CURRENT_SOURCE_DIR}/src/ui_resources.c)

add_custom_command(OUTPUT ${UI_RESOURCE_TARGET}
  COMMAND ${GLIB_COMPILE_RESOURCES} ${CMAKE_CURRENT_SOURCE_DIR}/src/manul.gresource.xml --target=${UI_RESOURCE_TARGET} --generate-source --sourcedir=${CMAKE_CURRENT_SOURCE_DIR}/src
  COMMENT "Generate resourcefile "
  DEPEND ${CMAKE_CURRENT_SOURCE_DIR}/src/manul.gresource.xml
)


message(STATUS "${GLIB_COMPILE_RESOURCES}")
message(STATUS "${CMAKE_CURRENT_SOURCE_DIR}/src/manul.gresource.xml")
message(STATUS "${UI_RESOURCE_TARGET}")
message(STATUS "${CMAKE_CURRENT_SOURCE_DIR}/src")

list(APPEND MANUL_SRC
  main.c
  manulapp.c
)

list(TRANSFORM MANUL_SRC PREPEND ${CMAKE_CURRENT_SOURCE_DIR}/src/)

add_executable(manul ${MANUL_SRC} ${UI_RESOURCE_TARGET})
target_link_libraries(manul ${GTK4_LIBRARIES} ${adwaita_LIBRARIES} ${libpeas_LIBRARIES} ${gtksourceview_LIBRARIES})

