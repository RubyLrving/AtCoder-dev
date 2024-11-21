# See here for image contents: https://github.com/microsoft/vscode-dev-containers/tree/v0.134.0/containers/cpp/.devcontainer/base.Dockerfile
ARG VARIANT="debian"
FROM mcr.microsoft.com/vscode/devcontainers/cpp:0-${VARIANT}
# インタラクティブモードにならないようにする
ENV DEBIAN_FRONTEND=noninteractive

# 必要なパッケージのインストール
RUN apt-get update && \
    apt-get -y install --no-install-recommends \
    git gdb \
    # python pypy3
    python3-numpy \ 
    python3-pip pypy3 nodejs npm locales-all expect build-essential && \
    rm -rf /var/lib/apt/lists/*

# Pipのアップグレード
RUN pip3 install --upgrade pip

# 必要なツールのインストール
# online-judge-tools atcoder-cli atcoderでも使えるpythonのライブラリ
RUN pip3 install online-judge-tools && \ 
    npm install -g atcoder-cli --unsafe-perm && \
    rm -rf ~/.cache/pip && \
    npm cache clean --force

ENV LANG ja_JP.UTF-8
ENV LANGUAGE ja_JP:ja
ENV LC_ALL ja_JP.UTF-8
ENV TZ=Asia/Tokyo

# C++でAtCoder Library(ACL)を使えるようにする
RUN git clone https://github.com/atcoder/ac-library.git /lib/ac-library
ENV CPLUS_INCLUDE_PATH /lib/ac-library