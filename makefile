compile: $(wildcard src/*.cpp)
	emcc -O2 $? -I include -Wextra -o build/index.html -s USE_SDL=2 --shell-file html/shell.html