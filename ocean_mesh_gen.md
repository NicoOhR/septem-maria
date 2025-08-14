The near player/coastline of the ocean will require waves to break/overturn

Methods which only consider the surface of the ocean will not lead to this
result and therefore a particle based method is necessary. To this end,
*near* the player the ocean will be simulated using Smoothed Particle
Hydrodynamics. 

However, since SPH is mesh less, to actually render the resulting water,
Screen Space Fluid Rendering is typically used. It involves rendering each
particle as an orb, then smoothing it over with a blur or other filter.

This is likely the most performant method that still allows for the water
simulation that I am shooting for.

The boat likely has to be seperate from the actual simulation, that is,
the simulation effects the boat but the boat is invisable to the
simulation. 

Another approach which I like a little more is reconstructing the fluid
surface from the particle simulation a la this paper
https://cg.informatik.uni-freiburg.de/publications/2012_CGF_surfaceReconstructionSPH.pdf
Which then allows me to use Raylib land meshing and modeling


If instead the ocean surface alone is simulated via a discrete height map,
Tessedorf style, and then meshed/rendered using a simple grid. Then LOD is
added. This simplifies boundry conditions as well

