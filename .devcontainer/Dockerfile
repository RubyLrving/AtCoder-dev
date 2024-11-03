# See here for image contents: https://github.com/microsoft/vscode-dev-containers/tree/v0.134.0/containers/cpp/.devcontainer/base.Dockerfile
ARG VARIANT="buster"
FROM mcr.microsoft.com/vscode/devcontainers/cpp:0-${VARIANT}
# インタラクティブモードにならないようにする
ENV DEBIAN_FRONTEND=noninteractive

# 必要なパッケージのインストール
RUN apt-get update && apt-get -y install --no-install-recommends git \
    python3-pip pypy3 nodejs npm build-essential gdb && \
    rm -rf /var/lib/apt/lists/*

# Pipのアップグレード
RUN pip3 install --upgrade pip

# 必要なツールのインストール
RUN pip3 install online-judge-tools && \
    npm install -g atcoder-cli --unsafe-perm && \
    rm -rf ~/.cache/pip && \
    npm cache clean --force

# C++でAtCoder Library(ACL)を使えるようにする
RUN git clone https://github.com/atcoder/ac-library.git /lib/ac-library
ENV CPLUS_INCLUDE_PATH /lib/ac-library