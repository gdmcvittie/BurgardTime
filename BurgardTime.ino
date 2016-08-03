
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
int GAME_STATE = 0;
int CURRENT_LEVEL = 0;
int GAME_SPEED = 1;

/*
* 0 = intro
* 1 = play
* 2 = win
* 3 = game over
*/

//health
int MAX_LIVES = 5;
int LIVES = 5;

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
int egg_x = 0;
int egg_y = 14;
int egg_direction = 0; //0 = left, 1 = right

//pickle position
int pickle_x = 112;
int pickle_y = -4;
int pickle_direction = 0; //0 = left, 1 = right

//hotdog position
int hotdog_x = 64;
int hotdog_y = 44;
int hotdog_direction = 0; //0 = left, 1 = right

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
  52,9,
  52,33,
  52,58
};
int level3burgers [] = { 
  2,9,     102,9,
  2,33,     102,33,
  2,58,     102,58
};
int level4burgers [] = { 
  4,9,     55,9,     104,9,
  4,33,     55,33,     104,33,
  4,58,     55,58,     104,58
};
int topbun1_x = 0;
int topbun1_y = 0;
int topbun2_x = 0;
int topbun2_y = 0;
int meat1_x = 0;
int meat1_y = 0;
int meat2_x = 0;
int meat2_y = 0;



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

//baddies
bool EGG_HIT = false;
bool HOTDOG_HIT = false;
bool PICKLE_HIT = false;

