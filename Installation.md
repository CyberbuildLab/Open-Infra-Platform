# REQUIREMENTS

- Qt 5.12.2 Installed and included in path. Get the general installer (free) and select 5.12.2 during the installation 

- Boost 1_65_1 Installed and included in path. Get it at https://sourceforge.net/projects/boost/files/boost-binaries/1.65.1/



# STEPS FOR BUILDING THE OIP SOLUTION IN MSVC

In **Git GUI**:

- Clone CyberBuildLab OIP repo https://github.com/CyberbuildLab/Open-Infra-Platform


In **CMAKE** (x64)

- Empty "build" folder (very important)

- click on "Configure"

- Set the following CMake variables:
	- EARLYBINDING: Check IFC4x1
	- CMAKE_INSTALL_PATH: C:/Projects/Open-Infra-Platform (where you have the project)
	- INSTALL: C:/Projects/Open-Infra-Platform/bin, /include, /lib, etc
	- MODULES: Check "MODULES_POINT_CLOUD_PROCESSING"
	
- click on "Configure" ("Configuring done" message)

- *IF* you want to add e57 support: 

	- Set the following CMake variables:
		- OPTION: check OPTION_USE_LIB_E57FORMAT which is a plugin to CloudCompare
		
	- click on "Configure" (this should fail with an error)

	- Set the following CMake variables:
		- Unresolved: the paths to the E57Format libraries (which needs to be compiled first)
		- Xerces: the path to the Include folder and Libraries of Xerces (which needs to be compiled first)

	- click on "Configure" ("Configuring done" message)

- *END IF*

- click on "Generate "("Generating done" message)

- click on "Open Project"


In **MSVC**

- Build "Commands.GenerateEarlyBinding.IFC4X1" (in the folder OpenInfraPlatform/ExpressBindingGenerator/Commands)

- Close MSVC. 


In **CMAKE**:

- click on "Generate"

- click on "Open project"


In **MSVC**

- Build OpenInfraPlatform.IFC4X1 (in the folder OpenInfraPlatform/EarlyBinding)

- Then, build the whole solution: Menu Build > Build solution

There may still be some errors (currently three of them related to wrong type casting), but the software should still load and both point clouds and 3D models should still be visualisable.



