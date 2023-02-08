# C++ Template Repository

![Linux Build](https://github.com/RayleighLord/CppTemplate/workflows/Ubuntu%20CI%20Test/badge.svg)
[![codecov](https://codecov.io/gh/RayleighLord/CppTemplate/branch/main/graph/badge.svg)](https://codecov.io/gh/RayleighLord/CppTemplate)

Install dependencies and prepare the build directory

```shell
make install
make prepare
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
cd tests
./unit_tests
```
