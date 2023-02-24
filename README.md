Single-threaded Geant4 base code that includes sensitive detector and creates CSV output.

Set up for flat-panel internal geometries (both external and internal -> see Adaptix slides to check these geometries if req'd but they are set out in detectorConstruction.cc)

The CSV consists of 5 columns: -Event Number -X,Y,Z Coord of Photon on Detector -Energy of Photon at the End

TO MAKE: $ cmake -DGeant4_DIR=$G4DIR ../ make -jN (where N is desired no. of cores -- more relevant in MT mode) ./Base to run UI or ./Base MACRO_NAME.mac for batch mode with desired macro file
