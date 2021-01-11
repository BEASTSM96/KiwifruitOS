#!/bin/bash

true_path="$(dirname "$(realpath "$0")")"
export PREFIX="../CrossCompiler/Tools32"
export TARGET=i386-elf-gcc
export PATH="$PREFIX/bin:$PATH"