# Licensing

This document states which licence covers which parts of this repository, and
explains what that means. [What applies where](#what-applies-where) is the operative
section — it is how these files are made available. The commentary around it is for
convenience; the binding terms are the full texts in [`LICENSES/`](LICENSES/).

Where a project holds both software and hardware design files, they are licensed
separately by component — not dual-licensed, since you do not get to choose which of
the two covers a given file:

- **Software** — GNU General Public License v3.0 or later (`GPL-3.0-or-later`) —
  [`LICENSES/GPL-3.0-or-later.txt`](LICENSES/GPL-3.0-or-later.txt)
- **Hardware** — CERN Open Hardware Licence Version 2, Strongly Reciprocal
  (`CERN-OHL-S-2.0`) — [`LICENSES/CERN-OHL-S-2.0.txt`](LICENSES/CERN-OHL-S-2.0.txt)

The root [`LICENSE`](LICENSE) is a copy of the GPL text. GitHub reports only one
licence per repository and reads that file, so this document is where the full
picture lives.

## What applies where

| Path | Licence |
| --- | --- |
| `src/` — firmware | `GPL-3.0-or-later` |
| `electrical/` — schematics, PCB layouts, gerbers, fabrication outputs | `CERN-OHL-S-2.0` |
| `scad/` — parametric CAD source | `GPL-3.0-or-later` **and** `CERN-OHL-S-2.0` |
| `scad/` — geometry (STL, STEP, 3MF), drawings and bill of materials generated from that source | `CERN-OHL-S-2.0` |
| `README.md` and the READMEs in each directory | see below |

Parametric CAD source is granted under both licences so that a licensee who Makes a
Product from the geometry can satisfy CERN-OHL-S-2.0 §4, which requires the Complete
Source — the design in its preferred form for modification, meaning the source, not
the mesh.

**If the parametric source includes a GPL-licensed library** — NopSCADlib and
similar — replace both `cad/` rows with a single `GPL-3.0-or-later` covering source,
geometry, drawings and BOM alike, and record the library under
[Third-party components](#third-party-components). GPL-3.0 is not a Compatible
Licence under CERN-OHL-S-2.0 §1.2, so the whole-work licensing its §3.3(d) requires
cannot be granted over source entangled with such a library. See the organization
[licensing policy](https://github.com/uwo-fast/.github/blob/main/LICENSING.md).

**Documentation.** Documentation specific to software is licensed
`GPL-3.0-or-later`, and documentation specific to hardware `CERN-OHL-S-2.0`. A
document covering both — a build guide carrying a bill of materials alongside code
listings — and documentation specific to neither are licensed under both, at your
option.

## Third-party components

Anything vendored or included keeps its own licence, unaffected by this document.

_None._ The firmware includes the Arduino libraries `LiquidCrystal_I2C` and
`PID_v1` at build time; they are installed separately, not vendored here.

## Contributions

"Contribution" means any work of authorship intentionally submitted for inclusion
in this project — a pull request, patch, commit, issue, or other communication —
excluding anything conspicuously marked "Not a Contribution".

Unless you state otherwise, contributions you submit are licensed under whichever
of the licences above covers the files they touch, with no additional terms. By
submitting a contribution you represent that you have the right to license it on
those terms.

## Patents

Both GPL-3.0 (section 11) and CERN-OHL-S-2.0 (section 7) contain express patent
provisions. Review them before using, modifying, or distributing this project.

## Disclaimer of warranty and liability

A summary of terms in the licences themselves — GPL-3.0 sections 15–17 and
CERN-OHL-S-2.0 section 6.

THIS PROJECT, INCLUDING ALL SOFTWARE AND HARDWARE DESIGNS, IS PROVIDED "AS IS"
WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE
WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE, AND
NON-INFRINGEMENT.

TO THE EXTENT PERMITTED BY APPLICABLE LAW, IN NO EVENT SHALL THE AUTHORS,
CONTRIBUTORS, OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES, OR OTHER
LIABILITY ARISING FROM, OUT OF, OR IN CONNECTION WITH THIS PROJECT.

### Additional disclaimer

The following is not a summary of either licence. It is an additional disclaimer of
the kind GPL-3.0 section 7(a) permits, offered alongside them:

HARDWARE DESIGNS HERE HAVE NOT BEEN INDEPENDENTLY VERIFIED OR CERTIFIED FOR SAFETY
OR REGULATORY COMPLIANCE. ANY PHYSICAL PRODUCT MANUFACTURED FROM THEM IS PRODUCED
ENTIRELY AT YOUR OWN RISK. TO THE EXTENT PERMITTED BY APPLICABLE LAW, THE AUTHORS
AND CONTRIBUTORS ARE NOT RESPONSIBLE FOR ANY PERSONAL INJURY, PROPERTY DAMAGE, OR
OTHER HARM RESULTING FROM THE USE OR MANUFACTURE OF PRODUCTS BASED ON THEM.

## Trademarks

Neither licence grants trademark rights. This project does not grant permission to
use the names, trademarks, or logos of the FAST research group or of the project's
contributors, except as needed to describe the project's origin.

## Precedence

Where the commentary in this document and the full licence texts conflict, the full
texts prevail. The scope table above is not commentary — it is the statement of
which files are made available under which terms.
