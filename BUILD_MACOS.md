# Build and Package OpenLIFU

This document summarizes how to build and package OpenLIFU on macOS.

OpenLIFU is a custom Slicer application. Reading the [3D Slicer Developer Documentation](https://slicer.readthedocs.io/en/latest/developer_guide/index.html) may help answer additional questions.

The initial source files were created using [KitwareMedical/SlicerCustomAppTemplate](https://github.com/KitwareMedical/SlicerCustomAppTemplate).

## Clone

```sh
git clone https://github.com/OpenwaterHealth/OpenLIFU-app.git
```

## Prerequisites

1. Install the latest Xcode SDKs:
    ```sh
    xcode-select --install
    ```

2. Install Homebrew and Qt5:  
    - **Apple Silicon:** Install `x86_64` Homebrew and Qt5. You can install "x86_64 Homebrew" if you run the `x86_64` shell with Rosetta 2. **Make sure you remain in the x86_64 shell for the rest of the build**:
      ```sh
      arch -x86_64 /bin/bash -c "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/HEAD/install.sh)"
      exec /usr/bin/arch -x86_64 /bin/bash --norc --noprofile
      export PATH="/usr/local/bin:$PATH"
      brew install qt5
      ```
    - **Intel:** Install Homebrew and Qt5:
      ```sh
      /bin/bash -c "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/HEAD/install.sh)"
      export PATH="/usr/local/bin:$PATH"
      brew install qt5
      ```    ```

## Build

Note: The build process can take hours.

```sh
mkdir OpenLIFU-superbuild
cd OpenLIFU-superbuild
cmake \
-DQt5_DIR:PATH=/usr/local/opt/qt@5/lib/cmake/Qt5 \
-DCMAKE_OSX_ARCHITECTURES:STRING=x86_64 \
-DCMAKE_OSX_DEPLOYMENT_TARGET:STRING=13.0 \
-DCMAKE_BUILD_TYPE:STRING=Release \
-DSlicer_USE_SYSTEM_QT:BOOL=ON \
-DSlicer_USE_SimpleITK:BOOL=OFF \
-B . \
-S ../OpenLIFU-app

NUM_CORES=$(sysctl -n hw.ncpu)
make -j${NUM_CORES}
```

Once the application is built, there will be an "inner build" inside the superbuild folder, located at `OpenLIFU-superbuild/Slicer-build`. The application executable is contained in this inner build folder.

## Package

Enter the inner build folder and then make the package:

```sh
cd Slicer-build/
make package -j${NUM_CORES}
```
