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

//health
int MAX_HEARTS = 5;
int MAX_LIVES = 3;
int HEARTS = 5;
int LIVES = 3;

//score
int SCORE = 0;


/*
 * positioning
 */
//player position
int player_x = 8;
int player_y = 44;

//platform position
int platform1_y = 12;
int platform2_y = 36;
int platform3_y = 60;

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
//x,y (w is always 16, h is always 24)
int level1ladders [] = { 11,15,  11,39,  57,15,  57,39,  102,15, 102,39 };
int level2ladders [] = { 0,15,  27,39,  86,15,  112,39 };
int level3ladders [] = { 30,39,  57,15,  84,39 };
int level4ladders [] = { 34,39,  86,15 };

//burger position
//x,y (w is always 24, h is always 6)
//top, top,
//meat, meat
//bun, bun
int level1burgers [] = { 
  30,9,   74,9,
  30,33,   74,33,
  30,58,   74,58
};
int level2burgers [] = { 
  52,10,
  52,34,
  52,58,
};
int level3burgers [] = { 
  2,10,     102,10,
  2,34,     102,34,
  2,58,     102,58
};
int level4burgers [] = { 
  4,10,     55,10,     104,10,
  4,34,     55,34,     104,34,
  4,58,     55,58,     104,58
};

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

//burger status
//0 = new, 1 = one item down, 2 = two items down, 3 = complete
int burger1status = 0;
int burger2status = 0;

//misc
bool ALLOW_BUTTONS = true;





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
      arduboy.drawBitmap(0,0,the_title, 128, 64, WHITE);
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
      switch(CURRENT_LEVEL){
        case 1:
          arduboy.drawBitmap(0,0,level1, 128, 64, WHITE);
        break;
        case 2:
          arduboy.drawBitmap(0,0,level2, 128, 64, WHITE);
        break;
        case 3:
          arduboy.drawBitmap(0,0,level3, 128, 64, WHITE);
        break;
        case 4:
          arduboy.drawBitmap(0,0,level4, 128, 64, WHITE);
        break;
      }
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
        CURRENT_LEVEL = 1;
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
      if(player_x > -1 && player_x<112){
        if( onPlatform() ){
          player_x++;
          if(arduboy.everyXFrames(10)){
            soundBad();
          }          
        } else {
          player_y++;
        }      
      }
      arduboy.drawBitmap(player_x,player_y,the_player_f3,16,16,BLACK);
    }    
    
    //are we walking left
    if(WALKING_LEFT){
      if(player_x > 0 && player_x<113){
        if( onPlatform() ){
          player_x--;
          if(arduboy.everyXFrames(10)){
            soundBad();
          }
        } else {
          player_y++;
        }
      }
      arduboy.drawBitmap(player_x,player_y,the_player_f4,16,16,BLACK);
    }
  
    //are we climbing up
    if(CLIMBING_UP){
      if(player_y > -4 && player_y<45){
          if( onLadder() ){
            player_y--;
            if(arduboy.everyXFrames(10)){
              soundBad();
            } 
          }          
      }
      arduboy.drawBitmap(player_x,player_y,the_player_f2,16,16,BLACK);
    }

    //are we climbing down
    if(CLIMBING_DOWN){
      if(player_y > -5 && player_y<44){
        if( onLadder() ){
          player_y++;   
          if(arduboy.everyXFrames(10)){
            soundBad();
          }   
        }               
      }
      arduboy.drawBitmap(player_x,player_y,the_player_f2,16,16,BLACK);
    }

    if(!WALKING_RIGHT && !WALKING_LEFT && !CLIMBING_UP && !CLIMBING_DOWN){
      arduboy.drawBitmap(player_x,player_y,the_player_f1,16,16,BLACK);
    }

    
  }  
 }






/*
 * are we on a ladder
 */
bool onLadder(){
  bool ret = false;
  switch( CURRENT_LEVEL ){
    case 1:{
      for(int i=0; i<11; i=i+2){        
        if( (player_x+12) >= (level1ladders[i]+8) && (player_x+8) <= (level1ladders[i]+16) ){
          ret = true;
        }
      }
    }
  }
  return ret;
}
bool onPlatform(){
  bool ret = false;
  if( (player_y+16) == platform1_y || (player_y+16) == platform2_y || (player_y+16) == platform3_y ){
    ret = true;
  }
  return ret;
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
  switch(CURRENT_LEVEL){
    case 1:
      if(burger1status == 0){
        arduboy.drawBitmap( level1burgers[0],level1burgers[1],the_top_bun,24,6,BLACK);
        arduboy.drawBitmap( level1burgers[2],level1burgers[3],the_top_bun,24,6,BLACK);
        
        arduboy.drawBitmap( level1burgers[4],level1burgers[5],the_meat,24,6,BLACK);
        arduboy.drawBitmap( level1burgers[6],level1burgers[7],the_meat,24,6,BLACK);
        
        arduboy.drawBitmap( level1burgers[8],level1burgers[9],the_bottom_bun,24,6,BLACK);
        arduboy.drawBitmap( level1burgers[10],level1burgers[11],the_bottom_bun,24,6,BLACK);
      }
    break;
  }
  return;
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

    //hit meat
    if( (player_x + 10) == meat1_x){
      if( (meat1_y+16) >= player_y ){
        
      }
    }
    if( (player_x + 10) == meat2_x){
      if( (meat2_y+16) >= player_y ){
        
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
