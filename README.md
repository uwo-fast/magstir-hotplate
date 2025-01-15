# magstir-hotplate

An open-source hardware dseign for building lab-grade magnetic stirrer hot plates.

This is under development - check back later for the result!

## Organization

- Lit revie can be found at: [appropedia.org/Literature_Review_for_Open_Source_Hot_plate_and_Stirrer](https://www.appropedia.org/Literature_Review_for_Open_Source_Hot_plate_and_Stirrer)
- The zotero group for the lit review can be found at: [zotero.org/zotero.org/groups/5827095/magstirhotplate](https://www.zotero.org/groups/5827095/magstirhotplate/library)
- The source files are stored all on GitHub at [github.com/uwo-fast/magstir-hotplate](https://github.com/uwo-fast/magstir-hotplate)

## Goal

Create a generic, low-cost, open-source magnetic stirrer hot plate for laboratory use, capable of reliable and precise stirring and heating for chemical, biological, or other experimental applications.

## Requirements

- Adjustable stirring speed and temperature through intuitive interface
- RPM range: 50–2000 RPM
- Temperature range: 25°C–300°C
- ±1°C temperature accuracy
- Compact and portable design
- Corrosion-resistant and heat-resistant materials
- Modular design for scalability and repairability
- Safety features (overheating protection, spill resistance)
- Build cost target: <$100

## Conceptual Design

- Processor: Budget MCU dev board (maybe QT or XIAO for size) to control system functions
- Motor: DC or stepper motor with encoder feedback, capable of 50–2000 RPM
- Heating Element: 6" surface burner resistive element (oven-top style)
- Temperature Control: Solid-state relay or PID-based controller for precise temperature regulation
- Control Interface: Potentiometer or encoder for setting speed and temperature, LCD/LED display for real-time temperature and RPM feedback
- Power Supply: 110–240V AC mains input, AC/DC converter to supply low-voltage power (e.g., 12V DC)
- Magnetic Stirring: Neodymium magnets mounted on motor shaft for reliable stirring
- Hot Plate: Off-the-shelf stainless steel dish with 6" coil mounted inside and back filled with ceramic insulation
- Thermal Barrier: off-the-shelf stainless steel plate with standoffs connecting up to hot plate and down to housing to isolate sensitive parts
- Component Housing: 3D printed from high-temperature materials (e.g., ASA or PETG)
- Safety Features: Overcurrent protection (fuse), thermal cut-off (software control), spill-resistant (enclosure design and overhang the plate)

## Reference Designs

- HomeBrew DIY Magnetic Stirplate kit
  - v1: https://www.thingiverse.com/thing:307404
  - v2: https://www.thingiverse.com/thing:632714
  - fan remix in scad: https://www.thingiverse.com/thing:2187595

## Outstanding Research Items

- Determining motor torque requirement (motor selection, sigh)
