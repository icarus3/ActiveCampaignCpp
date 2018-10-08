add_executable (Test Test.cpp)

set(GTEST_INCLUDE_DIR include)
set(GTEST_LIB_DIR gtestlib)

include_directories(${GTEST_INCLUDE_DIR})
include_directories(../${HEADER_DIR_1})
include_directories(../${CURL_HEADER_DIR})

find_library(GTEST_LIB gtestd.lib HINTS ${GTEST_LIB_DIR})

if(MSVC)
   target_link_libraries(Test ${PROJECT_NAME}_lib legacy_stdio_definitions.lib Normaliz.lib Wldap32.lib crypt32.lib Ws2_32.lib ${GTEST_LIB} ${CURL_LIB} kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib )
endif(MSVC)
