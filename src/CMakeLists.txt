# curl-asio
# Seamlessly integrate libcurl with Boost.Asio
#
# Copyright (c) 2013 Oliver Kuckertz <oliver.kuckertz@mologie.de>
# See COPYING for license information.

INCLUDE_DIRECTORIES(
	${CURLASIO_INCLUDE_DIR}
	${CURL_INCLUDE_DIR}
	${Boost_INCLUDE_DIRS}
	)

# Collect all source files
SET(LIBCURLASIO_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}")
FILE(GLOB LIBCURLASIO_SOURCE_FILES "${LIBCURLASIO_SOURCE_DIR}/*.cpp")

# Collect all header files
SET(LIBCURLASIO_HEADER_DIR "${CMAKE_CURRENT_SOURCE_DIR}/../include")
FILE(GLOB LIBCURLASIO_HEADER_FILES "${LIBCURLASIO_HEADER_DIR}/curl-asio/*.h")
LIST(APPEND LIBCURLASIO_HEADER_FILES "${LIBCURLASIO_HEADER_DIR}/curl-asio.h")

# Install targets
SET(CURLASIO_INSTALL_TARGETS)

ADD_LIBRARY(
		curlasio
		${LIBCURLASIO_SOURCE_FILES}
		${LIBCURLASIO_HEADER_FILES}
		)
	TARGET_LINK_LIBRARIES(curlasio ${Boost_LIBRARIES} ${CURL_LIBRARIES})
	LIST(APPEND CURLASIO_INSTALL_TARGETS curlasio)

# Install all libraries/archives to $PREFIX/lib (and DLLs to $PREFIX/bin on Windows)
INSTALL(TARGETS ${CURLASIO_INSTALL_TARGETS}
	RUNTIME DESTINATION bin
	LIBRARY DESTINATION lib
	ARCHIVE DESTINATION lib
	)

# Install header files to $PREFIX/include
INSTALL(DIRECTORY "${LIBCURLASIO_HEADER_DIR}/" DESTINATION include)
