# Particle-Animations
This is a project that's programmed int C++. Using the SDL library I was able to move the particles creating diffrent effects
and animations.

To make the movement more interesting, using the trigonometric functions I was able to set a random direction on each pixel
that starts from the center of the screen. Also using the box blur algorithem I was able to apply blur, which made it really
amazing to watch and created something that you could called finished.

The screen width and screen height are set to 1600 and 800 respectivly meaning that if you have another preferred resolution
you can go on screen.h and change the constant variables SCREEN_WIDTH AND SCREEN_HEIGHT to your preferred resolution.

Next up the files are managed in this way:

Swarm.h and Swarm.cpp handle the group of pixels together.
Particle.h and Particle.cpp handle the particles behaviour, so for example their direction or how fast do they move.
Screen.h and Screen.cpp handle creating the window, displaying the particles and updating them. It also contains the blur algorithem.
main.cpp contains the game loop and it's the loop where the program executes and it's the place where all the functions cluster
up and run the program.

To compile and run the project follow these steps:

Using the bash terminal run all the .mk files. So: ./fileName.mk.
After you've done that run the Particle Fire Explosion file. Like this: ./Particle\ Fire\ Explosion.
If the program doesn't execute try changing the name of the Source file folder to src.
If that doesn't work please report it as a problem.

For any code improvments and efficency please report it as an issue. I will gladly take a look at them!

So this is the whole project. I hope you like it and enjoy it.