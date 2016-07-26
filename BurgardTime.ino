/*
 * Grant D. McVittie
 * PixelPlatforms
 * 
 * v0.1
 */
#include <Arduboy2.h>
#include <ArduboyTones.h>
#include "sprites.h"
#include "bitmaps.h"

Arduboy2 arduboy;
ArduboyTones sound(arduboy.audio.enabled);
Sprites sprites(arduboy.getBuffer());

/*
 * game variables
 */ 
int FPS = 30;
int CURRENT_LEVEL = 0;
int GAME_STATE = 0;
int GAME_SPEED = 1;

/*
* 0 = intro
* 1 = play
* 2 = win
* 3 = game over
*/

//time
int SECS_PLAYED = 0;

//health
int MAX_HEARTS = 5;
int MAX_LIVES = 3;
int HEARTS = 5;
int LIVES = 3;
int DING_EVERY_X_FRAMES = 120;
int MAX_BOSS_HEALTH = 20;
int BOSS_HEALTH = 20;
int BOSS_MIN_X = 12; //close to player if standing still - increase to make boss easier, lower to make harder, 12 seems fair.

//score
int SCORE = 0;


/*
 * positioning
 */
//player position
int player_x = 32;
int player_y = 41;

//platform position
int platform_x = 128;
int platform_y = 42;
int platform2_x = 128;
int platform2_y = 42;
int platform3_x = 128;
int platform3_y = 42;

//egg position
int egg_x = 300;
int egg_y = 48;

//pickle position
int pickle_x = 190;
int pickle_y = 32;

//hotdog position
int hotdog_x = 190;
int hotdog_y = 32;

//salt position
int salt_x = 190;
int salt_y = 64;

//ladder position
int ladder1_x = 190;
int ladder1_y = 64;
int ladder2_x = 190;
int ladder2_y = 64;
int ladder3_x = 190;
int ladder3_y = 64;

//burger position
int topbun1_x = 190;
int topbun1_y = 64;
int topbun2_x = 190;
int topbun2_y = 64;
int meat1_x = 190;
int meat1_y = 64;
int meat2_x = 190;
int meat2_y = 64;
int btmbun1_x = 190;
int btmbun1_y = 64;
int btmbun2_x = 190;
int btmbun2_y = 64;



/*
 * flags
 */
//sound
bool SOUND_ENABLED = false;
bool SOUND_PLAYED = false;

//player actions
bool WALKING_LEFT = false;
bool WALKING_RIGHT = false;
bool CLIMBING_UP = false;
bool CLIMBING_DOWN = false;
bool IS_HIT = false;
bool PLAYER_HIT = false;

//goodies
bool GOT_SALT = false;

//misc
bool ALLOW_BUTTONS = true;




/*
 * sprites
 */
Sprite player(player_x,player_y,the_player,the_player_mask);


/*
 * ok go
 */
void setup() {
  arduboy.boot();
  arduboy.systemButtons();
  arduboy.audio.begin();
  arduboy.setFrameRate(FPS); 
  arduboy.initRandomSeed();
}

void loop() {
  if (!(arduboy.nextFrame()))
    return;

  //clean slate
  arduboy.clear();
  
  //build level
  buildLevel();
}







/*
 * build level
 */
void buildLevel(){
  arduboy.clear();
  switch( GAME_STATE ){
    //intro screen
    case 0:
      arduboy.drawSlowXYBitmap(0,0,the_intro, 128, 64, WHITE);
      if(SOUND_ENABLED){   
        trace("SOUND ON");
        if(!SOUND_PLAYED){
          soundGood();
          SOUND_PLAYED = true;
        }      
      } else {    
        trace("SOUND OFF");
        SOUND_PLAYED = false;
      }
      break;

    //game play
    case 1:
      //add player
      addPlayer();
      //add goodies and baddies
      addItems();
      //handle collisions
      handleCollisions();
    break;


    //win
    case 2: 

    break;





    //game over
    case 3: 
      //arduboy.drawBitmap(48,8,the_boss1,32,32,WHITE);
      arduboy.setCursor(38,50);
      arduboy.print("TRY AGAIN");
      handleButtons();
      arduboy.display();
      if(!SOUND_PLAYED){
        SOUND_PLAYED = true;
        soundGameOver();
      }
    break;
  }

  arduboy.display();
  //handle button inputs
  handleButtons();
}








