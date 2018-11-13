# Avada Kedavra 

 This game is a puzzle game. There are some boxes which will shuffle. Player has to choose the right box. And he/she can get score using perfect boxes. After that he or she  has to go to a fight scene. Choosing wrong objects will harm the main character. It's a story based game.


### Prerequisites
. This game has been made using cocos-2d-x.
.[Get started with](https://www.youtube.com/watch?v=c-oGUGBprHI) - Installation and starting
. [Tutorial](http://docs.cocos2d-x.org/cocos2d-x/en/) - cocos2d-x tutorial
. Some one can also see many game examples. Because it is very popular. Many games were made using this.
cocos2d has a really good physics engine in it. That is useful for many games. And there audio engine is also great.

###After HelloWorld
After installing cocos properly. We can open classes folder and add cpp file and header file(if needed). Then drag them to solution explorer of Visual Studio.Then just start coding!!!

## About this game 

 ### Project Module 
 
The code of this project was compartmentalized into different classes. Every scene was coded independently.That is each scene doesn’t depend on the other scenes.
A detailed description of the project modules is given below:

Main Menu : The main menu was coded in a scene which is defined      by a class. The functions needed to create the main menu was declared in the class. These functions was implemented afterwards in the cpp file outside the init function. However the labels were made in the init function.Bullets were declared individually in the main menu.

Settings Menu :  Settings menu was built in another class than the main menu. The bullets used here are different than the ones used in the main menu. However the process is almost similar to the main menu. But file is used here to renew the score and health bar
. 
Instructions : Instructions was created using label in another class. 

 Game Scene : The main game scene was built using a class other than that of the main menu and settings. The sprites were declared in the class. Required variables were also declared in  the class

Mouse Events : Everything happened due to the click of the mouse is created in function outside the init function which was declared in the class. The conditions for animation after clicking the boxes were also carried out in this function.
 
Animation : Animation for empty boxes were implemented by a function created outside the init function.It was called wherever it was  needed afterwards. However the other animations were done in  the init function.

Score : Score was mainly count in the mouse events function. A text file was used to store the current score for further progress of the game.

Bullets : Bullets were used here mainly to progress forward or go backward in the game.  

Fight Scenes : Two different kind of fight scenes was created.One was for the main character to attack the enemy. The other was simply the reverse.Two different classes were used to implement these two fight scenes.
Characters : The two characters were created using structure. Sprites were used for the characters.Information about the characters were declared in the structure.
Health Bar : Health bar was created in the init function.Text file was used to  change and save the condition of the health bar.

Spell : Spell was created and animated in the init function of the mother function in the class.      
                 
Thus the whole code was divided into different classes and then implemented.                 

###Limitations

During the course of building the project ,we have gone through a lot of problems. As such, there are some limitations we couldn’t solve within the designated time. For example :
Highscore list hasn’t been added.


## Project members

Nafisa Naznin 
Khondker Bin Yamin 


## Acknowledgments

* Inspiration
 We two are always  big fans of Harry Potter. So, we take this marvelous book as a game story platform. Though I know this game is up to no good. 
