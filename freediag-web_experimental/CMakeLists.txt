cmake_minimum_required(VERSION 3.0)

project(freediag-web C CXX)

include(${CMAKE_CURRENT_SOURCE_DIR}/src.wsjcpp/CMakeLists.txt)

set(CMAKE_CXX_STANDARD 11)
set(EXECUTABLE_OUTPUT_PATH ${freediag-web_SOURCE_DIR})

configure_file (../cconf.h.in ../cconf.h)

# include header dirs
list (APPEND WSJCPP_INCLUDE_DIRS "../")
list (APPEND WSJCPP_INCLUDE_DIRS "src")
list (APPEND WSJCPP_INCLUDE_DIRS "../scantool/")

list (APPEND WSJCPP_SOURCES "src/main.cpp")
list (APPEND WSJCPP_SOURCES "../scantool/scantool.c")
list (APPEND WSJCPP_SOURCES "../scantool/scantool_test.c")

list (APPEND WSJCPP_SOURCES "../scantool/scantool_vag.c")
list (APPEND WSJCPP_SOURCES "../scantool/scantool_850.c")
list (APPEND WSJCPP_SOURCES "../scantool/scantool_dyno.c")
list (APPEND WSJCPP_SOURCES "../scantool/scantool_obd.c")
list (APPEND WSJCPP_SOURCES "../scantool/scantool_aif.c")

list (APPEND WSJCPP_SOURCES "../scantool/diag.h")
list (APPEND WSJCPP_SOURCES "../scantool/diag_l2_d2.h")
list (APPEND WSJCPP_SOURCES "../scantool/diag_l3_saej1979.h")
list (APPEND WSJCPP_SOURCES "../scantool/diag_tty_unix.h")
list (APPEND WSJCPP_SOURCES "../scantool/diag_cfg.h")
list (APPEND WSJCPP_SOURCES "../scantool/diag_l2_iso14230.h")
list (APPEND WSJCPP_SOURCES "../scantool/diag_l3_vag.h")
list (APPEND WSJCPP_SOURCES "../scantool/diag_tty_win.h")
list (APPEND WSJCPP_SOURCES "../scantool/diag_dtc.h")
list (APPEND WSJCPP_SOURCES "../scantool/diag_l2_iso9141.h")
list (APPEND WSJCPP_SOURCES "../scantool/diag_l7.h") 
list (APPEND WSJCPP_SOURCES "../scantool/diag_vag.h")
list (APPEND WSJCPP_SOURCES "../scantool/diag_err.h")
list (APPEND WSJCPP_SOURCES "../scantool/diag_l2_mb1.h")
list (APPEND WSJCPP_SOURCES "../scantool/diag_l7_d2.h")
list (APPEND WSJCPP_SOURCES "../scantool/dyno.h")
list (APPEND WSJCPP_SOURCES "../scantool/diag_iso14230.h")
list (APPEND WSJCPP_SOURCES "../scantool/diag_l2_raw.h")
list (APPEND WSJCPP_SOURCES "../scantool/diag_l7_kwp71.h")
list (APPEND WSJCPP_SOURCES "../scantool/scantool.h")
list (APPEND WSJCPP_SOURCES "../scantool/diag_l0.h") 
list (APPEND WSJCPP_SOURCES "../scantool/diag_l2_saej1850.h")
list (APPEND WSJCPP_SOURCES "../scantool/diag_mb1.h")
list (APPEND WSJCPP_SOURCES "../scantool/scantool_aif.h")
list (APPEND WSJCPP_SOURCES "../scantool/diag_l1.h")
list (APPEND WSJCPP_SOURCES "../scantool/diag_l2_vag.h")
list (APPEND WSJCPP_SOURCES "../scantool/diag_os.h")
list (APPEND WSJCPP_SOURCES "../scantool/scantool_cli.h")
list (APPEND WSJCPP_SOURCES "../scantool/diag_l2.h")
list (APPEND WSJCPP_SOURCES "../scantool/diag_l3.h")
list (APPEND WSJCPP_SOURCES "../scantool/diag_os_unix.h")
list (APPEND WSJCPP_SOURCES "../scantool/scantool_obd.h")
list (APPEND WSJCPP_SOURCES "../scantool/diag_l2_can.h")
list (APPEND WSJCPP_SOURCES "../scantool/diag_l3_iso14230.h")
list (APPEND WSJCPP_SOURCES "../scantool/diag_tty.h")
list (APPEND WSJCPP_SOURCES "../scantool/utlist.h")

#### BEGIN_WSJCPP_APPEND
#### END_WSJCPP_APPEND

include_directories(${WSJCPP_INCLUDE_DIRS})

add_executable (freediag-web ${WSJCPP_SOURCES})



target_link_libraries(freediag-web ${WSJCPP_LIBRARIES})

install(
    TARGETS
        freediag-web
    RUNTIME DESTINATION
        /usr/bin
)

