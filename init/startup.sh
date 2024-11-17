#!/bin/bash

cd /workspaces/atcoder_cpp

./init/login.sh

acc config default-task-choice all
cp -r ./config/. `acc config-dir` 
acc config default-template cpp
