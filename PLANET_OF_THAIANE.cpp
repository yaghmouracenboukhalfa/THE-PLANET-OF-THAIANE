#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <vector>
#include <thread>
#include <chrono>
using namespace sf;
using namespace std;

struct Bullet {
    RectangleShape shape;
    float speed;
    int direction;// 1 = right, -1 = left
    bool fromPlayer;// true if shot by player, false if by enemy
};

int main() {
    RenderWindow window(VideoMode(1010, 460), "PLANET OF THAIANE", Style::Titlebar | Style::Close);//(x, y, title, style)
    window.setFramerateLimit(60);//60 FPS
    int currentpage = -2;//-2
    int triller_ones=0;//0
    Clock trailerClock;
    const float trailerPageDuration = 3.0f; // seconds per trailer page

    Clock lastTrailerClock;
    const float lastTrailerPageDuration = 3.0f; // seconds per trailer page
    int activateCross =0;//0=not activated, 1=activated

    //game icone
    Image icon;
    if (!icon.loadFromFile("img\\icone.jpg")) {
        return -1;
    }
    window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());
    // ________textures setup________
  Texture texture0, texture1, texture2,texture3,texture4,texture5,texture6,texture7,texture8,texture9,texture10,texture11,texture12,texture13,texture14,texture15,texture16,texture17,texture18,texture19,texture20,texture21,texture22,texture23,texture24,texture25,texture26,texture27,texture28,texture29,texture30,texture31,texture32,texture33,texture34,texture35,texture36,texture37,texture38,texture39,texture40,texture41,texture42,texture43,texture44,texture45,texture46,texture47,texture48,texture49,texture50,texture51,texture52,texture53,texture54,texture55,texture56,texture57,texture58,texture59,texture60,texture61,texture62,texture63,texture64,texture65,texture66,texture67,texture68,texture69,texture70,texture71,texture72,texture73,texture74,texture75,texture76,texture77,texture78,texture79,texture80,texture81,texture82,texture83,texture84,texture85,texture86,texture87,texture88,texture89,texture90,texture91,texture92,texture93,texture94,texture95,texture96,texture97,texture98,texture99;
  if (!texture0.loadFromFile("img\\20260123_130445.jpg")) {//house and cow
    return -1;
  }
  if (!texture1.loadFromFile("img\\grass.png")) {//grass
    return -1;
  }
  if (!texture2.loadFromFile("img\\1.jpg")){//forest
    return -1;
  }
  if (!texture3.loadFromFile("img\\2.jpg")){//forest +rever
        return -1;
  }
  if(!texture4.loadFromFile("img\\3.jpg")){//forest+robot
    return -1;
  }
   if(!texture5.loadFromFile("img\\4.jpg")){//forest+cave enerence
    return -1;
  }
  if(!texture6.loadFromFile("img\\5.jpg")){//inside the cave 1
    return -1;
    }
  if(!texture7.loadFromFile("img\\6.jpg")){//inside the cave 2
    return -1;
    }
  if(!texture8.loadFromFile("img\\7.jpg")){//inside the cave 3+out
    return -1;
    }
  if(!texture9.loadFromFile("img\\9.jpg")){//the sahl
    return -1;
    }
  if(!texture10.loadFromFile("img\\10.jpg")){//the sahl+sahara
    return -1;
    }
    if (!texture11.loadFromFile("img\\11.jpg")) {//sahara+mountain
        return -1;
    }
    if (!texture12.loadFromFile("img\\sahara platform.png")) {//sahara platform
        return -1;
    }
    if (!texture13.loadFromFile("img\\12.jpg")) {//sahara platform
        return -1;
    }
    if (!texture14.loadFromFile("img\\13.jpg")) {//sahara end +sahl
        return -1;
    }
    if (!texture15.loadFromFile("img\\14.jpg")) {//sahl+destroyed city
        return -1;
    }
    if (!texture16.loadFromFile("img\\15.jpg")) {//destroyed city enterence
        return -1;
    }
    if (!texture17.loadFromFile("img\\16.png")) {//city platform
        return -1;
    }
    if (!texture18.loadFromFile("img\\17.jpg")) {//destroyed city inside1
        return -1;
    }
    if (!texture19.loadFromFile("img\\18.jpg")) {//destroyed city inside2
        return -1;
    }
    //player frames :
    if(!texture20.loadFromFile("img\\Stand.png")){//standing frame
        return -1;
    }
    vector<Texture> runTextures(7);// running frames
    for (int i = 0; i < 7; ++i) {
        if (!runTextures[i].loadFromFile("img\\Run" + to_string(i + 1) + ".png")) {
            return -1;
        }
    }
    vector<Texture> koTextures(2);// ko(shooting) frames
    for (int i = 0; i < 2; ++i) {
        if (!koTextures[i].loadFromFile("img\\ko" + to_string(i + 1) + ".png")) {
            return -1;
        }
    }
    vector<Texture> superJumpTextures(1);// super jump frames
    for (int i = 0; i < 1; ++i) {
        if (!superJumpTextures[i].loadFromFile("img\\jump" + to_string(i + 1) + ".png")) {
            return -1;
        }
    }
    //car frame:
    if(!texture21.loadFromFile("img\\Brake.png")){//car
        return -1;
    }
    if(!texture22.loadFromFile("img\\Ride.png")){//car while riding
        return -1;
    }
    //enemy frame:
    //enemy 1 frame:
    if(!texture23.loadFromFile("img\\enemy1walk.png")){//enemy 1 walking
        return -1;
    }
    //enemy 2 frame:
    if(!texture25.loadFromFile("img\\enemy2walk.png")){//enemy 2 walking
        return -1;
    }
    //enemy 3 frame:
    if(!texture27.loadFromFile("img\\enemy3walk.png")){//enemy 3 walking
        return -1;
    }
    if(!texture28.loadFromFile("img\\enemy3shoot.png")){//enemy 3 shooting
        return -1;
    }
    //health bar textures:
    if(!texture29.loadFromFile("img\\hp0.png")){//health 0
        return -1;
    }
    if(!texture30.loadFromFile("img\\hp1.png")){//health 1
        return -1;
    }
    if(!texture31.loadFromFile("img\\hp2.png")){//health 2
        return -1;
    }
    if(!texture32.loadFromFile("img\\hp3.png")){//health 3
        return -1;
    }
    if(!texture33.loadFromFile("img\\hp4.png")){//health 4
        return -1;
    }
    if(!texture34.loadFromFile("img\\hp5.png")){//health 5
        return -1;
    }
    if(!texture35.loadFromFile("img\\hp6.png")){//health 6
        return -1;
    }
    //menu page textures:
    if(!texture36.loadFromFile("img\\page0.jpg")){//menu page 1
        return -1;
    }
    if(!texture37.loadFromFile("img\\play_now.png")){//play now btn
        return -1;
    }
    //btn texture for page 4
    if(!texture38.loadFromFile("img\\click_here.png")){//btn for page 4
        return -1;
    }
    //texture for page9
    if(!texture39.loadFromFile("img\\press_r.png")){// press R
        return -1;
    }
    //triller pages texturees:
    if(!texture40.loadFromFile("img\\t1.jpg")){
        return -1;
    }
    if(!texture41.loadFromFile("img\\t2.jpg")){
        return -1;
    }
    if(!texture42.loadFromFile("img\\t3.jpg")){
        return -1;
    }
    if(!texture43.loadFromFile("img\\t4.jpg")){
        return -1;
    }
    if(!texture44.loadFromFile("img\\t5.jpg")){
        return -1;
    }
    if(!texture45.loadFromFile("img\\t6.jpg")){
        return -1;
    }
    if(!texture46.loadFromFile("img\\t7.jpg")){
        return -1;
    }
    if(!texture47.loadFromFile("img\\t8.jpg")){
        return -1;
    }
    if(!texture48.loadFromFile("img\\t9.jpg")){
        return -1;
    }
    if(!texture49.loadFromFile("img\\t10.jpg")){
        return -1;
    }
    if(!texture50.loadFromFile("img\\t11.jpg")){
        return -1;
    }
    if(!texture51.loadFromFile("img\\t12.png")){
        return -1;
    }
    if(!texture52.loadFromFile("img\\t13.jpg")){
        return -1;
    }
    if(!texture53.loadFromFile("img\\t14.jpg")){
        return -1;
    }
    if(!texture54.loadFromFile("img\\t15.jpg")){
        return -1;
    }
    if(!texture55.loadFromFile("img\\t16.jpg")){
        return -1;
    }
    if(!texture56.loadFromFile("img\\t17.jpg")){
        return -1;
    }
    if(!texture57.loadFromFile("img\\t18.jpg")){
        return -1;
    }
    if(!texture58.loadFromFile("img\\t19.jpg")){
        return -1;
    }
    if(!texture59.loadFromFile("img\\t20.jpg")){
        return -1;
    }
    if(!texture60.loadFromFile("img\\black.jpg")){
        return -1;
    }
    if(!texture61.loadFromFile("img\\yb_logo.jpg")){
        return -1;
    }
    if(!texture62.loadFromFile("img\\thainane_logo.jpg")){
        return -1;
    }
    //last triller pages texturees:
    if(!texture63.loadFromFile("img\\last_tr1.jpg")){
        return -1;
    }
    if(!texture64.loadFromFile("img\\last_tr2.jpg")){
        return -1;
    }
    if(!texture65.loadFromFile("img\\last_tr3.jpg")){
        return -1;
    }
    if(!texture66.loadFromFile("img\\last_tr4.jpg")){
        return -1;
    }

    //audio setup
    float sfxVolume = 50.f; // sound volume (0-100)
    float sfxVolume2 = 20.f; // sound volume (0-100)
    float sfxVolume3 = 7.f; // sound volume (0-100)
    float sfxVolume4 = 15.f; // sound volume (0-100)
    float sfxVolume5 = 75.f; // sound volume (0-100)

    SoundBuffer buffer1,buffer2,buffer3,buffer4,buffer5,buffer6,buffer7,buffer8,buffer9,buffer10;
    if (!buffer1.loadFromFile("audio\\triller1audio.mp3")) {//triller1 audio
        return -1;
    }
    Sound triller1Sound;
    triller1Sound.setBuffer(buffer1);

    if (!buffer2.loadFromFile("audio\\Nature.mp3")) {//nature audio
        return -1;
    }
    Sound natureSound;
    natureSound.setBuffer(buffer2);
    natureSound.setVolume(sfxVolume);

    if (!buffer3.loadFromFile("audio\\gun-shot.mp3")) {//gun shot audio
        return -1;
    }
    Sound gunSound;
    gunSound.setBuffer(buffer3);

    if (!buffer4.loadFromFile("audio\\robot-shoot.mp3")) {//robot gun shot audio
        return -1;
    }
    Sound robotGunSound;
    robotGunSound.setBuffer(buffer4);
    robotGunSound.setVolume(sfxVolume2);

   if (!buffer5.loadFromFile("audio\\car-driving.mp3")) {//car driving audio
        return -1;
    }
    Sound carMovingSound;
    carMovingSound.setBuffer(buffer5);
    carMovingSound.setVolume(sfxVolume2);

   if (!buffer6.loadFromFile("audio\\desert-wind.mp3")) {//desert audio
        return -1;
    }
    Sound desertWindSound;
    desertWindSound.setBuffer(buffer6);
    desertWindSound.setVolume(sfxVolume3);

   if (!buffer7.loadFromFile("audio\\running.mp3")) {//runing audio
        return -1;
    }
    Sound runningSound;
    runningSound.setBuffer(buffer7);
    runningSound.setVolume(sfxVolume4);

    if (!buffer8.loadFromFile("audio\\trieler2sound.mp3")) {//triller2 audio
        return -1;
    }
    Sound triller2;
    triller2.setBuffer(buffer8);
    triller2.setVolume(sfxVolume5);


    // ________game objects setup________
    //________car________
    RectangleShape car(Vector2f(400, 150));
    car.setFillColor(Color::Red);
    car.setPosition(250.f, 420 - car.getSize().y);// start position(on ground)

    const float carSpeed = 7.f;
    int rideCar = 0; // 0=not riding, 1=riding
    int carmoving=0;//0=stop 1=moving
    int cardamage=0;//0= no damage 1= there is damage

   // RectangleShape rideCarSign(Vector2f(150.f, 50.f));//betton to ride the car
    Sprite pressR(texture39);// press R
    pressR.setScale(.1, .1f);
    pressR.setPosition(350.f, 180.f);//(x, y)
    int onec=0;//to show the signe only ones
    int carCoureentPage=9;//to save the page where the car is located

    // ───── PLAYER ─────
    RectangleShape player(Vector2f(45, 180));
    player.setFillColor(Color::Green);
    player.setPosition(100, 220);// start position

    //velocity.x → حركة يمين / يسار
    //velocity.y → سقوط / قفز
    Vector2f velocity(0.f, 0.f);//(x, y)
    const float speed = 4.5f;
    const float gravity = 0.8f;
    const float jumpPower = -18.0f;// negative value to go up(opposite to gravity)(-15)

    bool isGrounded = false;// to check if player is on ground(in ground=true state, can jump)
    bool playerAlive = true;// to check if player is alive(true=alive, false=dead)
    int playerHealth = 4;// player health (max 6)

    Clock jumpClock;
    const float jumpCooldown = 1.;// jump ability stopped for 0.8 seconds after each jump

    bool movementLocked = false;
    Clock movementLockClock;
    const float movementLockTime = 0.3f; // seconds

    Clock shootClock;
    const float shootCooldown = 0.5f;// time between each shot

    Clock playerDamageClock;
    const float damageCooldown = 1.0f;// time between each damage taken from enemy

    int facing = 1;// 1 = right, -1 = left (starts facing right)

    // ───── GROUND ─────
    RectangleShape ground(Vector2f(1010, 20));
    ground.setFillColor(Color::Red);
    ground.setPosition(0, 420);
   //--------side wall-----------
    RectangleShape sideWallLeft(Vector2f(3, 460));
    sideWallLeft.setFillColor(Color::Blue);
    sideWallLeft.setPosition(0, 0);
    RectangleShape sideWallRight(Vector2f(3, 460));
    sideWallRight.setFillColor(Color::Blue);
    sideWallRight.setPosition(1010, 0);
    // ───── ENEMY ─────(enemy1)
    RectangleShape enemy(Vector2f(40, 160));
    enemy.setFillColor(Color::Magenta);
    enemy.setPosition(800.f, 420 - enemy.getSize().y);// start position(on ground)

    const float enemySpeed = 1.6f;
    int enemyHealth = 7;
    bool enemyAlive = false;// to check if enemy is alive(true=alive, false=dead)
    int enemyIsWalking = 1; // 1=walking, 0=shooting
    // Enemy AI delay
    Clock enemyThinkClock;// to control thinking delay
    const float enemyThinkDelay = 1.0f; // seconds
    int enemyDir = -1; // last decision(-1=left, 1=right)

    Clock enemyShootClock;// to control enemy shooting delay
    const float enemyShootCooldown = 1.5f;// time between each shot

    // ───── ENEMY1 ─────(enemy2)
    RectangleShape enemy1(Vector2f(40, 160));
    enemy1.setFillColor(Color::Green);
    enemy1.setPosition(800.f, 420 - enemy1.getSize().y);// start position(on ground)

    const float enemy1Speed = 1.6f;
    int enemy1Health = 7;
    bool enemy1Alive = false;// to check if enemy is alive(true=alive, false=dead)
    int enemy1IsWalking = 1; // 1=walking, 0=shooting

    // Enemy1 AI delay
    Clock enemy1ThinkClock;// to control thinking delay
    const float enemy1ThinkDelay = 1.2f; // seconds
    int enemy1Dir = -1; // last decision(-1=left, 1=right)

    Clock enemy1ShootClock;// to control enemy shooting delay
    const float enemy1ShootCooldown = 1.5f;// time between each shot

    // ───── ENEMY2 ─────(enemy3)
    RectangleShape enemy2(Vector2f(60, 145));
    enemy2.setFillColor(Color::Yellow);
    enemy2.setPosition(800.f, 420 - enemy2.getSize().y);// start position(on ground)

    const float enemy2Speed = 2.5f;
    int enemy2Health = 13;
    bool enemy2Alive = false;// to check if enemy is alive(true=alive, false=dead)
    int enemy2IsWalking = 1; // 1=walking, 0=shooting
    float destanceToPlayer = 0.f;// to store the distance between enemy2 and player

    // Enemy2 AI delay
    Clock enemy2ThinkClock;// to control thinking delay
    const float enemy2ThinkDelay = .7f; // seconds
    int enemy2Dir = -1; // last decision(-1=left, 1=right)

    Clock enemy2ShootClock;// to control enemy shooting delay
    const float enemy2ShootCooldown = 1.5f;// time between ea
    // ───── BULLETS ─────
    vector<Bullet> bullets;
    const float bulletSpeed = 8.0f;// speed of bullets


   // ________sprites setup________

    //______player sprite setup______
    //standing frame:
    Sprite playerSprite(texture20);//standing frame
    playerSprite.setScale(0.2f, 0.2f);//scale down to fit player size


    //running frames setup:
    Sprite playerSpriteRun;
    playerSpriteRun.setTexture(runTextures[0]); // start with first frame
    playerSpriteRun.setScale(0.45f, 0.45f);//scale down to fit player size
    vector<Vector2f> runScales(7);
    runScales[0] = Vector2f(0.45f, 0.45f);
    runScales[1] = Vector2f(0.45f, 0.45f);
    runScales[2] = Vector2f(0.52f, 0.52f);
    runScales[3] = Vector2f(0.52f, 0.52f);
    runScales[4] = Vector2f(0.45f, 0.45f);
    runScales[5] = Vector2f(0.45f, 0.45f);
    runScales[6] = Vector2f(0.45f, 0.45f);
    vector<Vector2f> runOffsets(7);
    // manually adjust until it looks right
    runOffsets[0] = Vector2f(-70.f, -20.f); // frame 0 (-70,-20)
    runOffsets[1] = Vector2f(-70.f, -20.f); // frame 1  (-70,-20)
    runOffsets[2] = Vector2f(-70.f, -20.f); // frame 2 need fix
    runOffsets[3] = Vector2f(-70.f, -20.f);  // frame 3 need fix
    runOffsets[4] = Vector2f(-70.f, -20.f); // frame 4
    runOffsets[5] = Vector2f(-70.f, -20.f); // frame 5
    runOffsets[6] = Vector2f(-70.f, -20.f); // frame 6

    int RunCurrentFrame = 0;
    float RunFrameTime = 0.09f; // seconds per frame
    float RunTimer = 0.f;
    Clock RunClock;
 

    //ko(shooting) frames setup:
    Sprite playerSpriteKo;
    playerSpriteKo.setTexture(koTextures[0]); // start with first frame
    vector<Vector2f> koScales(2);
    //koScales[0] = Vector2f(0.47f, 0.47f);
    koScales[0] = Vector2f(0.47f, 0.47f);
    koScales[1] = Vector2f(0.67f, 0.67f);
   // koScales[3] = Vector2f(0.45f, 0.45f);
   // koScales[4] = Vector2f(0.45f, 0.45f);
    vector<Vector2f> koOffsets(2);
    // manually adjust until it looks right
    //koOffsets[0] = Vector2f(-70.f, -3.f); // frame 0 (-70,-3)
    koOffsets[0] = Vector2f(-70.f, -3.f); // frame 1  
    koOffsets[1] = Vector2f(-45.f, -5.f); // frame 2.. 
    //koOffsets[3] = Vector2f(-70.f, -3.f);  // frame 3 
    //koOffsets[4] = Vector2f(-70.f, -3.f); // frame 4

    int koCurrentFrame = 0;
    float koFrameTime = .1; // seconds per frame
    float koTimer = 0.;
    Clock koClock;


    //super jump frames setup:
    Sprite playerSpriteSuperJump;
    playerSpriteSuperJump.setTexture(superJumpTextures[0]); // start with first frame
    vector<Vector2f> superJumpScales(1);
    superJumpScales[0] = Vector2f(0.55f, 0.55f);
    //superJumpScales[1] = Vector2f(0.55f, 0.55f);
    vector<Vector2f> superJumpOffsets(1);
    // manually adjust until it looks right
    superJumpOffsets[0] = Vector2f(-70.f, -20.f); // frame 1  (-70,-3)
   // superJumpOffsets[1] = Vector2f(-70.f, -20.f); // frame 2.. 

    int superJumpCurrentFrame = 0;
    float superJumpFrameTime2 = .9; // seconds per frame
    float superJumpTimer = 0.;
    Clock superJumpClock;

    bool justLanded = false;
    Clock landClock;
    const float landStandTime = 0.25f; // stand for 0.25s after landing

    // car sprite setup:
    // car standing frame:
    Sprite carSprite(texture21);//car standing frame
    carSprite.setScale(0.8f, 0.8f);//scale down to fit car size
    // car riding frame:
    Sprite carRideSprite(texture22);//car riding frame
   const int FRAME_WIDTH  = 256;
   const int FRAME_HEIGHT = 256;
   const int FRAME_COUNT  = 8;
    int carCurrentFrame = 0;
    float carframeTime = 0.1f; // seconds per frame
    float carTimer = 0.f;
    Clock carClock;

    // enemy sprite setup:

    //enemy 1 walking frame:
    Sprite enemy1SpriteWalk(texture23);//enemy 1 walking frame
    enemy1SpriteWalk.setScale(0.8f, 0.8f);//scale down to fit enemy size
    const int FRAME_COUNT1  = 8;
    const int FRAME_WIDTH1  = 128;
    const int FRAME_HEIGHT1 = 128;
    int enemy1CurrentFrame = 0;
    float enemy1frameTime = 0.1f; // seconds per frame
    float enemy1Timer = 0.f;
    Clock enemy1Clock;

    //enemy 2 walking frame:
    Sprite enemy2SpriteWalk(texture25);//enemy 2 walking frame
    enemy2SpriteWalk.setScale(0.8f, 0.8f);//scale down to fit enemy size
    const int FRAME_COUNT2  = 6;
    const int FRAME_WIDTH2  = 128;
    const int FRAME_HEIGHT2 = 128;
    int enemy2CurrentFrame = 0;
    float enemy2frameTime = 0.1f; // seconds per frame
    float enemy2Timer = 0.f;
    Clock enemy2Clock;

    //enemy 3 walking frame:
    Sprite enemy3SpriteWalk(texture27);//enemy 3walking frame
    enemy3SpriteWalk.setScale(0.8f, 0.8f);//scale down to fit enemy size
    const int FRAME_WIDTH3  = 128;
    const int FRAME_HEIGHT3 = 128;
    const int FRAME_COUNT3  = 8;
    int enemy3CurrentFrame = 0;
    float enemy3frameTime = 0.1f; // seconds per frame
    float enemy3Timer = 0.f;
    Clock enemy3Clock;
    //enemy 3 shooting frame:
    Sprite enemy3SpriteShoot(texture28);//enemy 3 shooting frame
    enemy3SpriteShoot.setScale(0.8f, 0.8f);//scale down to fit enemy size
    const int FRAME_WIDTH3_2  = 128;
    const int FRAME_HEIGHT3_2 = 128;
    const int FRAME_COUNT3_2  = 4;
    int enemy3CurrentFrame_2 = 0;
    float enemy3frameTime_2 = 0.1f; // seconds per frame
    float enemy3Timer_2 = 0.f;
    Clock enemy3Clock_2;

    //health bar sprite setup:
    Sprite hp0Sprite;
    hp0Sprite.setTexture(texture29);
    hp0Sprite.setScale(0.45f, 0.45f);
    hp0Sprite.setPosition(10.f, 10.f);
    Sprite hp1Sprite;
    hp1Sprite.setTexture(texture30);
    hp1Sprite.setScale(0.45f, 0.45f);
    hp1Sprite.setPosition(10.f, 10.f);
    Sprite hp2Sprite;
    hp2Sprite.setTexture(texture31);
    hp2Sprite.setScale(0.45f, 0.45f);
    hp2Sprite.setPosition(10.f, 8.f);//up
    Sprite hp3Sprite;
    hp3Sprite.setTexture(texture32);
    hp3Sprite.setScale(0.45f, 0.45f);
    hp3Sprite.setPosition(10.f, 6.f);
    Sprite hp4Sprite;
    hp4Sprite.setTexture(texture33);
    hp4Sprite.setScale(0.45f, 0.45f);
    hp4Sprite.setPosition(10.f, 10.f);//
    Sprite hp5Sprite;
    hp5Sprite.setTexture(texture34);
    hp5Sprite.setScale(0.45f, 0.45f);
    hp5Sprite.setPosition(10.f, 7.f);
    Sprite hp6Sprite;
    hp6Sprite.setTexture(texture35);
    hp6Sprite.setScale(0.45f, 0.45f);
    hp6Sprite.setPosition(10.f, 6.f);



