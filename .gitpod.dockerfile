FROM gitpod/workspace-full
# Install custom tools, runtime, etc.
RUN hg clone https://hg.libsdl.org/SDL SDL \
        cd SDL \
        mkdir build \
        cd build \
        ../configure \
        make \
        sudo make install

# Apply user-specific settings