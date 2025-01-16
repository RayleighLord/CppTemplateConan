all: prepare

install:
	sudo apt-get install gcc g++ cmake make doxygen graphviz git llvm pkg-config curl zip unzip tar python3-dev clang-format clang-tidy

prepare:
	rm -rf build
	mkdir build

setup_conan:
	pip install --user -U conan
	conan profile detect --force
	conan profile path default

conan_d:
	rm -rf build
	mkdir build
	cd build && conan install .. -s build_type=Debug --output-folder=. --build missing -s compiler.cppstd=17

conan_r:
	rm -rf build
	mkdir build
	cd build && conan install .. -s build_type=Release --output-folder=. --build missing -s compiler.cppstd=17