//// trailer pages ______________:

    RectangleShape trailerwall1(Vector2f(150, 460));
    trailerwall1.setFillColor(Color::Black);
    trailerwall1.setPosition(0, 0);
    RectangleShape trailerwall2(Vector2f(150, 460));
    trailerwall2.setFillColor(Color::Black);
    trailerwall2.setPosition(860, 0);
    
    //______________page-1___________________
    Sprite t0_1(texture60);//trailer page 1(black)
    t0_1.setScale(.5f, .5f);
    t0_1.setPosition(0.f, 0.f);//(x, y)
    //______________page-2___________________
    Sprite t0_2(texture61);//trailer page 2(yb logo)
    t0_2.setScale(.5f, .5f);
    t0_2.setPosition(-100.f, -20.f);//(x, y)
    //______________page-3___________________
    //also black page
    //______________page-4___________________
    Sprite t0_3(texture62);//trailer page 3(thainane logo)
    t0_3.setScale(.5f, .5f);
    t0_3.setPosition(-100.f, -20.f);//(x, y)
    //______________page-5___________________
    //also black page for 3s
    //______________page-6___________________
    Sprite t1(texture40);//trailer page 4
    t1.setScale(.7f, .7f);
    t1.setPosition(50.f, -60.f);//(x, y)
    //______________page-7___________________
    Sprite t2(texture41);//trailer page 5
    t2.setScale(.7f, .7f);
    t2.setPosition(50.f, -60.f);//(x, y)
    //______________page-8___________________
    Sprite t3(texture42);//trailer page 6
    t3.setScale(.7f, .7f);
    t3.setPosition(50.f, -60.f);//(x, y)
    //______________page-9___________________
    Sprite t4(texture43);//trailer page 7
    t4.setScale(.7f, .7f);
    t4.setPosition(50.f, -60.f);//(x, y)
    //______________page-10___________________
    Sprite t5(texture44);//trailer page 8
    t5.setScale(.7f, .7f);
    t5.setPosition(50.f, -60.f);//(x, y)
    //______________page-11___________________
    Sprite t6(texture45);//trailer page 9
    t6.setScale(.7f, .7f);
    t6.setPosition(50.f, -60.f);//(x, y)
    //______________page-12___________________
    Sprite t7(texture46);//trailer page 10
    t7.setScale(.7f, .7f);
    t7.setPosition(50.f, -60.f);//(x, y)
    //______________page-13___________________
    Sprite t8(texture47);//trailer page 11
    t8.setScale(.7f, .7f);
    t8.setPosition(50.f, -60.f);//(x, y)
    //______________page-14___________________
    Sprite t9(texture48);//trailer page 12
    t9.setScale(.8f, .8f);
    t9.setPosition(150.f, -120.f);//(x, y)
    //______________page-15___________________
    Sprite t10(texture49);//trailer page 13
    t10.setScale(.8f, .8f);
    t10.setPosition(150.f, -120.f);//(x, y)
    //______________page-16___________________
    Sprite t11(texture50);//trailer page 14
    t11.setScale(.77f, .77f);
    t11.setPosition(160.f, -130.f);//(x, y)
    //______________page-17___________________
    Sprite t12(texture51);//trailer page 15
    t12.setScale(.6f, .6f);
    t12.setPosition(150.f, -120.f);//(x, y)
    //______________page-18___________________
    Sprite t13(texture52);//trailer page 16
    t13.setScale(.95f, .95f);
    t13.setPosition(170.f, -120.f);//(x, y)
    //______________page-19___________________
    Sprite t14(texture53);//trailer page 17
    t14.setScale(.85f, .85f);
    t14.setPosition(150.f, -180.f);//(x, y)
    //______________page-20___________________
    Sprite t15(texture54);//trailer page 18
    t15.setScale(.6f, .6f);
    t15.setPosition(150.f, 0.f);//(x, y)
    //______________page-21___________________
    Sprite t16(texture55);//trailer page 19
    t16.setScale(.8f, .8f);
    t16.setPosition(150.f, -290.f);//(x, y)
    //______________page-22___________________
    Sprite t17(texture56);//trailer page 20
    t17.setScale(.6f, .6f);
    t17.setPosition(150.f, 0.f);//(x, y)
    //______________page-23___________________
    Sprite t18(texture57);//trailer page 21
    t18.setScale(.6f, .6f);
    t18.setPosition(150.f, -0.f);//(x, y)
    //______________page-24___________________
    Sprite t19(texture58);//trailer page 22
    t19.setScale(.6f, .6f);
    t19.setPosition(150.f, 0.f);//(x, y)
    //______________page-25___________________
    Sprite t20(texture59);//trailer page 23
    t20.setScale(.6f, .6f);
    t20.setPosition(150.f, 0.f);//(x, y)
    //_______________page-26___________________
    //trailer last page(black)
    

  //___________________page 0___________________
    Sprite spritePage0(texture36);//menu page 1
    spritePage0.setScale(.625f, .625f);
    spritePage0.setPosition(0.f, -60.f);//(x, y)
    Sprite playNowBtn(texture37);//play now btn
    playNowBtn.setScale(.26f, .26f);
    playNowBtn.setPosition(155.f, 230.f);//(x, y)

  //___________________page 1___________________
    Sprite spritePage1(texture2);//forest
    spritePage1.setScale(.988f, .988f);
    spritePage1.setPosition(0.f, -200.f);//(x, y)
  //___________________page 2___________________
    Sprite spritePage2(texture3);//forest +rever
    spritePage2.setScale(.988f, .988f);
    spritePage2.setPosition(0.f, -180.f);//(x, y)
  //____________________page 3___________________
    Sprite spritePage3(texture4);//forest+robot
    spritePage3.setScale(.988f, .988f);
    spritePage3.setPosition(0.f, -200.f);//(x, y)
  //____________________page 4___________________
    Sprite spritePage4(texture5);//forest+cave enerence
    spritePage4.setScale(.988f, .988f);
    spritePage4.setPosition(0.f, -209.f);//(x, y)
    RectangleShape btn1(Vector2f(120.f, 60.f));//betton pressed my mouse to go to next page
    btn1.setFillColor(Color(0, 0, 0, 0));//invisible btn
    btn1.setPosition(790.f, 250.f);
    Sprite btnPage4(texture38);//    //btn texture for page 4
    btnPage4.setScale(.11f, .11f);
    btnPage4.setPosition(776.f, 230.f);//(x, y)
  //___________________page 5___________________
    Sprite spritePage5(texture6);//inside the cave 1
    spritePage5.setScale(.985f, .985f);
    spritePage5.setPosition(0.f, -300.f);//(x, y)
  //____________________page6_________________
  Sprite spritePage6(texture7);//inside the cave 2
    spritePage6.setScale(.985f, .985f);
    spritePage6.setPosition(0.f, -297.f);//(x, y)
   //_________________________page7___________________
   Sprite spritePage7(texture8);//inside the cave 3+outside
    spritePage7.setScale(.988f, .988f);
    spritePage7.setPosition(0.f, -209.f);//(x, y)
  //___________________page 8___________________
  Sprite sprite0(texture0);//house and cow
  sprite0.setScale(.8f, .8f);
  sprite0.setPosition(0.f, -2.f);//(x, y)

  Sprite sprite1(texture1),sprite2(texture1),sprite3(texture1);//grass
  sprite1.setScale(.7f, .7f);
  sprite1.setPosition(-25.f, 390.f);//(x, y)
  sprite2.setScale(.7f, .7f);
  sprite2.setPosition(328.f, 390.f);//(x, y)
  sprite3.setScale(.7f, .7f);
  sprite3.setPosition(631.f, 390.f);//(x, y)
  //___________________page 9___________________
  Sprite sprite9(texture9);//sahl
  sprite9.setScale(.8f, .8f);
  sprite9.setPosition(0.f, -7.f);//(x, y)
    //___________________page 10___________________
    Sprite sprite10(texture10);//sahl+sahara
    sprite10.setScale(.8f, .8f);
    sprite10.setPosition(0.f, -7.f);//(x, y)
    //___________________page 11___________________
    Sprite sprite11(texture11);//sahara+mountain
    sprite11.setScale(.8f, .8f);
    sprite11.setPosition(0.f, -7.f);//(x, y)
  Sprite sprite12(texture12),sprite13(texture12),sprite14(texture12);//sahara platform
  sprite12.setScale(.8f, .8f);
  sprite12.setPosition(-25.f, 370.f);//(x, y)
  sprite13.setScale(.8f, .8f);
  sprite13.setPosition(328.f, 370.f);//(x, y)
  sprite14.setScale(.8f, .8f);
  sprite14.setPosition(631.f, 370.f);//(x, y)
    //___________________page 12___________________
    Sprite sprite15(texture13);//sahara+desert
    sprite15.setScale(.99f, .99f);
    sprite15.setPosition(0.f, 0.f);//(x, y)
    //___________________page 13___________________
    Sprite sprite16(texture14);//sahara end +sahl
    sprite16.setScale(.8f, .8f);
    sprite16.setPosition(0.f, -6.f);//(x, y)
    //___________________page 14___________________
    Sprite sprite17(texture15);//sahl+destroyed city
    sprite17.setScale(.8f, .8f);
    sprite17.setPosition(0.f, -6.f);//(x, y)
    //___________________page 15___________________
    Sprite sprite18(texture16);//destroyed city enterence
    sprite18.setScale(.8f, .8f);
    sprite18.setPosition(0.f, -6.f);//(x, y)
    //_________________page16_____________________
    Sprite sprite19(texture18);//destroyed city inside1
    sprite19.setScale(.8f, .8f);
    sprite19.setPosition(0.f, -6.f);//(x, y)
  Sprite sprite20(texture17),sprite21(texture17),sprite22(texture17);//destroyed city platform
  sprite20.setScale(.8f, .8f);
  sprite20.setPosition(-25.f, 360.f);//(x, y)
  sprite21.setScale(.8f, .8f);
  sprite21.setPosition(328.f, 360.f);//(x, y)
  sprite22.setScale(.8f, .8f);
  sprite22.setPosition(631.f, 360.f);//(x, y)
  //___________________page 17___________________
    Sprite sprite23(texture19);//destroyed city inside2
    sprite23.setScale(.8f, .8f);
    sprite23.setPosition(0.f, -6.f);//(x, y)

    //last triller pages ______________:
    //______________page 18___________________
    Sprite lt1(texture63);//last trailer page 1
    lt1.setScale(.65f, .65f);
    lt1.setPosition(220.f, -120.f);//(x, y)
    //______________page 19___________________
    Sprite lt2(texture64);//last trailer page 2
    lt2.setScale(.75f, .75f);
    lt2.setPosition(220.f, -290.f);//(x, y)
    //___________page 20____________________
    //black page
    //______________page 21___________________
    Sprite lt3(texture65);//last trailer page 3
    lt3.setScale(.37f, .37f);
    lt3.setPosition(90.f, 0.f);//(x, y)
    //______________page 22___________________
    Sprite lt4(texture66);//last trailer page 4
    lt4.setScale(.37f, .37f);
    lt4.setPosition(90.f, 0.f);//(x, y)




    // ───── MAIN LOOP ─────
    while (window.isOpen()) {
        Event event;
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed)
                window.close();
        }

    // ________trailer section________
    if(triller_ones==0){
      trailerClock.restart();
       triller_ones=1;
    }

     //Handle trailer page transitions
    if(triller_ones==1 && currentpage >= -25){
         if(trailerClock.getElapsedTime().asSeconds() >= trailerPageDuration){
            currentpage = currentpage - 1;
            trailerClock.restart();

            
              if ((triller1Sound.getStatus() != Sound::Playing)&&(currentpage<=-5))
              {
                triller1Sound.play();
              }
            
            
            
            if(currentpage < -25){
             currentpage = 0;
             triller_ones=2; // finished trailer
          }
       }
    }
    //make the sound stop when currentpage=1
    if(currentpage==1){
        triller1Sound.stop();
    }

    //last trailer section
   if((currentpage >= 18)&&(activateCross==1)&&(currentpage<=24)){
        if(lastTrailerClock.getElapsedTime().asSeconds() >= lastTrailerPageDuration){
           currentpage = currentpage + 1;
           lastTrailerClock.restart();
           
           if(currentpage > 24){
              currentpage = 0;
           }
       }
    }
       

    //nature sound
    if (currentpage>=1 && currentpage<=10)
    {
        if (natureSound.getStatus() != Sound::Playing)
        {
            natureSound.play();
        }
    }else
        {
            natureSound.stop();
        }
    //deset sound
    if (currentpage>=11 && currentpage<=12)
    {
        if (desertWindSound.getStatus() != Sound::Playing)
        {
            desertWindSound.play();
        }
    }else
    {
        desertWindSound.stop();
    }

    if(currentpage>=18){
       if (triller2.getStatus() != Sound::Playing)
        {
            triller2.play();
        }
    }
    if (currentpage==1)
    {
        triller2.stop();
    }
    


        // ───── PLAYER INPUT ─────
        if (playerAlive) {// only allow input if player is alive
            velocity.x = 0;
    
                 if (movementLocked &&
                 movementLockClock.getElapsedTime().asSeconds() >= movementLockTime)
             {
                 movementLocked = false;
             }

            if (!movementLocked) {
               if (Keyboard::isKeyPressed(Keyboard::A)) {
                   velocity.x = -speed;
                   facing = -1;
                      if (runningSound.getStatus() != Sound::Playing) {
                          runningSound.play();
                      }
               }
               if (Keyboard::isKeyPressed(Keyboard::D)) {
                   velocity.x = speed;
                   facing = 1;
                   if (runningSound.getStatus() != Sound::Playing) {
                      runningSound.play();
                   }
               }
            } 
            //if there is no press on a or d key and player not Grounded
            if ((!Keyboard::isKeyPressed(Keyboard::A) && !Keyboard::isKeyPressed(Keyboard::D))|| (!isGrounded)||(rideCar==1)) {
                runningSound.stop();
            }

            if (Keyboard::isKeyPressed(Keyboard::W)
                && isGrounded
                && jumpClock.getElapsedTime().asSeconds() >= jumpCooldown) {//if there is press on w and player is on ground and jump cooldown passed

                velocity.y = jumpPower;//(jumpPower=-15) go up
                isGrounded = false;
                jumpClock.restart();// reset jump cooldown(start counting)
            }

            if ((Keyboard::isKeyPressed(Keyboard::K)
                && shootClock.getElapsedTime().asSeconds() >= shootCooldown)// if there is press on k and shoot cooldown passed
                && (isGrounded) ) {//if there is press on k and shoot cooldown passed and player is in the ground 
                 
                Bullet b;
                b.shape = RectangleShape(Vector2f(10, 5));// bullet size
                b.shape.setFillColor(Color::Yellow);
                b.shape.setPosition(
                    player.getPosition().x + (facing == 1 ? player.getSize().x + 80 : -60),// spawn at player's front
                    player.getPosition().y + 48// spawn at middle height
                );
                b.speed = bulletSpeed;// bullet speed=8
                b.direction = facing;// direction based on player facing
                b.fromPlayer = true;// shot by player
                bullets.push_back(b);// add bullet to list(vector)
                
                if (rideCar==0)
                {
                   gunSound.play();
                }
                 shootClock.restart();
                 movementLocked = true;
                 movementLockClock.restart();

            }
        }

        // ───── PLAYER PHYSICS ─────
        if (playerAlive) {
            velocity.y += gravity;// apply gravity
            
            player.move(velocity.x, 0);// move in x direction
            if (player.getGlobalBounds().intersects(ground.getGlobalBounds()))//if colliding with ground after moving in x direction
                player.move(-velocity.x, 0);// move back(no horizontal movement through ground)

            if (player.getGlobalBounds().intersects(sideWallLeft.getGlobalBounds()))//if colliding with left wall after moving in x direction
                player.move(-velocity.x, 0);// move back(no horizontal movement through wall)
            if (player.getGlobalBounds().intersects(sideWallRight.getGlobalBounds()))//if colliding with right wall after moving in x direction
                player.move(-velocity.x, 0);// move back(no horizontal movement through wall)

            player.move(0, velocity.y);// move in y direction

            if (player.getGlobalBounds().intersects(ground.getGlobalBounds())) {
                if (velocity.y > 0) {
                   player.setPosition(
                        player.getPosition().x,
                        ground.getPosition().y - player.getSize().y
                   );
                velocity.y = 0;

                   if (!isGrounded) { // JUST LANDED
                       justLanded = true;
                 landClock.restart();
                   }
            
                   isGrounded = true;
               }
            }
        }
        if (justLanded && landClock.getElapsedTime().asSeconds() >= landStandTime) {
                 justLanded = false;
         }


        // ───── ENEMY AI (DELAYED THINKING) ─────
        if (enemyAlive && playerAlive) {//if both enemy and player are alive

            // Think every few seconds
            if (enemyThinkClock.getElapsedTime().asSeconds() >= enemyThinkDelay) {//if thinking delay passed
                enemyDir = (player.getPosition().x < enemy.getPosition().x) ? -1 : 1;//go at same x as player
                enemyThinkClock.restart();// reset thinking clock(delay)
            }

            // Move using last decision
            enemy.move(enemySpeed * enemyDir, 0);

            // Enemy shooting
            if (enemyShootClock.getElapsedTime().asSeconds() >= enemyShootCooldown) {//if enemy shoot cooldown passed
                Bullet eb;
                eb.shape = RectangleShape(Vector2f(10, 5));// bullet size
                eb.shape.setFillColor(Color::Cyan);
                eb.shape.setPosition(enemy.getPosition().x, enemy.getPosition().y + 7);// spawn at middle height
                eb.speed = bulletSpeed - 2;
                eb.direction = enemyDir;
                eb.fromPlayer = false;// shot by enemy
                bullets.push_back(eb);// add bullet to list(vector)

                robotGunSound.play();

                enemyShootClock.restart();// reset enemy shoot cooldown(start counting)
                enemyIsWalking = 0;
            }
            else {
                enemyIsWalking = 1;
            }
        }
        // ───── ENEMY1 AI (DELAYED THINKING) ─────
        if (enemy1Alive && playerAlive) {//if both enemy and player are alive

            // Think every few seconds
            if (enemy1ThinkClock.getElapsedTime().asSeconds() >= enemy1ThinkDelay) {//if thinking delay passed
                enemy1Dir = (player.getPosition().x < enemy1.getPosition().x) ? -1 : 1;//go at same x as player
                enemy1ThinkClock.restart();// reset thinking clock(delay)
            }

            // Move using last decision
            enemy1.move(enemy1Speed * enemy1Dir, 0);

            // Enemy shooting
            if (enemy1ShootClock.getElapsedTime().asSeconds() >= enemy1ShootCooldown) {//if enemy shoot cooldown passed
                Bullet eb;
                eb.shape = RectangleShape(Vector2f(10, 5));// bullet size
                eb.shape.setFillColor(Color::Cyan);
                eb.shape.setPosition(enemy1.getPosition().x + 13, enemy1.getPosition().y + 20);// spawn at middle height
                eb.speed = bulletSpeed - 2;
                eb.direction = enemy1Dir;
                eb.fromPlayer = false;// shot by enemy
                bullets.push_back(eb);// add bullet to list(vector)

                robotGunSound.play();

                enemy1ShootClock.restart();// reset enemy shoot cooldown(start counting)
                enemy1IsWalking = 0;
            }
            else {
                enemy1IsWalking = 1;
            }
        }
        // ───── ENEMY2 AI (DELAYED THINKING) ─────
        if (enemy2Alive && playerAlive) {//if both enemy and player are alive

            // Think every few seconds
            if (enemy2ThinkClock.getElapsedTime().asSeconds() >= enemy2ThinkDelay) {//if thinking delay passed
                enemy2Dir = (player.getPosition().x < enemy2.getPosition().x) ? -1 : 1;//go at same x as player
                enemy2ThinkClock.restart();// reset thinking clock(delay)
            }

            // Move using last decision
            enemy2.move(enemy2Speed * enemy2Dir, 0);
            // Enemy shooting
       
        }
        // Calculate distance to player for enemy2
        destanceToPlayer = abs(enemy2.getPosition().x - player.getPosition().x);

        // ───── BULLETS & DAMAGE ─────
        for (size_t i = 0; i < bullets.size(); ++i) {//while going through all bullets
            bullets[i].shape.move(bullets[i].speed * bullets[i].direction, 0);

            // Player bullet → enemy
            if (enemyAlive && bullets[i].fromPlayer &&
                bullets[i].shape.getGlobalBounds().intersects(enemy.getGlobalBounds())) {//if enemy is alive and bullet is from player and colliding with enemy

                enemyHealth--;
                bullets.erase(bullets.begin() + i);
                --i;

                if (enemyHealth <= 0)
                    enemyAlive = false;
                continue;
            }
            // Player bullet → enemy1
            if (enemy1Alive && bullets[i].fromPlayer &&
                bullets[i].shape.getGlobalBounds().intersects(enemy1.getGlobalBounds())) {//if enemy is alive and bullet is from player and colliding with enemy

                enemy1Health--;
                bullets.erase(bullets.begin() + i);
                --i;

                if (enemy1Health <= 0)
                    enemy1Alive = false;
                continue;
            }
            // Player bullet → enemy2
            if (enemy2Alive && bullets[i].fromPlayer &&
                bullets[i].shape.getGlobalBounds().intersects(enemy2.getGlobalBounds())) {//if enemy is alive and bullet is from player and colliding with enemy

                enemy2Health--;
                bullets.erase(bullets.begin() + i);
                --i;

                if (enemy2Health <= 0)
                    enemy2Alive = false;
                continue;
            }
            // Enemy bullet → player
            if (playerAlive && !bullets[i].fromPlayer &&
                bullets[i].shape.getGlobalBounds().intersects(player.getGlobalBounds()) &&
                playerDamageClock.getElapsedTime().asSeconds() >= damageCooldown) {//if player is alive and bullet is from enemy and colliding with player and damage cooldown passed
                if(rideCar==0){
                playerHealth--;}
                playerDamageClock.restart();
                bullets.erase(bullets.begin() + i);
                --i;

                if (playerHealth <= 0)
                    playerAlive = false;
                continue;
            }

            if (bullets[i].shape.getPosition().x < 0 ||
                bullets[i].shape.getPosition().x > window.getSize().x) {//if bullet is out of window bounds
                bullets.erase(bullets.begin() + i);// remove bullet if out of bounds
                --i;
            }
        }
         // IF ENEMY SHOOT A BULLET AND THE BULLET TOUCH THE CAR THE CAR WILL TAKE DAMAGE
        for (size_t i = 0; i < bullets.size(); ++i) {//while going through all bullets
            // Enemy bullet → car
            if (carmoving==1 &&
                !bullets[i].fromPlayer &&
                bullets[i].shape.getGlobalBounds().intersects(car.getGlobalBounds())) {//if car is moving and bullet is from enemy and colliding with car
                bullets.erase(bullets.begin() + i);
                --i;
                cardamage=1;// car took damage 
                continue;
            }
            cardamage=0;
        }


        // ───── ENEMY TOUCH DAMAGE ─────
        if (enemyAlive && playerAlive &&
            enemy.getGlobalBounds().intersects(player.getGlobalBounds()) &&
            playerDamageClock.getElapsedTime().asSeconds() >= damageCooldown) {//if both enemy and player are alive and colliding and damage cooldown passed

            playerHealth--;
            playerDamageClock.restart();

            if (playerHealth <= 0)
                playerAlive = false;
        }

        // ───── ENEMY1 TOUCH DAMAGE ─────
        if (enemy1Alive && playerAlive &&
            enemy1.getGlobalBounds().intersects(player.getGlobalBounds()) &&
            playerDamageClock.getElapsedTime().asSeconds() >= damageCooldown) {//if both enemy and player are alive and colliding and damage cooldown passed

            playerHealth--;
            playerDamageClock.restart();

            if (playerHealth <= 0)
                playerAlive = false;
        }
        // ───── ENEMY2 TOUCH DAMAGE ─────
        if (enemy2Alive && playerAlive &&
            enemy2.getGlobalBounds().intersects(player.getGlobalBounds()) &&
            playerDamageClock.getElapsedTime().asSeconds() >= damageCooldown) {//if both enemy and player are alive and colliding and damage cooldown passed

            playerHealth--;
            playerDamageClock.restart();

            if (playerHealth <= 0)
                playerAlive = false;
        }
 
        //________if player is dead________
        if(playerAlive==false){
            enemy2Alive=false;
            enemy1Alive=false;
            enemyAlive=false;
            currentpage=currentpage-2;
            playerAlive=true;
            playerHealth=4;
        }
        //__________car_________

        // Car ride toggle with key release detection
        if ((currentpage >= 8 && currentpage <= 12) && currentpage != 13) {
            static bool rKeyPressed = false;
            // Check if player is close to car (within 100 pixels)
            float distanceToCar = abs(player.getPosition().x - car.getPosition().x);
            if (Keyboard::isKeyPressed(Keyboard::R) && !rKeyPressed && distanceToCar < 300.f &&(currentpage==carCoureentPage)) {
            rideCar = (rideCar == 0) ? 1 : 0;
            onec = 1;
            rKeyPressed = true;
            } else if (!Keyboard::isKeyPressed(Keyboard::R)) {
            rKeyPressed = false;
            }
        }
        if (currentpage == 13) {
            rideCar = 0;
        }
        // Car movement
        if (rideCar == 1) {
            int moveDir = 0;
            if (Keyboard::isKeyPressed(Keyboard::D)) moveDir = 1;
            else if (Keyboard::isKeyPressed(Keyboard::A)) moveDir = -1;
            
            if (moveDir != 0) {
            carmoving = 1;
            car.move(carSpeed * moveDir, 0);
            carSprite.move(carSpeed * moveDir, 0);
            } else {
            carmoving = 0;
            }
        } else {
            carmoving = 0;
        }
        if (rideCar==1) {
            player.setPosition(car.getPosition().x, player.getPosition().y);
        }
        if (rideCar == 1) {
            if (car.getGlobalBounds().intersects(sideWallLeft.getGlobalBounds())) {// this
            car.move(carSpeed, 0);
            carSprite.move(carSpeed, 0);
            }
            if (car.getGlobalBounds().intersects(sideWallRight.getGlobalBounds())) {
            car.move(carSpeed, 0);
            carSprite.move(carSpeed, 0);
            }
        }

        if(carmoving==0){
            carMovingSound.play();
        }


        //frame update:

        //standing frame update:
        if (playerAlive && !Keyboard::isKeyPressed(Keyboard::A) && !Keyboard::isKeyPressed(Keyboard::D)
             && !Keyboard::isKeyPressed(Keyboard::K)&&isGrounded) {        //if player is alive and there no press on a or d or w or k
             if (facing==1)
             {
                 playerSprite.setPosition(player.getPosition().x-80.f, player.getPosition().y-7.f);// sync with player position
                 playerSprite.setScale(0.194f, 0.194f);
             }
             else
             {
                 playerSprite.setScale(-0.194f, 0.194f);
                 playerSprite.setPosition(player.getPosition().x+123.f, player.getPosition().y-7.f);// sync with player position
             }
        }

        //running frames update:
        float dt = RunClock.restart().asSeconds();
        RunTimer += dt;
        if(playerAlive && Keyboard::isKeyPressed(Keyboard::D) && 
        !movementLocked)//u cant run while shooting
        {//if player is alive and there is press on  a or d
          if ((facing==1) && RunTimer >= RunFrameTime)
          {
            RunCurrentFrame++;

            if (RunCurrentFrame >= 7)
                RunCurrentFrame = 0;

            playerSpriteRun.setTexture(runTextures[RunCurrentFrame]);
            RunTimer = 0.f;
          }
          if (!facing==1)
          {
            RunCurrentFrame = 0;
            playerSpriteRun.setTexture(runTextures[RunCurrentFrame]);
          }

          playerSpriteRun.setPosition(
          player.getPosition().x + runOffsets[RunCurrentFrame].x,
          player.getPosition().y + runOffsets[RunCurrentFrame].y
         );
            playerSpriteRun.setScale(runScales[RunCurrentFrame].x, runScales[RunCurrentFrame].y);

        }
        if(playerAlive && Keyboard::isKeyPressed(Keyboard::A) &&
         !movementLocked)
        {//if player is alive and there is press on  a or d
          if ((facing==-1) && RunTimer >= RunFrameTime)
          {
            RunCurrentFrame++;

            if (RunCurrentFrame >= 7)
                RunCurrentFrame = 0;

            playerSpriteRun.setTexture(runTextures[RunCurrentFrame]);
            RunTimer = 0.f;
          }
          if (!facing==-1)
          {
            RunCurrentFrame = 0;
            playerSpriteRun.setTexture(runTextures[RunCurrentFrame]);
          }

          playerSpriteRun.setPosition(
          player.getPosition().x - (runOffsets[RunCurrentFrame].x-60.f),
          player.getPosition().y + runOffsets[RunCurrentFrame].y
         );
            playerSpriteRun.setScale(-runScales[RunCurrentFrame].x, runScales[RunCurrentFrame].y);
        }


        //ko(shooting) frames update:
        float dtKo = koClock.restart().asSeconds();
        koTimer += dtKo;
        if (playerAlive && Keyboard::isKeyPressed(Keyboard::K)
            && isGrounded && movementLocked) {//if player is alive and there is press on k and player is in the ground and shoot cooldown passed doing ko animation

            if (koTimer >= koFrameTime) {
                koCurrentFrame++;

                if (koCurrentFrame >= 2)
                    koCurrentFrame = 0;

                playerSpriteKo.setTexture(koTextures[koCurrentFrame]);
                koTimer = 0.f;
            }

            if (facing == 1) {
               playerSpriteKo.setPosition(
               player.getPosition().x + koOffsets[koCurrentFrame].x,
               player.getPosition().y + koOffsets[koCurrentFrame].y
               );               
                playerSpriteKo.setScale(koScales[koCurrentFrame].x, koScales[koCurrentFrame].y);
            } else {
                playerSpriteKo.setScale(-koScales[koCurrentFrame].x, koScales[koCurrentFrame].y);
                playerSpriteKo.setPosition(
                player.getPosition().x - (koOffsets[koCurrentFrame].x-60.f),
                player.getPosition().y + koOffsets[koCurrentFrame].y
                  );            
            }
        }

        //super jump frames update:
        float dtSuperJump = superJumpClock.restart().asSeconds();//time since last frame
        superJumpTimer += dtSuperJump;

        if (!isGrounded) {

            if (superJumpTimer >= superJumpFrameTime2) {
                superJumpCurrentFrame++;

                if (superJumpCurrentFrame >= 1)
                    superJumpCurrentFrame = 0;

                playerSpriteSuperJump.setTexture(superJumpTextures[superJumpCurrentFrame]);
                superJumpTimer = 0.f;
            }

            if (facing == 1) {
               playerSpriteSuperJump.setPosition(
               player.getPosition().x + superJumpOffsets[superJumpCurrentFrame].x,
               player.getPosition().y + superJumpOffsets[superJumpCurrentFrame].y
               );               
                playerSpriteSuperJump.setScale(superJumpScales[superJumpCurrentFrame].x, superJumpScales[superJumpCurrentFrame].y);
            } else {
                playerSpriteSuperJump.setScale(-superJumpScales[superJumpCurrentFrame].x, superJumpScales[superJumpCurrentFrame].y);
                playerSpriteSuperJump.setPosition(
                player.getPosition().x - (superJumpOffsets[superJumpCurrentFrame].x-60.f),
                player.getPosition().y + superJumpOffsets[superJumpCurrentFrame].y
                  );            
            }
        }

        //car movement:
        //standing frame update:
        if(carmoving==0){//if not riding or car not moving
                carSprite.setPosition(car.getPosition().x-80.f, car.getPosition().y-400.f);// sync with car position
                carSprite.setScale(2.2f, 2.2f);
        }

        //moving frame update:
        float carDeltaTime = carClock.restart().asSeconds();
        carTimer += carDeltaTime;

      if (carmoving==1) //if car is moving
        {
            if (carTimer >= carframeTime)
            {
                carCurrentFrame = (carCurrentFrame + 1) % FRAME_COUNT;
                carTimer = 0.f;
            }
        }
        else
        {
            carCurrentFrame = 0; // idle frame
        }

        // ───── Apply frame to sprite ─────
            carRideSprite.setTextureRect(IntRect(
            carCurrentFrame * FRAME_WIDTH,
            0,
            FRAME_WIDTH,
            FRAME_HEIGHT
        ));

                carRideSprite.setPosition(car.getPosition().x-80.f, car.getPosition().y-400.f);// sync with car position
                carRideSprite.setScale(2.2f, 2.2f);



        // ───── ENEMY ANIMATIONS ─────
        //enemy1
        //walking frame update:
        float enemy1DeltaTime = enemy1Clock.restart().asSeconds();
        enemy1Timer += enemy1DeltaTime;

          if (enemyIsWalking == 1) 
        {
            if (enemy1Timer >= enemy1frameTime)
            {
            enemy1CurrentFrame = (enemy1CurrentFrame + 1) % FRAME_COUNT1;
            enemy1Timer = 0.f;
            }
        }
        else
        {
            enemy1CurrentFrame = 0; // idle frame
        }

        // ───── Apply frame to sprite ─────
            enemy1SpriteWalk.setTextureRect(IntRect(
            enemy1CurrentFrame * FRAME_WIDTH1,
            0,
            FRAME_WIDTH1,
            FRAME_HEIGHT1
        ));
            
            // Face right or left based on enemy direction
            if (enemyDir == 1) {// facing right
                enemy1SpriteWalk.setScale(2.f, 2.f);
                enemy1SpriteWalk.setPosition(enemy.getPosition().x-111.f, enemy.getPosition().y-100.f);
            } else {
                enemy1SpriteWalk.setScale(-2.f, 2.f);
                enemy1SpriteWalk.setPosition(enemy.getPosition().x+150.f , enemy.getPosition().y-100.f);// sync with enemy position
            }



        //enemy2
        //walking frame update:
        float enemy2DeltaTime = enemy2Clock.restart().asSeconds();
        enemy2Timer += enemy2DeltaTime;

          if (enemyIsWalking == 1) 
        {
            if (enemy2Timer >= enemy2frameTime)
            {
            enemy2CurrentFrame = (enemy2CurrentFrame + 1) % FRAME_COUNT2;
            enemy2Timer = 0.f;
            }
        }
        else
        {
            enemy2CurrentFrame = 0; // idle frame
        }

        // ───── Apply frame to sprite ─────
            enemy2SpriteWalk.setTextureRect(IntRect(
            enemy2CurrentFrame * FRAME_WIDTH2,
            0,
            FRAME_WIDTH2,
            FRAME_HEIGHT2
        ));
            
            // Face right or left based on enemy direction
            if (enemy1Dir == 1) {// facing right
                enemy2SpriteWalk.setScale(2.f, 2.f);
                enemy2SpriteWalk.setPosition(enemy1.getPosition().x-111.f, enemy1.getPosition().y-100.f);
            } else {
                enemy2SpriteWalk.setScale(-2.f, 2.f);
                enemy2SpriteWalk.setPosition(enemy1.getPosition().x+150.f , enemy1.getPosition().y-100.f);// sync with enemy position
            }




        //enemy3
        //walking frame update:
        float enemy3DeltaTime = enemy3Clock.restart().asSeconds();
        enemy3Timer += enemy3DeltaTime;

          if (enemyIsWalking == 1) 
        {
            if (enemy3Timer >= enemy3frameTime)
            {
            enemy3CurrentFrame = (enemy3CurrentFrame + 1) % FRAME_COUNT3;
            enemy3Timer = 0.f;
            }
        }
        else
        {
            enemy3CurrentFrame = 0; // idle frame
        }

        // ───── Apply frame to sprite ─────
            enemy3SpriteWalk.setTextureRect(IntRect(
            enemy3CurrentFrame * FRAME_WIDTH3,
            0,
            FRAME_WIDTH3,
            FRAME_HEIGHT3
        ));
            
            // Face right or left based on enemy direction
            if (enemy2Dir == 1) {// facing right
                enemy3SpriteWalk.setScale(2.f, 2.f);
                enemy3SpriteWalk.setPosition(enemy2.getPosition().x-111.f, enemy2.getPosition().y-120.f);
            } else {
                enemy3SpriteWalk.setScale(-2.f, 2.f);
                enemy3SpriteWalk.setPosition(enemy2.getPosition().x+150.f , enemy2.getPosition().y-120.f);// sync with enemy position
            }

        //enemy3 shooting frame update:
        float enemy3DeltaTime_2 = enemy3Clock_2.restart().asSeconds();
        enemy3Timer_2 += enemy3DeltaTime_2;

          if (enemyIsWalking == 1) 
        {
            if (enemy3Timer_2 >= enemy3frameTime_2)
            {
            enemy3CurrentFrame_2 = (enemy3CurrentFrame_2 + 1) % FRAME_COUNT3_2;
            enemy3Timer_2 = 0.f;
            }
        }
        else
        {
            enemy3CurrentFrame_2 = 0; // idle frame
        }

        // ───── Apply frame to sprite ─────
            enemy3SpriteShoot.setTextureRect(IntRect(
            enemy3CurrentFrame_2 * FRAME_WIDTH3_2,
            0,
            FRAME_WIDTH3_2,
            FRAME_HEIGHT3_2
        ));
            
            // Face right or left based on enemy direction
            if (enemy2Dir == 1) {// facing right
                enemy3SpriteShoot.setScale(2.f, 2.f);
                enemy3SpriteShoot.setPosition(enemy2.getPosition().x-111.f, enemy2.getPosition().y-120.f);
            } else {
                enemy3SpriteShoot.setScale(-2.f, 2.f);
                enemy3SpriteShoot.setPosition(enemy2.getPosition().x+150.f , enemy2.getPosition().y-120.f);// sync with enemy position
            }



        //________move bettwen pages________
        if (currentpage==0)
        {
            //if there is a press on playNowBtn go to page 1
            if (Mouse::isButtonPressed(Mouse::Left)) {
                Vector2i mousePos = Mouse::getPosition(window);
                if (playNowBtn.getGlobalBounds().contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y))) {
                    enemyAlive=false;   
                    currentpage=1;//go to page 1
                    player.setPosition(15.f, player.getPosition().y);//spawn at left edge
                }
            }
        }
        
        if(currentpage==1){
            if(player.getPosition().x>950){//if player passed right edge
                enemyAlive=false;
                currentpage=2;//go to page 2
                player.setPosition(15.f, player.getPosition().y);//spawn at left edge
            }
        }
        if(currentpage==2){
            if(player.getPosition().x<10){//if player passed right edge
                enemyAlive=false;
                currentpage=1;//go to page 1
                player.setPosition(900.f, player.getPosition().y);//spawn at left edge
            }
            if(player.getPosition().x>950){//if player passed right edge
                enemy2Alive=true;  
                enemy2Health=5; 
                enemy2.setPosition(550.f, enemy2.getPosition().y);
                currentpage=3;//go to page 3
                player.setPosition(15.f, player.getPosition().y);//spawn at left edge
            }
        }
        if(currentpage==3){
            if(player.getPosition().x<10){//if player passed right edge
                enemyAlive=false;
                currentpage=2;//go to page 2
                player.setPosition(900.f, player.getPosition().y);//spawn at left edge
            }
            if(player.getPosition().x>950){//if player passed right edge
                enemy2Alive=false;   
                currentpage=4;//go to page 4
                player.setPosition(15.f, player.getPosition().y);//spawn at left edge
            }
        }
        if (currentpage==4)
        {
            if(player.getPosition().x<10){//if player passed right edge
                enemyAlive=false;
                currentpage=3;//go to page 3
                player.setPosition(900.f, player.getPosition().y);//spawn at left edge
            }
            if (Mouse::isButtonPressed(Mouse::Left)) {
                Vector2i mousePos = Mouse::getPosition(window);
                if (btn1.getGlobalBounds().contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y))) {
                    enemyAlive=false;   
                    currentpage=5;//go to page 5
                    player.setPosition(15.f, player.getPosition().y);//spawn at left edge
                }
            }
        }
        if(currentpage==5){
            if(player.getPosition().x>950){//if player passed right edge
                enemyAlive=true;
                enemyHealth=7;
                playerHealth=4;   
                 enemy.setPosition(800.f, enemy.getPosition().y);
                currentpage=6;//go to page 6
                player.setPosition(15.f, player.getPosition().y);//spawn at left edge
            }
        }
        if(currentpage==6){
            if(player.getPosition().x<10){//if player passed right edge
                enemyAlive=false;
                currentpage=5;//go to page 5
                player.setPosition(900.f, player.getPosition().y);//spawn at left edge
            }
            if(player.getPosition().x>950){//if player passed right edge
                enemyAlive=false;   
                currentpage=7;//go to page 7
                player.setPosition(120.f, player.getPosition().y);//spawn at left edge
            }  
        }
        if (currentpage==7)
        {
            if(player.getPosition().x<100){//if player passed right edge
                enemyAlive=false;
                currentpage=6;//go to page 6
                player.setPosition(850.f, player.getPosition().y);//spawn at left edge
            }
            if(player.getPosition().x>850){//if player passed right edge
                enemyAlive=false;   
                currentpage=8;//go to page 8
                player.setPosition(100.f, player.getPosition().y);//spawn at left edge
            }   
        }
        if (currentpage==8)
        {
            if(player.getPosition().x>950){//if player passed right edge
                enemyAlive=false; 
                currentpage=9;//go to page 9
                player.setPosition(50.f, player.getPosition().y);//spawn at left edge
            }

        }
        if(currentpage==9){
            if(player.getPosition().x<10){
            enemyAlive=false;
            if (rideCar==0)
            {
            currentpage=8;
            }
            player.setPosition(900.f, player.getPosition().y);
            }
            if(player.getPosition().x>950){
            enemyAlive=false; 
            if(rideCar==0)
            {
            currentpage=10;
            }
            player.setPosition(100.f, player.getPosition().y);
            }
            if(car.getPosition().x>950){
                carCoureentPage=10;
                currentpage=10;
            car.setPosition(0.f, car.getPosition().y);
            carSprite.setPosition(0.f-80.f, carSprite.getPosition().y);
            }
        }
        if(currentpage==10){
            if(player.getPosition().x<10){
            enemyAlive=false;
            if(rideCar==0)
            {
            currentpage=9;
            }
            player.setPosition(850.f, player.getPosition().y);
            }
            if(player.getPosition().x>950){
            enemyAlive=false;  
            if(rideCar==0)
            {
            currentpage=11;
            } 
            player.setPosition(100.f, player.getPosition().y);
            }
            if(car.getPosition().x>950){
                carCoureentPage=11;
                currentpage=11;
            car.setPosition(0.f, car.getPosition().y);
            carSprite.setPosition(0.f - 80.f, carSprite.getPosition().y);
            }
        }
        if (currentpage==11){
            if(player.getPosition().x<10){
            enemyAlive=false;
            if(rideCar==0){
            currentpage=10;
         }
            player.setPosition(850.f, player.getPosition().y);
            }
            if(player.getPosition().x>950){
            enemyAlive=false;  
            if(rideCar==0){ 
            currentpage=12;
           }
            player.setPosition(100.f, player.getPosition().y);
            }
            if(car.getPosition().x>950){
                carCoureentPage=12;
                currentpage=12;
            car.setPosition(0.f, car.getPosition().y);
            carSprite.setPosition(0.f - 80.f, carSprite.getPosition().y);
            }
        }
        if (currentpage==12){
            if(player.getPosition().x<10){
            enemyAlive=false;
            if(rideCar==0){
            currentpage=11;
            }
            player.setPosition(850.f, player.getPosition().y);
            }
            if(player.getPosition().x>950){
            enemyAlive=false; 
            if(rideCar==0){  
            currentpage=13;
            }
            player.setPosition(100.f, player.getPosition().y);
            }
            if(car.getPosition().x>950){
                carCoureentPage=13;
                currentpage=13;
            car.setPosition(100.f, car.getPosition().y);
            carSprite.setPosition(100.f - 80.f, carSprite.getPosition().y);
            }
        }
        if(currentpage==13){
            if(player.getPosition().x<10){//if player passed right edge
                enemyAlive=false;
                currentpage=12;//go to page 12
                player.setPosition(850.f, player.getPosition().y);//spawn at left edge
            }
            if(player.getPosition().x>950){//if player passed right edge
                enemy1Alive=true;
                enemy1.setPosition(800.f, enemy1.getPosition().y);
                enemy1Health=7;  
                playerHealth=4; 
                currentpage=14;//go to page 14
                player.setPosition(100.f, player.getPosition().y);//spawn at left edge
            }
        }
        if (currentpage==14)
        {
            if(player.getPosition().x<10){//if player passed right edge
                enemy1Alive=false;
                currentpage=13;//go to page 13
                player.setPosition(850.f, player.getPosition().y);//spawn at left edge
            }
            if(player.getPosition().x>950){//if player passed right edge
                enemyAlive=true;
                enemyHealth=3;
                enemy1Alive=true;
                enemy1Health=4;  
                enemy.setPosition(800.f, enemy.getPosition().y);   
                enemy1.setPosition(450.f, enemy1.getPosition().y);
                playerHealth=6;
                currentpage=15;//go to page 15
                player.setPosition(100.f, player.getPosition().y);//spawn at left edge
            }
        }
        if(currentpage==15){
            if(player.getPosition().x<10){//if player passed right edge
                enemyAlive=false;
                currentpage=14;//go to page 14
                player.setPosition(850.f, player.getPosition().y);//spawn at left edge
            }
            if(player.getPosition().x>950){//if player passed right edge
                enemyAlive=false;
                enemy1Alive=false;   
                currentpage=16;//go to page 16
                player.setPosition(100.f, player.getPosition().y);//spawn at left edge
            }
        }
        if (currentpage==16)
        {
            if(player.getPosition().x<10){//if player passed right edge
                enemyAlive=false;
                currentpage=15;//go to page 15
                player.setPosition(850.f, player.getPosition().y);//spawn at left edge
            }
            if(player.getPosition().x>950){//if player passed right edge
                enemy2Alive=true;  
                enemy2Health=13;
                playerHealth=6; 
                currentpage=17;//go to page 17
                player.setPosition(100.f, player.getPosition().y);//spawn at left edge
            }
        }
        if(currentpage==17){
            if(player.getPosition().x<10){//if player passed right edge
                enemy2Alive=false;
                currentpage=16;//go to page 16
                player.setPosition(850.f, player.getPosition().y);//spawn at left edge
            }
            if(player.getPosition().x>950){//if player passed right edge
                enemy2Alive=false;
                enemy1Alive=false;
                enemyAlive=false;
                activateCross=1;
                currentpage=18;//go to page 18
                player.setPosition(500.f, player.getPosition().y);//spawn at left edge

            }
        }
        
        
        // ───── DRAW ─────
        window.clear();
        if (currentpage==8)
        {
        window.draw(sprite0);
        window.draw(sprite1);
        window.draw(sprite2);
        window.draw(sprite3);
        if (currentpage==carCoureentPage)
        {
        window.draw(car);
        window.draw(carSprite);
        }
        if (rideCar==0){
            if (playerAlive&& isGrounded&& !Keyboard::isKeyPressed(Keyboard::A) && !Keyboard::isKeyPressed(Keyboard::D) && !Keyboard::isKeyPressed(Keyboard::K) ) {//standing frame
                 window.draw(playerSprite);
                }
            if((playerAlive && Keyboard::isKeyPressed(Keyboard::D) && isGrounded&& !movementLocked) || (playerAlive && Keyboard::isKeyPressed(Keyboard::A)&& isGrounded && !movementLocked)) {//running frames
                window.draw(playerSpriteRun);
            }
            if (playerAlive && Keyboard::isKeyPressed(Keyboard::K)
                && (isGrounded)&& movementLocked) {//ko(shooting) frames
                window.draw(playerSpriteKo);
            }
            if (!isGrounded) {
                window.draw(playerSpriteSuperJump);//super jump frames
            }            
            for (auto& b : bullets) window.draw(b.shape);// draw all bullets
        }
        }
        if (currentpage==1)
        {
            window.draw(spritePage1);

            if (playerAlive&& isGrounded&& !Keyboard::isKeyPressed(Keyboard::A) && !Keyboard::isKeyPressed(Keyboard::D) && !Keyboard::isKeyPressed(Keyboard::K) ) {//standing frame
                 window.draw(playerSprite);
                }
            if((playerAlive && Keyboard::isKeyPressed(Keyboard::D) && isGrounded&& !movementLocked) || (playerAlive && Keyboard::isKeyPressed(Keyboard::A)&& isGrounded && !movementLocked)) {//running frames
                window.draw(playerSpriteRun);
            }
            if (playerAlive && Keyboard::isKeyPressed(Keyboard::K)
                && (isGrounded)&& movementLocked) {//ko(shooting) frames
                window.draw(playerSpriteKo);
            }
            if (!isGrounded) {
                window.draw(playerSpriteSuperJump);//super jump frames
            }

            for (auto& b : bullets) window.draw(b.shape);// draw all bullets
        }
        if (currentpage==2)
        {
            window.draw(spritePage2);

             if (playerAlive&& isGrounded&& !Keyboard::isKeyPressed(Keyboard::A) && !Keyboard::isKeyPressed(Keyboard::D) && !Keyboard::isKeyPressed(Keyboard::K) ) {//standing frame
                 window.draw(playerSprite);
                }
            if((playerAlive && Keyboard::isKeyPressed(Keyboard::D) && isGrounded&& !movementLocked) || (playerAlive && Keyboard::isKeyPressed(Keyboard::A)&& isGrounded && !movementLocked)) {//running frames
                window.draw(playerSpriteRun);
            }
            if (playerAlive && Keyboard::isKeyPressed(Keyboard::K)
                && (isGrounded)&& movementLocked) {//ko(shooting) frames
                window.draw(playerSpriteKo);
            }
            if (!isGrounded) {
                window.draw(playerSpriteSuperJump);//super jump frames
            }

            for (auto& b : bullets) window.draw(b.shape);// draw all bullets
        }
        if( currentpage==3)
        {
            window.draw(spritePage3);
            
            if (playerAlive&& isGrounded&& !Keyboard::isKeyPressed(Keyboard::A) && !Keyboard::isKeyPressed(Keyboard::D) && !Keyboard::isKeyPressed(Keyboard::K) ) {//standing frame
                 window.draw(playerSprite);
                }
            if((playerAlive && Keyboard::isKeyPressed(Keyboard::D) && isGrounded&& !movementLocked) || (playerAlive && Keyboard::isKeyPressed(Keyboard::A)&& isGrounded && !movementLocked)) {//running frames
                window.draw(playerSpriteRun);
            }
            if (playerAlive && Keyboard::isKeyPressed(Keyboard::K)
                && (isGrounded)&& movementLocked) {//ko(shooting) frames
                window.draw(playerSpriteKo);
            }
            if (!isGrounded) {
                window.draw(playerSpriteSuperJump);//super jump frames
            }          
            if ((enemy2Alive && enemy2IsWalking==1 && destanceToPlayer>100)) { window.draw(enemy3SpriteWalk);}else if ((enemy2Alive && destanceToPlayer<100)) { window.draw(enemy3SpriteShoot);}
            //if (enemyAlive && enemyIsWalking==0) { window.draw(enemy1SpriteShoot);}
            for (auto& b : bullets) window.draw(b.shape);// draw all bullets
        }
        if( currentpage==4)
        {
            window.draw(spritePage4);
            window.draw(btnPage4);
            if (playerAlive&& isGrounded&& !Keyboard::isKeyPressed(Keyboard::A) && !Keyboard::isKeyPressed(Keyboard::D) && !Keyboard::isKeyPressed(Keyboard::K) ) {//standing frame
                 window.draw(playerSprite);
                }
            if((playerAlive && Keyboard::isKeyPressed(Keyboard::D) && isGrounded&& !movementLocked) || (playerAlive && Keyboard::isKeyPressed(Keyboard::A)&& isGrounded && !movementLocked)) {//running frames
                window.draw(playerSpriteRun);
            }
            if (playerAlive && Keyboard::isKeyPressed(Keyboard::K)
                && (isGrounded)&& movementLocked) {//ko(shooting) frames
                window.draw(playerSpriteKo);
            }
            if (!isGrounded) {
                window.draw(playerSpriteSuperJump);//super jump frames
            }
            for (auto& b : bullets) window.draw(b.shape);// draw all bullets
            window.draw(btn1);
        }
        if( currentpage==5)
        {
            window.draw(spritePage5);
            if (playerAlive&& isGrounded&& !Keyboard::isKeyPressed(Keyboard::A) && !Keyboard::isKeyPressed(Keyboard::D) && !Keyboard::isKeyPressed(Keyboard::K) ) {//standing frame
                 window.draw(playerSprite);
                }
            if((playerAlive && Keyboard::isKeyPressed(Keyboard::D) && isGrounded&& !movementLocked) || (playerAlive && Keyboard::isKeyPressed(Keyboard::A)&& isGrounded && !movementLocked)) {//running frames
                window.draw(playerSpriteRun);
            }
            if (playerAlive && Keyboard::isKeyPressed(Keyboard::K)
                && (isGrounded)&& movementLocked) {//ko(shooting) frames
                window.draw(playerSpriteKo);
            }
            if (!isGrounded) {
                window.draw(playerSpriteSuperJump);//super jump frames
            }        
            for (auto& b : bullets) window.draw(b.shape);// draw all bullets
        }
        if(currentpage==6)
        {
            window.draw(spritePage6);
            if (playerAlive&& isGrounded&& !Keyboard::isKeyPressed(Keyboard::A) && !Keyboard::isKeyPressed(Keyboard::D) && !Keyboard::isKeyPressed(Keyboard::K) ) {//standing frame
                 window.draw(playerSprite);
                }
            if((playerAlive && Keyboard::isKeyPressed(Keyboard::D) && isGrounded&& !movementLocked) || (playerAlive && Keyboard::isKeyPressed(Keyboard::A)&& isGrounded && !movementLocked)) {//running frames
                window.draw(playerSpriteRun);
            }
            if (playerAlive && Keyboard::isKeyPressed(Keyboard::K)
                && (isGrounded)&& movementLocked) {//ko(shooting) frames
                window.draw(playerSpriteKo);
            }
            if (!isGrounded) {
                window.draw(playerSpriteSuperJump);//super jump frames
            }
            if ((enemyAlive && enemyIsWalking==1)||(enemyAlive && enemyIsWalking==0)) { window.draw(enemy1SpriteWalk);}
            for (auto& b : bullets) window.draw(b.shape);// draw all bullets
        }
        if(currentpage==7)
        {
            window.draw(spritePage7);
            if (playerAlive&& isGrounded&& !Keyboard::isKeyPressed(Keyboard::A) && !Keyboard::isKeyPressed(Keyboard::D) && !Keyboard::isKeyPressed(Keyboard::K) ) {//standing frame
                 window.draw(playerSprite);
                }
            if((playerAlive && Keyboard::isKeyPressed(Keyboard::D) && isGrounded&& !movementLocked) || (playerAlive && Keyboard::isKeyPressed(Keyboard::A)&& isGrounded && !movementLocked)) {//running frames
                window.draw(playerSpriteRun);
            }
            if (playerAlive && Keyboard::isKeyPressed(Keyboard::K)
                && (isGrounded)&& movementLocked) {//ko(shooting) frames
                window.draw(playerSpriteKo);
            }
            if (!isGrounded) {
                window.draw(playerSpriteSuperJump);//super jump frames
            }  
            for (auto& b : bullets) window.draw(b.shape);// draw all bullets
        }
        if (currentpage==9)
        {
            window.draw(sprite9);
            window.draw(sprite1);
            window.draw(sprite2);
            window.draw(sprite3);
            if (rideCar==0 && onec==0) {window.draw(pressR);}
            if (currentpage==carCoureentPage)
            {
            if (carmoving==0) {window.draw(carSprite);}
            if (carmoving==1){window.draw(carRideSprite);}
            }
        if (rideCar==0){
            if (playerAlive&& isGrounded&& !Keyboard::isKeyPressed(Keyboard::A) && !Keyboard::isKeyPressed(Keyboard::D) && !Keyboard::isKeyPressed(Keyboard::K) ) {//standing frame
                 window.draw(playerSprite);
                }
            if((playerAlive && Keyboard::isKeyPressed(Keyboard::D) && isGrounded&& !movementLocked) || (playerAlive && Keyboard::isKeyPressed(Keyboard::A)&& isGrounded && !movementLocked)) {//running frames
                window.draw(playerSpriteRun);
            }
            if (playerAlive && Keyboard::isKeyPressed(Keyboard::K)
                && (isGrounded)&& movementLocked) {//ko(shooting) frames
                window.draw(playerSpriteKo);
            }
            if (!isGrounded) {
                window.draw(playerSpriteSuperJump);//super jump frames
            }            
            for (auto& b : bullets) window.draw(b.shape);// draw all bullets
        }

        }
        if(currentpage==10)
        {
            window.draw(sprite10);
            window.draw(sprite1);
            window.draw(sprite2);
            window.draw(sprite3);
            if (currentpage==carCoureentPage)
            {
            if (carmoving==0) {window.draw(carSprite);}
            if (carmoving==1){window.draw(carRideSprite);}
            }
        if (rideCar==0){
            if (playerAlive&& isGrounded&& !Keyboard::isKeyPressed(Keyboard::A) && !Keyboard::isKeyPressed(Keyboard::D) && !Keyboard::isKeyPressed(Keyboard::K) ) {//standing frame
                 window.draw(playerSprite);
                }
            if((playerAlive && Keyboard::isKeyPressed(Keyboard::D) && isGrounded&& !movementLocked) || (playerAlive && Keyboard::isKeyPressed(Keyboard::A)&& isGrounded && !movementLocked)) {//running frames
                window.draw(playerSpriteRun);
            }
            if (playerAlive && Keyboard::isKeyPressed(Keyboard::K)
                && (isGrounded)&& movementLocked) {//ko(shooting) frames
                window.draw(playerSpriteKo);
            }
            if (!isGrounded) {
                window.draw(playerSpriteSuperJump);//super jump frames
            }            
            for (auto& b : bullets) window.draw(b.shape);// draw all bullets
        }
        }
        if(currentpage==11)
        {
            window.draw(sprite11);
            window.draw(sprite12);
            window.draw(sprite13);
            window.draw(sprite14);
            if (currentpage==carCoureentPage)
            {
            if (carmoving==0) {window.draw(carSprite);}
            if (carmoving==1){window.draw(carRideSprite);}
            }
        if (rideCar==0){
            if (playerAlive&& isGrounded&& !Keyboard::isKeyPressed(Keyboard::A) && !Keyboard::isKeyPressed(Keyboard::D) && !Keyboard::isKeyPressed(Keyboard::K) ) {//standing frame
                 window.draw(playerSprite);
                }
            if((playerAlive && Keyboard::isKeyPressed(Keyboard::D) && isGrounded&& !movementLocked) || (playerAlive && Keyboard::isKeyPressed(Keyboard::A)&& isGrounded && !movementLocked)) {//running frames
                window.draw(playerSpriteRun);
            }
            if (playerAlive && Keyboard::isKeyPressed(Keyboard::K)
                && (isGrounded)&& movementLocked) {//ko(shooting) frames
                window.draw(playerSpriteKo);
            }
            if (!isGrounded) {
                window.draw(playerSpriteSuperJump);//super jump frames
            }            
            for (auto& b : bullets) window.draw(b.shape);// draw all bullets
        }
        }
        if (currentpage==12)
        {
            window.draw(sprite15);
            window.draw(sprite12);
            window.draw(sprite13);
            window.draw(sprite14);
            if (currentpage==carCoureentPage)
            {
            if (carmoving==0) {window.draw(carSprite);}
            if (carmoving==1){window.draw(carRideSprite);}
            }
        if (rideCar==0){
            if (playerAlive&& isGrounded&& !Keyboard::isKeyPressed(Keyboard::A) && !Keyboard::isKeyPressed(Keyboard::D) && !Keyboard::isKeyPressed(Keyboard::K) ) {//standing frame
                 window.draw(playerSprite);
                }
            if((playerAlive && Keyboard::isKeyPressed(Keyboard::D) && isGrounded&& !movementLocked) || (playerAlive && Keyboard::isKeyPressed(Keyboard::A)&& isGrounded && !movementLocked)) {//running frames
                window.draw(playerSpriteRun);
            }
            if (playerAlive && Keyboard::isKeyPressed(Keyboard::K)
                && (isGrounded)&& movementLocked) {//ko(shooting) frames
                window.draw(playerSpriteKo);
            }
            if (!isGrounded) {
                window.draw(playerSpriteSuperJump);//super jump frames
            }            
            for (auto& b : bullets) window.draw(b.shape);// draw all bullets
        }
        }
        if(currentpage==13)
        {
            window.draw(sprite16);
            window.draw(sprite12);
            window.draw(sprite2);
            window.draw(sprite3);
            if (currentpage==carCoureentPage)
            {
            if (carmoving==0) {window.draw(carSprite);}
            if (carmoving==1){window.draw(carRideSprite);}
            }
        if (rideCar==0){
            if (playerAlive&& isGrounded&& !Keyboard::isKeyPressed(Keyboard::A) && !Keyboard::isKeyPressed(Keyboard::D) && !Keyboard::isKeyPressed(Keyboard::K) ) {//standing frame
                 window.draw(playerSprite);
                }
            if((playerAlive && Keyboard::isKeyPressed(Keyboard::D) && isGrounded&& !movementLocked) || (playerAlive && Keyboard::isKeyPressed(Keyboard::A)&& isGrounded && !movementLocked)) {//running frames
                window.draw(playerSpriteRun);
            }
            if (playerAlive && Keyboard::isKeyPressed(Keyboard::K)
                && (isGrounded)&& movementLocked) {//ko(shooting) frames
                window.draw(playerSpriteKo);
            }
            if (!isGrounded) {
                window.draw(playerSpriteSuperJump);//super jump frames
            }            
            for (auto& b : bullets) window.draw(b.shape);// draw all bullets
        }
        }
        if(currentpage==14)
        {
            window.draw(sprite17);
            window.draw(sprite1);
            window.draw(sprite2);
            window.draw(sprite3);
            if (playerAlive&& isGrounded&& !Keyboard::isKeyPressed(Keyboard::A) && !Keyboard::isKeyPressed(Keyboard::D) && !Keyboard::isKeyPressed(Keyboard::K) ) {//standing frame
                 window.draw(playerSprite);
                }
            if((playerAlive && Keyboard::isKeyPressed(Keyboard::D) && isGrounded&& !movementLocked) || (playerAlive && Keyboard::isKeyPressed(Keyboard::A)&& isGrounded && !movementLocked)) {//running frames
                window.draw(playerSpriteRun);
            }
            if (playerAlive && Keyboard::isKeyPressed(Keyboard::K)
                && (isGrounded)&& movementLocked) {//ko(shooting) frames
                window.draw(playerSpriteKo);
            }
            if (!isGrounded) {
                window.draw(playerSpriteSuperJump);//super jump frames
            }     
            if ((enemy1Alive && enemy1IsWalking==1)||(enemy1Alive && enemy1IsWalking==0)) { window.draw(enemy2SpriteWalk);}       
            for (auto& b : bullets) window.draw(b.shape);// draw all bullets
        }
        if(currentpage==15)
        {
            window.draw(sprite18);
            window.draw(sprite1);
            window.draw(sprite2);
            window.draw(sprite3);
            if (playerAlive&& isGrounded&& !Keyboard::isKeyPressed(Keyboard::A) && !Keyboard::isKeyPressed(Keyboard::D) && !Keyboard::isKeyPressed(Keyboard::K) ) {//standing frame
                 window.draw(playerSprite);
                }
            if((playerAlive && Keyboard::isKeyPressed(Keyboard::D) && isGrounded&& !movementLocked) || (playerAlive && Keyboard::isKeyPressed(Keyboard::A)&& isGrounded && !movementLocked)) {//running frames
                window.draw(playerSpriteRun);
            }
            if (playerAlive && Keyboard::isKeyPressed(Keyboard::K)
                && (isGrounded)&& movementLocked) {//ko(shooting) frames
                window.draw(playerSpriteKo);
            }
            if (!isGrounded) {
                window.draw(playerSpriteSuperJump);//super jump frames
            }  
            if ((enemy1Alive && enemy1IsWalking==1)||(enemy1Alive && enemy1IsWalking==0)) { window.draw(enemy2SpriteWalk);}       
            if ((enemyAlive && enemyIsWalking==1)||(enemyAlive && enemyIsWalking==0)) { window.draw(enemy1SpriteWalk);}
            for (auto& b : bullets) window.draw(b.shape);// draw all bullets
        }
        if(currentpage==16)
        {
            window.draw(sprite19);
            window.draw(sprite20);
            window.draw(sprite21);
            window.draw(sprite22);
            if (playerAlive&& isGrounded&& !Keyboard::isKeyPressed(Keyboard::A) && !Keyboard::isKeyPressed(Keyboard::D) && !Keyboard::isKeyPressed(Keyboard::K) ) {//standing frame
                 window.draw(playerSprite);
                }
            if((playerAlive && Keyboard::isKeyPressed(Keyboard::D) && isGrounded&& !movementLocked) || (playerAlive && Keyboard::isKeyPressed(Keyboard::A)&& isGrounded && !movementLocked)) {//running frames
                window.draw(playerSpriteRun);
            }
            if (playerAlive && Keyboard::isKeyPressed(Keyboard::K)
                && (isGrounded)&& movementLocked) {//ko(shooting) frames
                window.draw(playerSpriteKo);
            }
            if (!isGrounded) {
                window.draw(playerSpriteSuperJump);//super jump frames
            }
            for (auto& b : bullets) window.draw(b.shape);// draw all bullets
        }
        if(currentpage==17)
        {
            window.draw(sprite23);
            window.draw(sprite20);
            window.draw(sprite21);
            window.draw(sprite22);
             if (playerAlive&& isGrounded&& !Keyboard::isKeyPressed(Keyboard::A) && !Keyboard::isKeyPressed(Keyboard::D) && !Keyboard::isKeyPressed(Keyboard::K) ) {//standing frame
                 window.draw(playerSprite);
                }
            if((playerAlive && Keyboard::isKeyPressed(Keyboard::D) && isGrounded&& !movementLocked) || (playerAlive && Keyboard::isKeyPressed(Keyboard::A)&& isGrounded && !movementLocked)) {//running frames
                window.draw(playerSpriteRun);
            }
            if (playerAlive && Keyboard::isKeyPressed(Keyboard::K)
                && (isGrounded)&& movementLocked) {//ko(shooting) frames
                window.draw(playerSpriteKo);
            }
            if (!isGrounded) {
                window.draw(playerSpriteSuperJump);//super jump frames
            }  
            if ((enemy2Alive && enemy2IsWalking==1 && destanceToPlayer>100)) { window.draw(enemy3SpriteWalk);}else if ((enemy2Alive && destanceToPlayer<100)) { window.draw(enemy3SpriteShoot);}
            for (auto& b : bullets) window.draw(b.shape);// draw all bullets
        }

        if(currentpage>=1&&currentpage<=17){
        //draw health bars
        if (playerHealth==0){
            window.draw(hp0Sprite);
        }else if (playerHealth==1){
            window.draw(hp1Sprite);
        }else if (playerHealth==2){
            window.draw(hp2Sprite);
        }else if (playerHealth==3){
            window.draw(hp3Sprite);
        }else if (playerHealth==4){
            window.draw(hp4Sprite);
        }else if (playerHealth==5){
            window.draw(hp5Sprite);
        }else if (playerHealth==6){
            window.draw(hp6Sprite);
        }
        }

        if (currentpage==0)
        {
            window.draw(spritePage0);
            window.draw(playNowBtn);

        }
        
        // trieller page draw
        if(currentpage==-1){
            window.draw(t0_1); 
        }
        if (currentpage==-2)
        {
            window.draw(t0_1);
        }
        if (currentpage==-3)
        {
            window.draw(t0_2);
        }
        if (currentpage==-4)
        {
            window.draw(t0_3);
        }
        if (currentpage==-5)
        {
            window.draw(t0_1);
        }
        if (currentpage==-6)
        {
            window.draw(t1);
        }
        if (currentpage==-7)
        {
            window.draw(t2);
        }
        if (currentpage==-8)
        {
            window.draw(t3);
        }
       if (currentpage==-9)
        {
            window.draw(t4);
        }
        if (currentpage==-10)
        {
            window.draw(t5);
        }
       if (currentpage==-11)
        {
            window.draw(t6);
        }
        if (currentpage==-12)
        {
            window.draw(t7);
        }
        if (currentpage==-13)
        {
            window.draw(t8);
        }
        if (currentpage==-14)
        {
            window.draw(t9);
        }
       if (currentpage==-15)
        {
            window.draw(t10);
        }
        if (currentpage==-16)
        {
            window.draw(t11);
        }
       if (currentpage==-17)
        {
            window.draw(t12);
        }
        if(currentpage==-18)
        {
            window.draw(t13);
        }
        if(currentpage==-19)
        {
            window.draw(t14);
        }
        if(currentpage==-20)
        {
            window.draw(t15);
        }
        if(currentpage==-21)
        {
            window.draw(t16);
        }
        if(currentpage==-22)
        {
            window.draw(t17);
        }
        if(currentpage==-23)
        {
            window.draw(t18);
        }
        if(currentpage==-24)
        {
            window.draw(t19);
        }
        if(currentpage==-25)
        {
            window.draw(t20);
        }
        if (currentpage==-26)
        {
            window.draw(t0_1);
        }

        if (currentpage<=-5 && currentpage>=-26)
        {
        window.draw(trailerwall1);
        window.draw(trailerwall2);
        }
        if (currentpage==18)
        {
            window.draw(t0_1); 
        }
        if (currentpage==19)
        {
            window.draw(lt1);
            window.draw(trailerwall1);
            window.draw(trailerwall2);
        }
        if (currentpage==20)
        {
            window.draw(lt2);
            window.draw(trailerwall1);
            window.draw(trailerwall2);
        }
        if (currentpage==21)//
        {
            window.draw(t0_1); 
        }
        if (currentpage==22)
        {
            window.draw(lt3);
            window.draw(trailerwall1);
            window.draw(trailerwall2);
        }
        if (currentpage==23)
        {
            window.draw(lt4);
            window.draw(trailerwall1);
            window.draw(trailerwall2);
        }
        if (currentpage==24)
        {
            window.draw(t0_3);
        }
        

        window.display();
    }

    return 0;
}
