project(dtrace)

include(GNUInstallDirs)

set(DTRACE_PUBLIC_HEADERS "src/include/dt_common.h;src/include/dt_client.h;src/include/dt_server.h")

add_library(dt_client SHARED src/dt_client.c)
set_target_properties(dt_client PROPERTIES PUBLIC_HEADER "${DTRACE_PUBLIC_HEADERS}")
target_include_directories(dt_client PRIVATE src/include)

add_library(dt_server SHARED src/dt_client.c)
set_target_properties(dt_server PROPERTIES PUBLIC_HEADER "${DTRACE_PUBLIC_HEADERS}")
target_include_directories(dt_server PRIVATE src/include)

install(TARGETS dt_client dt_server LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
	PUBLIC_HEADER DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})
