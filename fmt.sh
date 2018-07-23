#!/bin/bash

find -name '*.re' -exec refmt {} --in-place \;
