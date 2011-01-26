#! /bin/bash

VERSION=$( sed -n '1s~[^(]*(\([^-]*\).*~\1~p' openscenegraph/debian/changelog )
DIRNAME=openscenegraph-$VERSION

cp -r openscenegraph $DIRNAME

tar cvzf openscenegraph_$VERSION.orig.tar.gz $DIRNAME --exclude=$DIRNAME/debian

rm -rf $DIRNAME