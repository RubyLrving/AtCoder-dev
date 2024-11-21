#!/bin/bash

cd /workspaces/atcoder_cpp

export $(grep -v '^#' .env | xargs)

./init/login.sh

acc config default-task-choice all
cp -r ./config/. `acc config-dir` 
acc config default-template cpp
