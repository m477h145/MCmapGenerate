#!/bin/bash

screen -S $4 -X stuff "`printf "tp $3 $1 150 $2^M"`"