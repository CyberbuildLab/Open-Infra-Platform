# 	ConfigureDoxygen
#
# 	This is a configuration for the generation of doxygen documentation for the Open Infra Platform project. 
# 	ConfigureDoxygen is included in the top-level CMakeLists.txt of the project. 
#  	Changes to documentation settings should be made here. 
#  

file(MAKE_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/Doxymentation)

find_file(DOXYGEN_EXECUTABLE NAMES doxygen.exe HINTS
"C:/thirdparty/doxygen"
)

find_file(DOXYGEN_DOT_EXECUTABLE NAMES dot.exe HINTS
"C:/thirdparty/graphviz_dot/release/bin"
)

find_package(Doxygen
	REQUIRED dot
)

if(DOXYGEN_FOUND)
message("Use of DOXYGEN for developers: Please use this project's doxygen documentation style specified in ${CMAKE_CURRENT_SOURCE_DIR}/Documentation/doxymentation/StyleSheetOIP.")

# CONFIGURATION. Check http://www.doxygen.nl/manual/config.html for all available options and their default values. 

# Configuration file generation using CMake. 
set(DOXYFILE_CMAKE ${CMAKE_CURRENT_BINARY_DIR}/CMakeDoxyfile.in)
set(DOXYFILE ${CMAKE_CURRENT_BINARY_DIR}/Doxyfile)

# Build related configuration options. 
set(DOXYGEN_PROJECT_NAME OpenInfraPlatform)
set(DOXYGEN_PROJECT_BRIEF "Open source software for viewing and converting alignment data.")
#set(DOXYGEN_PROJECT_LOGO ${CMAKE_CURRENT_SOURCE_DIR}/Documentation/interface.png)
set(DOXYGEN_CREATE_SUBDIRS YES)
set(DOXYGEN_HAVE_DOT YES) # GraphViz Package for diagrams

# Documentation settings.
set(DOXYGEN_EXTRACT_ALL YES) # Set to yes if you want to extract all existing documentation  from project. Do this for now, once starting proper documentation change to NO. 
set(DOXYGEN_RECURSIVE YES) #Search subdirectories for input files as well.
set(DOXYGEN_INTERNAL_DOCS NO) # Comments intended for developers and not for users (*! \internal *)
set(DOXYGEN_CLASS_DIAGRAMS YES)

# Output (HTML/Latex/...) configuration options.
set(DOXYGEN_GENERATE_HTML YES)
set(DOXYGEN_GENERATE_LATEX NO)
set(DOXYGEN_OUTPUT_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/Doxymentation)
set(DOXYGEN_SEARCHENGINE YES)
set(DOXYGEN_SOURCE_BROWSER YES)
set(DOXYGEN_SUBGROUPING YES)
set(DOXYGEN_EXCLUDE_PATTERNS */CurrentlyExcluded/* */cmake/* */deploy/* */Documentation/* */external/* */testdata/* */Tools/* */UserInterface/QtPropertyBrowser/*)

configure_file(${DOXYFILE_CMAKE} ${DOXYFILE} @ONLY) 

# Documentation for entire OPEN INFRA PLATFORM project.
doxygen_add_docs(OpenInfraPlatform.GenerateDocumentation ALL
${CMAKE_CURRENT_SOURCE_DIR} 	# Source code that is (to be) documented located here
WORKING DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}	# Current root. Change if relative base point should be different.
COMMENT "Generating doxymentation for TUM Open Infra Platform project.")

add_custom_command(TARGET OpenInfraPlatform.GenerateDocumentation POST_BUILD
	COMMAND "${DOXYGEN_OUTPUT_DIRECTORY}/html/index.html"
)

else()
message("Doxygen not found. Please install doxygen using ${CMAKE_CURRENT_SOURCE_DIR}/external/Get_Doxygen.cmd to be able to generate documentation for the project. Please also install the GraphViz DOT package using ${CMAKE_CURRENT_SOURCE_DIR}/external/Get_Dot.cmd for rendering diagrams.")
endif(DOXYGEN_FOUND)


