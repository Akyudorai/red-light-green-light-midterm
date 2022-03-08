# red-light-green-light-midterm

<!-- SUMMARY -->
## Summary


<p align="right">(<a href="#top">back to top</a>)</p>

<!-- TASKLIST -->
## Tasklist

- [ ] Gameplay Loop (F)      
- [ ] Character Controls (F)
- [ ] Colliders (F)
- [ ] Win Screen (F)
- [ ] Lose Screen (F)
- [ ] Lighting Effects (L)
- [ ] View Distance Shader (Fog) (S)
- [ ] Primitives (T)
- [ ] Map (T)
- [ ] Map Textures (T)

<p align="right">(<a href="#top">back to top</a>)</p>

<!-- FUNCTIONALITY -->
## Functionality

#### Concepts
The player will move in one direction along a hallway towards the exit.  On random time intervals, the lights in the hallway will turn red indicating that the player must stop.  If the player is caught moving while the lights are red, they will lose the game.  After a brief moment, red lights will turn back to normal indicating the player can continue moving. 

#### How to Implement
We can technically create all the functionality in a single class script, but let's separate it into a character control script and a game manager script.  

The game manager will have an update loop that runs a randomly generated timer during play.  When the timer hits zero, we'll do three things: firstly, we'll change our lights from whatever color they were to red.  We can hard code what color lights they change between or record what light they were before the red light for when we switch back.  Secondly, we'll set a boolean true that will be used to detect if the player is moving or not during the red light.  Lastly, we'll set a new timer which, when completed, will return everything back to normal, reverting the light colors back and setting the boolean to be false before randomly generating our next red light timer.

For the character controller, we'll also have an update function that is being called during play to detect any input.  In the update, we will track to see if the player is pressing a specified button down, and if they are, we'll move the parent/camera in a direction towards the end of the room.  We will use an if conditional to check if the game manager's red light boolean is true or not, and if it is we'll end the game with a result of "LOSS".  If we make this script a component class, we can attach it to any game object easily and just modify the game object's position.  This will also work well with the camera being a component itself, so easy first person controls.

We'll also need a trigger collider at the end of the hallway to detect when the player reaches the end in order to call the win function.  In turn, we need to apply a rigidbody to our character (or maybe just add a collider to it) in order to be detected by the trigger collider.  If using a rigidbody, we also need to create at least one collider for the floor.

Finally, we'll need to create an indicator for winning the game and for losing the game.  This can be represented by a simple popup image or text.   

<p align="right">(<a href="#top">back to top</a>)</p>

<!-- TEXTURES -->
## Textures + Models

#### Concepts
For textures and models, we can use simple primitives to represent objects in our scene.  Because we're using a first person control scheme, we wont need to use a model for the character.  Realistically, we only need one model to complete this game, and that is the "map" or "level", which will be a linear hallway with an exit door at the end. All our textures will go into this model using simple UV unwrapping thanks to the cubic shape of the hallway.  If we have time, we can create an enemy using a primitive shape or custom model that stands at the end of the hall, only rendered when there is red light.

#### How to Implement
The model itself will be a modified cube shape with inversed normals so we can see into it from outside, but not outside from inside.  Another way to think of it is that the player will be trapped inside the box.  Once the box is made with inverse normals, we can use smart UV unwrap to auto generate our UVs.  This works well because of the simple shape. Because of how simple this should be to set up, it should allow for enough time to texture the inside of the box with whatever style texture we want.  Texture painting will likely be the easiest, but if you're more comfortable exporting to photoshop, then that works too.

As for the enemy (if we get that far) we can just toggle on/off the renderable component of the game object depending on what boolean state the game manager has set for the red light.

<p align="right">(<a href="#top">back to top</a>)</p>

<!-- LIGHTING -->
## Lighting

#### Concepts
The lights in our scene will have two "states".  The first should be an "green light state", where they're simply dark and eerie lights with low radius but enough to light up the hallway around their sources.  The second state should be a "red light state" where all the lights glow a brighter red, illuminating the hallway.  If we have time, we should experiment with creative use of these light sources.

#### How to Implement
We'll need to position lights around the level and adjust their luminosity accordingly to create a dark hallway vibe.  Once we found what we want, we can record the values and then adjust to get the lighting feel we want for a red light state.  For additional effects, we can implement a pulsing light effect where the intensity or radius of the light expands and retracts over a period of time, or create a rotating light reminiscent of a something similar to police lights.  

<p align="right">(<a href="#top">back to top</a>)</p>

<!-- SHADERS -->
## Shaders

#### Concepts

#### How to Implement

<p align="right">(<a href="#top">back to top</a>)</p>
