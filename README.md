OpenLIFU by Openwater
================================

An open-source software platform for Low Intensity Focused Ultrasound (LIFU) research and development.

This desktop application provides a graphical user interface for planning and controlling Open-LIFU sonications.

_This project is in active development and may change from version to version without notice,_

## Table of contents

* [Features](#features)
* [Development](#development)

## Features

* Empty list for now!


## Development

* [Contributing](CONTRIBUTING.md)
* [Building on Windows](BUILD_WINDOWS.md)
* [Building on Linux](BUILD_LINUX.md)

### Dependency versions

The versions of Slicer and the SlicerOpenLIFU extensions that this application is based upon are determined by `GIT_TAG`s in the top-level `CMakeLists.txt`.
The version of the python package `openlifu` that is used by this application is determined by the SlicerOpenLIFU version.
So, in order to update the `openlifu` that is used:
- Update `openlifu` in the python requirements file of SlicerOpenLIFU
- Update the SlicerOpenLIFU `GIT_TAG` here in OpenLIFU-app


![OpenLIFU by Open Water Internet, Inc.](Applications/OpenLIFUApp/Resources/Images/LogoFull.png?raw=true)

