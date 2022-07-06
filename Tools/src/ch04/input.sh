#!/bin/bash
echo I got $# arguments
echo $*
echo Line by line:
echo $@ | xargs -n 1