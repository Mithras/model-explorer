#!/bin/bash
# Copyright 2024 The AI Edge Model Explorer Authors.
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#     http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.
# ==============================================================================

cd package
pip install torch torchvision --index-url https://download.pytorch.org/whl/cpu
pip install -e .


# pushd /workspace/src/server
# source venv/bin/activate
# cd package

# rm -rf /workspace/src/server/venv/lib/python3.12/site-packages/torch
# pip install torch==2.5.1 --index-url https://download.pytorch.org/whl/cpu --extra-index-url https://pypi.python.org/simple
# pip install torch==2.6.0 --index-url https://download.pytorch.org/whl/cpu --extra-index-url https://pypi.python.org/simple


# pip install mkl-static mkl-include
# curl -SLO https://repo.anaconda.com/miniconda/Miniconda3-latest-Linux-x86_64.sh
# bash Miniconda3-latest-Linux-x86_64.sh
# conda install cmake ninja
# pip install git+https://github.com/pytorch/pytorch.git@c17a07ade34074ffdda36a1412a58f0a6cdcfc14

# git clone https://github.com/pytorch/pytorch.git
# cd pytorch
# git checkout 97d4d3c40ae1ccfbb87b14ea45150656ede4f4de
# cp -r ~/pytorch/torch/export/* /workspace/src/server/venv/lib/python3.12/site-packages/torch/export/
# cp -r ~/pytorch/torch/_export/* /workspace/src/server/venv/lib/python3.12/site-packages/torch/_export/
# cp -r ~/pytorch/torch/fx/* /workspace/src/server/venv/lib/python3.12/site-packages/torch/fx/
# cp -r ~/pytorch/torch/* /workspace/src/server/venv/lib/python3.12/site-packages/torch/

