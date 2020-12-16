project(dtrace)

include(GNUInstallDirs)

add_library(dtrace SHARED src/dtrace.c)

set(DTRACE_PUBLIC_HEADERS "src/include/dt_common.h;src/include/dt_client.h")

set_target_properties(dtrace PROPERTIES PUBLIC_HEADER "${DTRACE_PUBLIC_HEADERS}")
target_include_directories(dtrace PRIVATE src/include)

install(TARGETS dtrace LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
	PUBLIC_HEADER DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})
