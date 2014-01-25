# curl-asio
# Seamlessly integrate libcurl with Boost.Asio
#
# Copyright (c) 2013 Oliver Kuckertz <oliver.kuckertz@mologie.de>
# See COPYING for license information.

CMAKE_MINIMUM_REQUIRED(VERSION 2.6.2 FATAL_ERROR)
PROJECT(curl-asio)

# Adjust the module path
LIST(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake/")

# Build options
OPTION(BUILD_EXAMPLES "Build the examples" ON)

SET(CURLASIO_INCLUDE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/include")

IF(MSVC)
	# Select Windows version
	OPTION(ENABLE_VISTA_FEATURES "Enable Vista features. This disables some workarounds, but sacrifices Windows XP compatibility." OFF)
	IF(ENABLE_VISTA_FEATURES)
		SET(TARGET_WINDOWS_VERSION 0x0600)
	ELSE()
		SET(TARGET_WINDOWS_VERSION 0x0501)
	ENDIF()
	ADD_DEFINITIONS(-D_WIN32_WINNT=${TARGET_WINDOWS_VERSION})

	# Disable using __declspec(dllimport) when linking statically
	IF(NOT BUILD_SHARED_LIBS)
		ADD_DEFINITIONS(-DCURL_STATICLIB)
	ENDIF()
ENDIF()

# Find dependencies
FIND_PACKAGE(CURL REQUIRED)
FIND_PACKAGE(Boost REQUIRED COMPONENTS chrono date_time system thread)

# Move along
ADD_SUBDIRECTORY(src)
IF(BUILD_EXAMPLES)
	ADD_SUBDIRECTORY(examples)
ENDIF()

# Install FindCURL.cmake and FindCURLASIO.cmake
INSTALL(DIRECTORY cmake/ DESTINATION cmake)
