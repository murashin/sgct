#!/bin/sh
cd "$(dirname "$0")"
./domeImageViewer_opengl3 -config two_nodes_stereo_dummy.xml -local 0 &
./domeImageViewer_opengl3 -config two_nodes_stereo_dummy.xml -local 1 --slave &
