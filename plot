  plot \
 "testjohnson" using 1:2 title 'Données non-corrélées n^2', \
 "testjohnson" using 1:3 title 'Données non-corrélées n log n', \
 "testjohnson" using 1:4 title 'Corrélation sur les durées d exécution n^2', \
 "testjohnson" using 1:5 title 'Corrélation sur les durées d exécution n log n', \
 "testjohnson" using 1:6 title 'Corrélation sur les machines n^2', \
 "testjohnson" using 1:7 title 'Corrélation sur les machines n log n'
 
 plot \
 "borne1" using 1:2 title 'Données non-corrélées borne b1', \
 "borne1" using 1:3 title 'Corrélation sur les durées d exécution borne b1', \
 "borne1" using 1:4 title 'Corrélation sur les machines borne b1', \
 "class1born2" using 1:2 title 'Données non-corrélées borne bMax', \
 "class1born2" using 1:3 title 'Corrélation sur les durées d exécution borne bMax', \
 "class1born2" using 1:4 title 'Corrélation sur les machines borne bMax'
 
  plot \
 "borne1" using 1:5 title 'Données non-corrélées borne b1', \
 "borne1" using 1:6 title 'Corrélation sur les durées d exécution borne b1', \
 "borne1" using 1:7 title 'Corrélation sur les machines borne b1', \
 "class1born2" using 1:5 title 'Données non-corrélées borne bMax', \
 "class1born2" using 1:6 title 'Corrélation sur les durées d exécution borne bMax', \
 "class1born2" using 1:7 title 'Corrélation sur les machines borne bMax'
