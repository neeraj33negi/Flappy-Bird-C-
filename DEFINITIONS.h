#ifndef DEFINITIONS_H
#define DEFINITIONS_H

#define SCREEN_WIDTH 768
#define SCREEN_HEIGHT 1024



#define SPLASH_STATE_SHOW_TIME 3.0
#define SPASH_SCREEN_BACKGROUND_FILE_PATH "Resources/res/splash.png"



#define MAIN_MENU_BACKGROUND_FILE_PATH "Resources/res/sky.png"
#define GAME_TITLE_FILE_PATH "Resources/res/title.png"
#define PLAY_BUTTON_FILE_PATH "Resources/res/PlayButton.png"
#define GAME_BACKGROUND_FILE_PATH "Resources/res/sky.png"
#define GAMEOVER_BACKGROUND_FILE_PATH "Resources/res/sky.png"
#define GAMEOVER_TITLE_FILE_PATH "Resources/res/Game-Over-Title.png"
#define GAMEOVER_BODY_FILE_PATH "Resources/res/Game-Over-Body.png"


#define TIME_BEFORE_GAMEOVER_APPEARS 0.75f


#define PIPE_UP_FILE_PATH "Resources/res/PipeUp.png"
#define PIPE_DOWN_FILE_PATH "Resources/res/PipeDown.png"
#define SCORING_PIPE_FILE_PATH "Resources/res/InvisibleScoringPipe.png"
#define PIPE_MOVEMENT_SPEED 210.0f
#define PIPE_SPAWN_FREQUENCY 1.0f



#define LAND_FILE_PATH "Resources/res/Land.png"
#define LAND_MOVEMENET_SPEED 250.0f



#define BIRD_FRAME1_FILE_PATH "Resources/res/bird-01.png"
#define BIRD_FRAME2_FILE_PATH "Resources/res/bird-02.png"
#define BIRD_FRAME3_FILE_PATH "Resources/res/bird-03.png"
#define BIRD_FRAME4_FILE_PATH "Resources/res/bird-04.png"

#define BIRD_STATE_STILL 1
#define BIRD_STATE_FLYING 2
#define BIRD_STATE_FALLING 3
#define GRAVITY 350.0f
#define BIRD_ANIMATION_DURATION 0.4f
#define BIRD_FLYING_DURATION 0.30f 
#define BIRD_FLYING_SPEED 350.0f
#define BIRD_ROTATION_SPEED 100.0f

#define HIT_SOUND_FILE_PATH "Resources/audio/Hit.wav"
#define WING_SOUND_FILE_PATH "Resources/audio/Wing.wav"
#define POINT_SOUND_FILE_PATH "Resources/audio/Point.wav"


#define FLAPPY_FONT_FILE_PATH "Resources/fonts/FlappyFont.ttf"

#define HIGHSCORE_FILE_PATH "Resources/HighScore.txt"


#define BRONZE_MEDAL_FILE_PATH "Resources/res/Bronze-Medal.png"
#define SILVER_MEDAL_FILE_PATH "Resources/res/Silver-Medal.png"
#define GOLD_MEDAL_FILE_PATH "Resources/res/Gold-Medal.png"
#define PLATINUM_MEDAL_FILE_PATH "Resources/res/Platinum-Medal.png"


#define BRONZE_MEDAL_SCORE 0
#define SILVER_MEDAL_SCORE 25
#define GOLD_MEDAL_SCORE 50




enum GameStates{
    eReady,
    ePlaying,
    eGameOver
};

#define FLASH_SPEED 2500.0f


#endif