project(dtrace)

include(GNUInstallDirs)

add_library(dtrace SHARED src/dtrace.c)

set_target_properties(dtrace PROPERTIES PUBLIC_HEADER src/include/dtrace.h)
target_include_directories(dtrace PRIVATE .)

install(TARGETS dtrace LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
	PUBLIC_HEADER DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})
