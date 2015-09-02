#!/bin/sh
ldapsearch -Q -LLL "uid=*bon*" sn | grep sn | wc -l | sed 's/ //g'
