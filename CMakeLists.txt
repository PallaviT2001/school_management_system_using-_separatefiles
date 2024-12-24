cmake_minimum_required(VERSION 3.16)

project(Project1 LANGUAGES C)

add_executable(Project1 main.c
    admin.h
    student.h
    faculty.h
    fees.h
    section.h
    fileoperation.h
    main1.h
    admin.c
    faculty.c
    fees.c
    fileoperation.c
    main1.c
    section.c
    student.c


)

include(GNUInstallDirs)
install(TARGETS Project1
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
