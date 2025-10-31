#!/bin/bash
ARG=$(shuf -i 1-20 -n 10 | tr '\n' ' ')
./PMergeMe $ARG