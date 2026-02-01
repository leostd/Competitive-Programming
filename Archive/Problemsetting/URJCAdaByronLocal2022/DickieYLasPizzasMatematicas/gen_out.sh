#!/usr/bin/env bash

for f in ./testcases/*.in; do
  ./main < ${f} > ${f%.in}.ans
done