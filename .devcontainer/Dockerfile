# See here for image contents: https://github.com/microsoft/vscode-dev-containers/tree/v0.134.0/containers/cpp/.devcontainer/base.Dockerfile
ARG VARIANT="buster"
FROM mcr.microsoft.com/vscode/devcontainers/cpp:0-${VARIANT}
# C++, Python3, PyPy3の3つの環境想定
RUN apt-get update && export DEBIAN_FRONTEND=noninteractive \
    && apt-get -y install --no-install-recommends \
    python3-pip \
    pypy3 \
    nodejs \
    npm \
    && pip3 install online-judge-tools \
    && npm install -g atcoder-cli \
    && rm -rf /var/lib/apt/lists/* \
    && rm -rf ~/.cache/pip \
    && npm cache clean --force