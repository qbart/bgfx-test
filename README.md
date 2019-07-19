# Environmentica

## Build

```shell
# .bash_profile
export CPP_SDK_HOME=$HOME/dev/cpp/sdk
```

```shell
mkdir -p $HOME/dev/cpp/sdk
cd $HOME/dev/cpp/sdk

git clone git@github.com:glfw/glfw.git
git clone git://github.com/bkaradzic/bx.git
git clone git://github.com/bkaradzic/bimg.git
git clone git://github.com/bkaradzic/bgfx.git
```

```shell
apt install \
    libxcursor-dev \
    libxinerama-dev \
    libx11-dev \
    mesa-common-dev \
    libglu1-mesa-dev \
    libxrandr-dev \
    libxi-dev
```
