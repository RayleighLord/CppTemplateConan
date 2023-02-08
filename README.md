# C++ Template Repository

![Linux Build](https://github.com/RayleighLord/CppTemplateConan/workflows/Ubuntu%20CI%20Test/badge.svg)
[![codecov](https://codecov.io/gh/RayleighLord/CppTemplateConan/branch/main/graph/badge.svg)](https://codecov.io/gh/RayleighLord/CppTemplateConan)

Install dependencies and prepare the build directory

```shell
make install
make setup_conan
make prepare_conan
```

- Executable for the app

```shell
cd build
cmake -DCMAKE_BUILD_TYPE=Release ..
cmake --build . --config Release --target main
cd app
./main
```

- Perform all the unit tests

```shell
cd build
cmake -DCMAKE_BUILD_TYPE=Debug ..
cmake --build . --config Debug --target unit_tests
cd test
./unit_tests
```
