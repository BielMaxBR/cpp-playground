compile: $(wildcard src/*.cpp)
	emcc $? -I include -Wextra -o build/index.html -s USE_SDL=2 