# OpenSCAD Models

This is where the OpenSCAD models will go.

## Planning

The design will approximately look like:

- assembly.scad
  - Main assembly of the components and their input parameters
- enclosure.scad
  - Should use one of the many automatic box generation libraries
- heatingcoil.scad
  - Use spiral method to create adjustable stove coils
- drive.scad
  - Contains the motor and shaft for driving the rotation of the magnet
- magholder.scad
  - the part that will hold the actual magnets to the shaft
- hotstage.scad
  - includes the hotplate, thermal barrier, and its mounting
