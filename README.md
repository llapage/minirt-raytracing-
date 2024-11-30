[MacOs + External library(mlx)]

**Overview**

Minirt is a simple ray tracing renderer developed in C using MiniLibX for macOS. It renders 3D scenes described in .rt files by simulating the physics of light interacting with geometric objects such as planes, spheres, and cylinders.

**Features**

Geometric Objects:

Supports rendering of planes, spheres, and cylinders.
Correct handling of object intersections and internal rendering (inside-out behavior).
Transformations:
Objects, lights, and cameras can be translated and rotated (except spheres and lights which cannot be rotated).
Resize support: Adjust diameter for spheres and width/height for cylinders.
Lighting:

Ambient and diffuse lighting are implemented.
Hard shadows cast by objects.
Support for adjustable spot brightness.
Objects are never completely in the dark due to ambient lighting.
Window & Rendering:

Renders the scene in a fluid window using MiniLibX.
The window content scales correctly when resized.
ESC or clicking the red cross will cleanly exit the program.
Scene File (.rt) Specification

The program accepts a scene description file as input. The .rt file must adhere to the following rules:

Each element (camera, light, object) can be separated by one or more line breaks.
Each element’s properties can be separated by one or more spaces.
Elements can be declared in any order.
Elements with capital letters (e.g., Camera, Light) can only be defined once.


Examples scenes are found in scenes_rt repo.