/*
 * handle button inputs
 */
void handleButtons(){
  switch( GAME_STATE ){
    //intro screen
    case 0:
      //sound
      if(arduboy.pressed(A_BUTTON) ){
        if(SOUND_ENABLED){
          SOUND_ENABLED = false;
          arduboy.audio.off();
        } else {
          SOUND_ENABLED = true;  
          arduboy.audio.on();    
        }
        delay(50);
      }
      if ( arduboy.pressed(B_BUTTON) ){
        LIVES = 3;
        HEARTS = MAX_HEARTS;
        SCORE = 0;
        SECS_PLAYED = 0;
        GAME_STATE = 1;
        delay(50);  
      }
      break;

      //game play
      case 1:
        
        if(ALLOW_BUTTONS){
          //right
          if( arduboy.pressed(RIGHT_BUTTON)) {
            WALKING_RIGHT = true;
            WALKING_LEFT = false;
            CLIMBING_UP = false;
            CLIMBING_DOWN = false;
          } else {
            WALKING_RIGHT = false;
          }

          //left
          if( arduboy.pressed(LEFT_BUTTON)) {
            WALKING_RIGHT = false;
            WALKING_LEFT = true;
            CLIMBING_UP = false;
            CLIMBING_DOWN = false;
          } else {
            WALKING_LEFT = false;
          }

          //up
          if( arduboy.pressed(UP_BUTTON)) {
            WALKING_RIGHT = false;
            WALKING_LEFT = false;
            CLIMBING_UP = true;
            CLIMBING_DOWN = false;
          } else {
            CLIMBING_UP = false;
          }

          //down
          if( arduboy.pressed(DOWN_BUTTON)) {
            WALKING_RIGHT = false;
            WALKING_LEFT = false;
            CLIMBING_UP = false;
            CLIMBING_DOWN = true;
          } else {
            CLIMBING_DOWN = false;
          }
        }
      break;
  }
}















/*
 * draw the player
 */
void addPlayer(){
  if(GAME_STATE == 1){
    //are we walking right
    if(WALKING_RIGHT){
      if(player_x > 2 && player_x<110){
          player_x++;
          player.frame = 2;
      }
    }    
    
    //are we walking left
    if(WALKING_LEFT){
      if(player_x > 2 && player_x<110){
          player_x--;
          player.frame = 3;
      }
    }
  
    //are we climbing up
    if(CLIMBING_UP){
      if(player_y > 12 && player_y<56){
          player_y--;
          player.frame = 0;
      }
    }

    //are we climbing down
    if(CLIMBING_DOWN){
      if(player_y > 12 && player_y<56){
          player_y++;
          player.frame = 0;
      }
    }

    //are we on a platform?
    if((player_x+16) >= platform1_x && (player_x+16) < (platform1_x+32)){
      if((player_y+16) >= platform1_y && (player_y+16) < (platform1_y+8)){
        player_y = platform1_y-16;        
      }
    }
    if((player_x+16) >= platform2_x && (player_x+16) < (platform2_x+32)){
      if((player_y+16) >= platform2_y && (player_y+16) < (platform2_y+8)){
        player_y = platform2_y-16;        
      }
    }
    if((player_x+16) >= platform3_x && (player_x+16) < (platform3_x+32)){
      if((player_y+16) >= platform3_y && (player_y+16) < (platform3_y+8)){
        player_y = platform2_y-16;        
      }
    }


    //are we on a ladder?
    if((player_x+16) >= ladder1_x && (player_x+16) < (ladder1_x+32)){
      if((player_y+16) >= ladder1_y && (player_y+16) < (ladder1_y+8)){
        player_x = ladder1_x;        
      }
    }
    if((player_x+16) >= ladder2_x && (player_x+16) < (ladder2_x+32)){
      if((player_y+16) >= ladder2_y && (player_y+16) < (ladder2_y+8)){
        player_x = ladder2_x;        
      }
    }
    if((player_x+16) >= ladder3_x && (player_x+16) < (ladder3_x+32)){
      if((player_y+16) >= ladder3_y && (player_y+16) < (ladder3_y+8)){
        player_x = ladder3_x;        
      }
    }
  
    //draw the player
    sprites.draw(player);
  }  
 }









