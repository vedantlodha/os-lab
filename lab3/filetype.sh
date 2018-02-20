#!/bin/bash
s=file "$1" | 'cut --delimiter=: -f 2' 
echo "$s"
