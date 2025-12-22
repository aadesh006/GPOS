#!/bin/bash

# 1. Ensure the cross-compiler is found
export PATH="$HOME/opt/cross/bin:$PATH"

# 2. Clean up old files
make clean

# 3. Build the OS
make all