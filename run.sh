#!/bin/bash

cd build/gmake2                             && \
  make -j8                                  && \
  echo "<debug> Building in $PWD:"          && \
  ./bin/x86_64/Debug/Editor