//burger status
//0 = new, 1 = top falling to platform2, 2 = meat falling to platform3, 3 = top falling to platform3, 4 = complete, 5 = waiting
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
      //add lives
      for(int i = 0; i < LIVES; i++){
        int16_t livesx = (1 + (i*5));
        arduboy.drawBitmap(livesx,1,the_lives,4,4,BLACK);
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
      arduboy.drawBitmap(0,0,the_level_done, 128, 64, WHITE);
      delay(100);
      if(!SOUND_PLAYED && SOUND_ENABLED){
        SOUND_PLAYED = true;
        soundLevelDone();
      }
    break;


    //game over
    case 3: 
      arduboy.drawBitmap(56,12,the_egg_f1,16,24,WHITE);
      arduboy.setCursor(38,50);
      arduboy.print("TRY AGAIN");
      handleButtons();
      arduboy.display();
      if(!SOUND_PLAYED && SOUND_ENABLED){
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
        delay(100);
      }
      if ( arduboy.pressed(B_BUTTON) ){
        LIVES = 5;
        SCORE = 0;
        CURRENT_LEVEL = 1;
        GAME_STATE = 1;
        delay(100);  
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

      //level done
      case 2:
        if( arduboy.pressed(A_BUTTON) || arduboy.pressed(B_BUTTON) ){
          CURRENT_LEVEL++;          
          LIVES = MAX_LIVES;
          SOUND_PLAYED = false;
          EGG_HIT = false;
          PICKLE_HIT = false;
          HOTDOG_HIT = false;
          burger1status = 0;
          burger2status = 0;
          player_y = 44;
          GAME_STATE = 1;
        }
      break;

      //game over
      case 3:
        if( arduboy.pressed(A_BUTTON) || arduboy.pressed(B_BUTTON) ){
          CURRENT_LEVEL = 0;
          GAME_STATE = 0;
          LIVES = MAX_LIVES;
          SOUND_PLAYED = false;
          EGG_HIT = false;
          PICKLE_HIT = false;
          HOTDOG_HIT = false;
          burger1status = 0;
          burger2status = 0;
          player_y = 44;
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
          if(arduboy.everyXFrames(10) && SOUND_ENABLED){
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
          if(arduboy.everyXFrames(10) && SOUND_ENABLED){
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
            if(arduboy.everyXFrames(10) && SOUND_ENABLED){
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
          if(arduboy.everyXFrames(10) && SOUND_ENABLED){
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
    case 1:
      for(int i=0; i<11; i=i+2){        
        if( (player_x+12) >= (level1ladders[i]+8) && (player_x+8) <= (level1ladders[i]+16) ){
          ret = true;
        }
      }
    break;
    
    case 2:
      for(int i=0; i<7; i=i+2){        
        if( (player_x+12) >= (level2ladders[i]+8) && (player_x+8) <= (level2ladders[i]+16) && (player_y+16) >= (level2ladders[i+1]-4) && (player_y+16) <= (level2ladders[i+1]+28) ){
          ret = true;
        }
      }
    break;

    case 3:
      for(int i=0; i<5; i=i+2){        
        if( (player_x+12) >= (level3ladders[i]+8) && (player_x+8) <= (level3ladders[i]+16) && (player_y+16) >= (level2ladders[i+1]-4) && (player_y+16) <= (level2ladders[i+1]+28) ){
          ret = true;
        }
      }
    break;
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
  if(!EGG_HIT){
    switch(CURRENT_LEVEL){
      case 1:
        egg_y = 14;
      break;
      case 2:
        egg_y = -10;
      break;
      case 3:
        egg_y = 38;
      break;
    }
  }
  if(egg_x == 112 && egg_direction == 1){
    egg_direction = 0;
  }
  if(egg_x == 0 && egg_direction == 0){
    egg_direction = 1;
  }  
  if(arduboy.everyXFrames(2)){
    if(egg_direction == 0){
      egg_x--;
    } else if(egg_direction == 1){
      egg_x++;
    }
  }
  if(egg_direction == 0){
    arduboy.drawBitmap( egg_x,egg_y,the_egg_f2,16,24,BLACK);
  } else if(egg_direction == 1){
    arduboy.drawBitmap( egg_x,egg_y,the_egg_f1,16,24,BLACK);
  }
  return;
}

 //pickle
void doPickle(){
  if(!PICKLE_HIT){
    switch(CURRENT_LEVEL){
      case 1:
        pickle_y = -4;
      break;
      case 2:
        pickle_y = 44;
      break;
      case 3:
        pickle_y = 20;
      break;
    }  
  }
  if(pickle_x == 112 && pickle_direction == 1){
    pickle_direction = 0;
  }
  if(pickle_x == 0 && pickle_direction == 0){
    pickle_direction = 1;
  }  
  
  if(pickle_direction == 0){
    pickle_x--;
    arduboy.drawBitmap( pickle_x,pickle_y,the_pickle_f2,16,16,BLACK);
  } else if(pickle_direction == 1){
    pickle_x++;
    arduboy.drawBitmap( pickle_x,pickle_y,the_pickle_f1,16,16,BLACK);
  }
  return;
}

//hotdog
void doHotdog(){
  if(!HOTDOG_HIT){
    switch(CURRENT_LEVEL){
      case 1:
        hotdog_y = 44;
      break;
      case 2:
        hotdog_y = 20;
      break;
      case 3:
        hotdog_y = -4;
      break;
    }  
  }
  if(hotdog_x == 112 && hotdog_direction == 1){
    hotdog_direction = 0;
  }
  if(hotdog_x == 0 && hotdog_direction == 0){
    hotdog_direction = 1;
  }  
  if(arduboy.everyXFrames(3)){
    if(hotdog_direction == 0){
      hotdog_x--;
    } else if(hotdog_direction == 1){
      hotdog_x++;
    }
  }
  if(hotdog_direction == 0){
    arduboy.drawBitmap( hotdog_x,hotdog_y,the_hotdog_f2,16,16,BLACK);
  } else if(hotdog_direction == 1){
    arduboy.drawBitmap( hotdog_x,hotdog_y,the_hotdog_f1,16,16,BLACK);
  }
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
      /*
       * burger 1 
       */
      //new
      if(burger1status == 0){
        topbun1_x = level1burgers[0];
        topbun1_y = level1burgers[1];
        meat1_x = level1burgers[4];
        meat1_y = level1burgers[5];
      }
      //top falling to platform2
      if(burger1status == 1){        
        if(topbun1_y<(platform2_y-3)){
          topbun1_y++;
        } else {
          doGoodSound();
          if(meat1_y<(platform3_y-5)){
            meat1_y++;
          } else {
            doGoodSound();
            burger1status = 5;
          }
        }
      }
      //meat falling to platform3
      if(burger1status == 2){        
        if(meat1_y<(platform3_y-5)){
          meat1_y++;
        }else{
          doGoodSound();
          burger1status = 5;
        }
      }
      //top falling to platform3
      if(burger1status == 3){        
        if(topbun1_y<(platform3_y-10)){
          topbun1_y++;
        } else {
          doGoodSound();
          if(meat1_y<(platform3_y-5)){
            meat1_y++;
          } else {
            doGoodSound();
            burger1status = 5;
          }
        }        
      }
      arduboy.drawBitmap( level1burgers[0],topbun1_y,the_top_bun,24,6,BLACK);
      arduboy.drawBitmap( level1burgers[4],meat1_y,the_meat,24,6,BLACK);
      arduboy.drawBitmap( level1burgers[8],level1burgers[9],the_bottom_bun,24,6,BLACK);


      /*
       * burger 2
       */
      //new
      if(burger2status == 0){
        topbun2_x = level1burgers[2];
        topbun2_y = level1burgers[3];
        meat2_x = level1burgers[6];
        meat2_y = level1burgers[7];
      }
      //top falling to platform2
      if(burger2status == 1){
        if(topbun2_y<(platform2_y-3)){
          topbun2_y++;
        } else {
          doGoodSound();
          if(meat2_y<(platform3_y-5)){
            meat2_y++;
          } else {
            doGoodSound();
            burger2status = 5;
          }
        }
      }
      //meat falling to platform3
      if(burger2status == 2){
        if(meat2_y<(platform3_y-5)){
          meat2_y++;          
        }else{
          doGoodSound();
          burger2status = 5;
        }
      }
      //top falling to platform3
      if(burger2status == 3){
        if(topbun2_y<(platform3_y-10)){
          topbun2_y++;
        } else {
          doGoodSound();
          if(meat2_y<(platform3_y-5)){
            meat2_y++;
          } else {      
            doGoodSound();   
            burger2status = 5;
          }
        }        
      }
      arduboy.drawBitmap( level1burgers[2],topbun2_y,the_top_bun,24,6,BLACK);
      arduboy.drawBitmap( level1burgers[6],meat2_y,the_meat,24,6,BLACK);
      arduboy.drawBitmap( level1burgers[10],level1burgers[11],the_bottom_bun,24,6,BLACK);

      //all done?
      if( topbun1_y == (platform3_y-10) && meat1_y == (platform3_y-5) && topbun2_y == (platform3_y-10) && meat2_y == (platform3_y-5) ){
        GAME_STATE = 2;
      }
    break;



    case 2:
      /*
       * burger 1 
       */
      //new
      if(burger1status == 0){
        topbun1_x = level2burgers[0];
        topbun1_y = level2burgers[1];
        meat1_x = level2burgers[2];
        meat1_y = level2burgers[3];
      }
      //top falling to platform2
      if(burger1status == 1){        
        if(topbun1_y<(platform2_y-3)){
          topbun1_y++;
        } else {
          doGoodSound();
          if(meat1_y<(platform3_y-5)){
            meat1_y++;
          } else {
            doGoodSound();
            burger1status = 5;
          }
        }
      }
      //meat falling to platform3
      if(burger1status == 2){        
        if(meat1_y<(platform3_y-5)){
          meat1_y++;
        }else{
          doGoodSound();
          burger1status = 5;
        }
      }
      //top falling to platform3
      if(burger1status == 3){        
        if(topbun1_y<(platform3_y-10)){
          topbun1_y++;
        } else {
          doGoodSound();
          if(meat1_y<(platform3_y-5)){
            meat1_y++;
          } else {
            doGoodSound();
            burger1status = 5;
          }
        }        
      }
      arduboy.drawBitmap( level2burgers[0],topbun1_y,the_top_bun,24,6,BLACK);
      arduboy.drawBitmap( level2burgers[2],meat1_y,the_meat,24,6,BLACK);
      arduboy.drawBitmap( level2burgers[4],level2burgers[5],the_bottom_bun,24,6,BLACK);
      //all done?
      if( topbun1_y == (platform3_y-10) && meat1_y == (platform3_y-5) ){
        GAME_STATE = 2;
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
    //baddies
    if( (player_x+16) >= egg_x && (player_x+16) <= (egg_x+16) && player_y == (egg_y+6) ){
      if(arduboy.everyXFrames(10)){
        dingHealth();
      }
    }
    if( (player_x+16) >= hotdog_x && (player_x+16) <= (hotdog_x+16) && player_y == hotdog_y){
      if(arduboy.everyXFrames(10)){
        dingHealth();
      }
    }
    if( (player_x+16) >= pickle_x && (player_x+16) <= (pickle_x+16) && player_y == pickle_y ){
      if(arduboy.everyXFrames(10)){
        dingHealth();
      }
    }



    

    //burger 1
    //top bun hits baddie
    if( burger1status == 1 || burger1status == 3 ){
      if( topbun1_x <= egg_x && (topbun1_x+24) >= egg_x && topbun1_y >= egg_y ){
          egg_y = 70;
          EGG_HIT = true;
      }
      if( topbun1_x <= pickle_x && (topbun1_x+24) >= pickle_x && topbun1_y >= pickle_y ){
          pickle_y = 70;
          PICKLE_HIT = true;
      }
      if( topbun1_x <= hotdog_x && (topbun1_x+24) >= hotdog_x && topbun1_y >= hotdog_y ){
          hotdog_y = 70;
          HOTDOG_HIT = true;
      }
    }
    //meat hits baddies
    if( burger1status == 2 ){
      if( meat1_x <= egg_x && (meat1_x+24) >= egg_x && meat1_y >= egg_y ){
          egg_y = 70;
          EGG_HIT = true;
      }
      if( meat1_x <= pickle_x && (meat1_x+24) >= pickle_x && meat1_y >= pickle_y ){
          pickle_y = 70;
          PICKLE_HIT = true;
      }
      if( meat1_x <= hotdog_x && (meat1_x+24) >= hotdog_x && meat1_y >= hotdog_y ){
          hotdog_y = 70;
          HOTDOG_HIT = true;
      }
    }

    //burger 2
    //top bun hits baddie
    if( burger2status == 1 || burger2status == 3 ){
      if( topbun2_x <= egg_x && (topbun2_x+24) >= egg_x && topbun2_y >= egg_y ){
          egg_y = 70;
          EGG_HIT = true;
      }
      if( topbun2_x <= pickle_x && (topbun2_x+24) >= pickle_x && topbun2_y >= pickle_y ){
          pickle_y = 70;
          PICKLE_HIT = true;
      }
      if( topbun2_x <= hotdog_x && (topbun2_x+24) >= hotdog_x && topbun2_y >= hotdog_y ){
          hotdog_y = 70;
          HOTDOG_HIT = true;
      }
    }
    //meat hits baddies
    if( burger2status == 2 ){
      if( meat2_x <= egg_x && (meat2_x+24) >= egg_x && meat2_y >= egg_y ){
          egg_y = 70;
          EGG_HIT = true;
      }
      if( meat2_x <= pickle_x && (meat2_x+24) >= pickle_x && meat2_y >= pickle_y ){
          pickle_y = 70;
          PICKLE_HIT = true;
      }
      if( meat2_x <= hotdog_x && (meat2_x+24) >= hotdog_x && meat2_y >= hotdog_y ){
          hotdog_y = 70;
          HOTDOG_HIT = true;
      }
    }




    
    
    //hit item on platform 1{
    if( (player_y+16) == platform1_y ){
      //burgers
      if(burger1status == 0 || burger1status == 5){
        //burger 1
        if( topbun1_y == (platform1_y-3) && (player_x + 16) >= topbun1_x && (player_x+16) <= (topbun1_x+24) ){
          burger1status = 1;
        }
        //burger 2
        if( topbun2_y == (platform1_y-3) && (player_x + 16) >= topbun2_x && (player_x+16) <= (topbun2_x+24) ){
          burger2status = 1;
        }
      }
    }

    //hit item on platform 2{
    if( (player_y+16) == platform2_y ){
      //burgers
      if(burger1status == 0 || burger1status == 5){
        //burger 1
        if( meat1_y == (platform2_y-3) && (player_x + 16) >= meat1_x && (player_x+16) <= (meat1_x+24) ){
          burger1status = 2;
        }
        if( topbun1_y == (platform2_y-3) && (player_x + 16) >= topbun1_x && (player_x+16) <= (topbun1_x+24) ){
          burger1status = 3;
        }
        //burger 2
        if( meat2_y == (platform2_y-3) && (player_x + 16) >= meat2_x && (player_x+16) <= (meat2_x+24) ){
          burger2status = 2;
        }
        if( topbun2_y == (platform2_y-3) && (player_x + 16) >= topbun2_x && (player_x+16) <= (topbun2_x+24) ){
          burger2status = 3;
        }
      }   
    }
  }
  
}













/*
 * ding the health
 */
void dingHealth(){
  if(ALLOW_BUTTONS){
    if(LIVES == 0){
      //game over
      GAME_STATE = 3;
    } else {
      LIVES--;
      if(SOUND_ENABLED){
        soundEgg();
      }      
      player_x = 8;
      player_y = 44;
    }
    PLAYER_HIT = false;
  }
}




/*
 * add to health
 */
void addHealth(){
  if(LIVES<MAX_LIVES){
    LIVES++;
  }
  doGoodSound();
}


/*
 * do sound
 */
void doGoodSound(){
  if(SOUND_ENABLED){ 
    soundGood();
  }
}
void trace(String the_string){
  arduboy.setCursor(0,56);
  arduboy.print(the_string);
}
