compile: $(wildcard src/*.cpp)
	emcc -O2 $? -I include -Wextra -o docs/index.html -s USE_SDL=2 --shell-file html/shell.html
emcc:
	cd emsdk && ./emsdk install latest && ./emsdk activate latest && source ./emsdk_env.sh && cd ..