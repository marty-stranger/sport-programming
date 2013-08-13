#!/bin/sh

sed "1d;1,$ s/ / -> /g;$ ! s/$/,/g" i | sed "1i GraphPlot[{"
echo "}, VertexLabeling -> True]"