/*
 * goodies and baddies
 */
void addItems(){
  arduboy.initRandomSeed();
  doEgg();
  doPickle();
  doHotdog();

  doSalt();
  doBurgers();
}





/*
 * baddies
 */
 //egg
void doEgg(){
  
  return;
}

 //pickle
void doPickle(){
  
  return;
}

//hotdog
void doHotdog(){
  
  return;
}



/*
 * goodies
 */
//salt
void doSalt(){
  
  return;
}

//burgers
void doBurgers(){
  
  return;
}





//platform
void doPlatform(){
  switch(CURRENT_LEVEL){
    case 1:

    break;
    
    case 2:

    break;

    case 3:

    break;
  }
  
}






/*
 * collisions
 */
void handleCollisions(){
  
  if(GAME_STATE == 1){
    //hit an egg
    if( (player_x + 10) == egg_x){
      if( (player_y+10) >= egg_y){
        delay(100);
        dingHealth();
      }
    }

    //hit a pickle
    if( (player_x + 10) == pickle_x){
      if( (player_y+10) >= pickle_y){
        delay(100);
        dingHealth();
      }
    }

    //hit hotdog
    if( (player_x + 10) == hotdog_x){
      if( (player_y+10) >= hotdog_y){
        delay(100);
        dingHealth();
      }
    }



    //hit salt
    if( (player_x + 10) == salt_x){
      if( (player_y+10) >= salt_y){
        addHealth();
      }
    }

    //hit top bun
    if( (player_x + 10) == topbun1_x){
      if( (topbun1_y+16) >= player_y ){
        
      }
    }
    if( (player_x + 10) == topbun2_x){
      if( (topbun2_y+16) >= player_y ){
        
      }
    }
    if( (player_x + 10) == topbun3_x){
      if( (topbun1_3+16) >= player_y ){
        
      }
    }

    //hit meat
    if( (player_x + 10) == meat1_x){
      if( (meat1_y+16) >= player_y ){
        
      }
    }
    if( (player_x + 10) == meat2_x){
      if( (meat2_y+16) >= player_y ){
        
      }
    }
    if( (player_x + 10) == meat3_x){
      if( (meat3_y+16) >= player_y ){
        
      }
    }

    //hit btm bun
    if( (player_x + 10) == btmbun1_x){
      if( (btmbun1_y+16) >= player_y ){
        
      }
    }
    if( (player_x + 10) == btmbun2_x){
      if( (btmbun2_y+16) >= player_y ){
        
      }
    }
    if( (player_x + 10) == btmbun3_x){
      if( (btmbun3_y+16) >= player_y ){
        
      }
    }

    
  }
}


















/*
 * ding the health
 */
void dingHealth(){
  if(ALLOW_BUTTONS){
    if(HEARTS > 0){
      HEARTS--;
      soundBad();
    }
    if(HEARTS == 0){
      if(LIVES == 0){
        //game over
        GAME_STATE = 3;
      } else {
        LIVES--;
        HEARTS = MAX_HEARTS;
        soundBad();
      }
    }
    PLAYER_HIT = false;
  }
}




/*
 * add to health
 */
void addHealth(){
  if(HEARTS<MAX_HEARTS){
    HEARTS++; 
  } else {
    if(LIVES<MAX_LIVES){
      LIVES++;
    }
  }
  soundGood();
}

void trace(String the_string){
  arduboy.setCursor(0,56);
  arduboy.print(the_string);
}
