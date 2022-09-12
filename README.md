C++/SFML

A moon rotates around its planet. Gravity simulation is implemented, acceleration is proportionate to 1/d^2.

Planet is movable on W/S.

Two classes are created. Moon and planet. Gravity calculations are made in the Moon object with the planet passed in.
Objects getting out of frame is resolved by connecting the edges of the window (teleport to the opposite edge).

![screenshot](gravity.png)
