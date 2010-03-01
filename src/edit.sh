#! /bin/bash

#killall emacs
cd $(dirname $0)

#emacsclient -a '' -c $(find -type f)
/usr/bin/emacs $(find -type f)
