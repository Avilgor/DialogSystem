# Dialog System


## Introduction

Here you will found some usefull information about what is a dialog system, examples of it, why it is used and how to do one. 
We will see different types of dialog systems, examples of games that have one and a little step by step tutorial to do one basic system.

## Dialog System?

The dialog system is that part of the game or app which control the dialog interaction between the user and/or IA interactions. In some games 
we can interact with it, making decisions which can or not inflict in the story or future actions, and in other cases the player can only see
how the AI interacts with itself. Not all decisions that we can make are important, there can be dialogs systems which don't save the 
decisions you made, it is all about the game you want to do and the importance you want to give to making decisions. 
There are two different types of dialog system, branching and not. Not having branches means that the player have no control over what is being
said, he/she only reads the information but can't make decisions to change it. In the opposite, we have the branching dialog system, which takes
into account what the player decides to show one text or another, we can even make it to remember previous decisions for future events in game.

Non branching system:

![](https://github.com/Avilgor/DialogSystem/blob/master/docs/noBranch.jpg?raw=true)

Branching system:

![](https://github.com/Avilgor/DialogSystem/blob/master/docs/branch.png?raw=true)

To do a GOOD branching dialog system, there are one thing that has to be done at first, planing a dialog tree. A dialog tree is where all 
the decisions are schedule, setting the possible answers and next questions to ask or answers to give.

![](https://github.com/Avilgor/DialogSystem/blob/master/docs/tree.png?raw=true)

That image is a clear example of a dialog tree. It is a simple dialog only taken into account, but for a larger one the basis is the same, 
you only have to include more options and further questions/answers.

Some branching systems use an idea of Hub-Dialog, which means that the player starts with multiple options to choose that each one leads to a 
different dilogue with the same NPC, and once it is finished, you return to the Hub, where you can choose another oprion and/or re-choose the
same one. This system can be found in games like "Divinity Original Sin".

![](https://github.com/Avilgor/DialogSystem/blob/master/docs/hub.jpg?raw=true)

## Why we use it?

In a RTS game it can be used to introduce the story or make gameplay decisions, like events, alliances... 

![](https://github.com/Avilgor/DialogSystem/blob/master/docs/stellaris.jpg?raw=true)

In the game "Stellaris", sometimes you have to make decisions that involve other races in the univers. Those decisions are the base for the alliance system the game has.

Other games that also use a dialog system are Skyrim and Fallout, which are good known in the industry for the amount of dialogues and 
decisions they have. Sometimes, one of the most criticized parts in a videogame is the dialog system, being answers not clear enough or not having enough impact in the story.

![](https://github.com/Avilgor/DialogSystem/blob/master/docs/skyrim.jpeg?raw=true)

![](https://github.com/Avilgor/DialogSystem/blob/master/docs/fallout.jpeg?raw=true)

In both cases is well done, having multiple options that we can see fully the whole text or almost it. Which allow us to decide correctly what to choose knowing what it means.

![](https://github.com/Avilgor/DialogSystem/blob/master/docs/fallout4.jpg?raw=true)

That last one was one of the reasons that people complain about "Fallout 4", the dialog system is awful compared whith the previous ones. The answers are not clear enough, which is a problem bacause players expect a certain result when taking a decision, and if it is not what he/she expected he/she can be dissapointed. 

Another dialog system is the one used in "Sims" games. Which is different from the others because it doesn't use words, only for the player to choose what to do, but to know if out decision was succesful we have to look at the images that explain what are they talking about or how they feel.

![](https://github.com/Avilgor/DialogSystem/blob/master/docs/sims.png?raw=true)

Knowing that there is not only one way to do it, it is up to you to decide how you want it to be.

## How to do one?

Now we are gonna see a step by step tutorial to do a dialog system based on text and multiple answers.
To start with it tou can download this [handout](https://github.com/Avilgor/DialogSystem/releases/tag/1.0.1) with the base code to start.

# TODO 1:

- First of all you have to create a dialog tree with your text lines and posible options to choose and answers, if you are not inspired, you can use the one I used created 
 for this tutorial, it is inside the handout folder.

# TODO 2:

- Now is time to declare a function to create the UI for the dialog and the variables for the UI
	- For this we will need 1 image for the retail and 4 texts, one for the information and the other 3 for each answer
	
![](https://github.com/Avilgor/DialogSystem/blob/master/ToDo/todo2_1.png?raw=true)
![](https://github.com/Avilgor/DialogSystem/blob/master/ToDo/todo2.png?raw=true)

# TODO 3:

- It's time to define crate UI function and call it at the module start
	- Here we will used the texture for the retail image and start all the text lines empty
	
![](https://github.com/Avilgor/DialogSystem/blob/master/ToDo/todo3.png?raw=true)
![](https://github.com/Avilgor/DialogSystem/blob/master/ToDo/todo3_1.png?raw=true)

# TODO 4:

- Declare a new function to update the dialog UI and variables needed to control the dialog
	- We need a counter for dialog steps
	- A boolean to activate or deactivate the decisions read
	- Enum with the diferent number of decisions

![](https://github.com/Avilgor/DialogSystem/blob/master/ToDo/todo4.png?raw=true)
![](https://github.com/Avilgor/DialogSystem/blob/master/ToDo/todo4_1.png?raw=true)
![](https://github.com/Avilgor/DialogSystem/blob/master/ToDo/todo4_2.png?raw=true)

# TODO 5:

- Now is when it starts to get more difficult :)
- Set dialog control variables in start function before anything
- In update we will check if a question is up, then check if our keys for options are pressed
	-If one of them is pressed, call update UI function with the enum of this option as parameter
-If there is nothing to choose, check if the key to advance in dialog steps is pressed	
	- If it is, call update UI function
	
![](https://github.com/Avilgor/DialogSystem/blob/master/ToDo/todo5_1.png?raw=true)
![](https://github.com/Avilgor/DialogSystem/blob/master/ToDo/todo5.png?raw=true)


# TODO 6:

- The last and most difficult part
- Is time for the update UI, here we will check the dialog step and if needed the option chosen
- For this we need a switch for the dialog step variable
	- Before anything we do another switch in the dialog step/s where we have to change our text depending in the decision made
- After this, we set our info text to the corresponding text in our dialog tree
- Now if it is a question where the player have to choose, we set the text needed for any number of options we have
- After this call the update text method in our text elements
- And if there is a option to choose, set the boolean for the option true
- If the option was in the previous step, clear all the options text and set the boolean to false
- Finally we call the function in the start method

![](https://github.com/Avilgor/DialogSystem/blob/master/ToDo/todo6.png?raw=true)
![](https://github.com/Avilgor/DialogSystem/blob/master/ToDo/todo6_1.png?raw=true)

If you did it all correct, your dialog should look like this by now: 

![](https://github.com/Avilgor/DialogSystem/blob/master/ToDo/start.png?raw=true)
![](https://github.com/Avilgor/DialogSystem/blob/master/ToDo/choose.png?raw=true)
![](https://github.com/Avilgor/DialogSystem/blob/master/ToDo/optionB.png?raw=true)

# Optional work:

- Clear screen if dialog ended
	- Check if the dialog ended and set true the variable "to_delete" in all the UI elements
- Only check keyboard if dialog is happening 
	- Check if dialog has ended, if not read inputs


That's the end of the tutorial. :D

If you couldn't make it to work, I provide you the solution code [here](https://github.com/Avilgor/DialogSystem/releases/tag/1.0) where all the previous steps are already done.

##Further improvements
- If that is not enough for you, you can try to implement this:
	- Save all dialog lines in string vector
	- Set text from vector
	- Create your own textures for retail
	- Change options to be buttons
	- Read text lines from xml and store them in a vector
		- That allows you to use multiple languages ;)
- Save options chosen for further use



## References

- [https://www.gamasutra.com/view/feature/132116/defining_dialogue_systems.php](https://www.gamasutra.com/view/feature/132116/defining_dialogue_systems.php)
- [https://www.gamasutra.com/blogs/BobbyLockhart/20171107/309121/5_Radical_Ideas_for_Dialogue_Systems.php](https://www.gamasutra.com/blogs/BobbyLockhart/20171107/309121/5_Radical_Ideas_for_Dialogue_Systems.php)
- [http://www.digra.org/wp-content/uploads/digital-library/09287.59480.pdf](http://www.digra.org/wp-content/uploads/digital-library/09287.59480.pdf)
- [https://en.wikipedia.org/wiki/Dialogue_tree](https://en.wikipedia.org/wiki/Dialogue_tree)
- [https://medium.com/@kionay/rpg-dialogue-systems-1de601383a94](https://medium.com/@kionay/rpg-dialogue-systems-1de601383a94)
