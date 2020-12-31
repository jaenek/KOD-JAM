.PHONY: all clean configure build configure-web build-web

all: build

clean:
	rm -rf build

configure:
	mkdir -pv build
	cd build && cmake -DCMAKE_EXPORT_COMPILE_COMMANDS=1 ..
	cp build/compile_commands.json src/

build:
	cd build && make

configure-web:
	emcmake cmake -S . -B webbuild -DEMSCRIPTEN=1

build-web:
	cd webbuild && make && mv kod-jam.html index.html
