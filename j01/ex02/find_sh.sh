#!/bin/sh
find . \( -name "*.sh" \) -print | sed 's/\.sh//g' | rev | cut -d"/" -f 1 | rev 
