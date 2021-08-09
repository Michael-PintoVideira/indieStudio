/*
** EPITECH PROJECT, 2021
** B-YEP-400-PAR-4-1-indiestudio-edouard.courty
** File description:
** Raylib
*/

#include "Raylib.hpp"
#include <fstream>
#include "handle_path.hpp"

Raylib::Raylib()
{
}

Raylib::Raylib(int nbPlayers, bool powers)
{
    Path path;
    Vector3 position = { 0.0f, 100.0f, 53.0f };
    Vector3 target = { 32.0f, 1.0f, 53.0f };
    Vector3 up = { 0.0f, 1.0f, 0.0f };
    _pow = powers;
    std::cout << _pow << std::endl;
    _cam = { 0 };
    _cam.position = position;
    _cam.target = target;
    _cam.up = up;
    _cam.fovy = 45.0f;
    _cam.projection = CAMERA_PERSPECTIVE;
    std::string map = "Ressources/map.txt";
    std::string background = "Ressources/background_background.txt";
    std::string objBuilding03 = "Ressources/TallBuilding03.obj";
    std::string imgBuilding03 = "Ressources/TallBuilding03.png";
    std::string objBuilding01 = "Ressources/SmallBuilding01.obj";
    std::string imgBuilding01 = "Ressources/SmallBuilding01.png";
    std::string objBuilding02 = "Ressources/SmallBuilding02.obj";
    std::string imgBuilding02 = "Ressources/SmallBuilding02.png";
    std::string objPatchouli = "Ressources/patchouli.obj";
    std::string imgPatchouli = "Ressources/patchouli.png";
    std::string objTorch = "Ressources/VoxelDungeonSet/Obj/torch.obj";
    std::string imgTorch = "Ressources/VoxelDungeonSet/Obj/torch.png";
    std::string objSlime = "Ressources/VoxelDungeonSet/Obj/slime.obj";
    std::string imgSlime = "Ressources/VoxelDungeonSet/Obj/slime.png";
    std::string floor = "Ressources/CLAYBRICKS.png";
    std::string destroy_b = "Ressources/brick_sand.png";
    std::string objBonus01 = "Ressources/VoxelDungeonSet/Obj/book_red.obj";
    std::string imgBonus01 = "Ressources/VoxelDungeonSet/Obj/book_red.png";
    std::string objBonus02 = "Ressources/VoxelDungeonSet/Obj/mana_potion.obj";
    std::string imgBonus02 = "Ressources/VoxelDungeonSet/Obj/mana_potion.png";
    std::string objBonus03 = "Ressources/VoxelDungeonSet/Obj/sword.obj";
    std::string imgBonus03 = "Ressources/VoxelDungeonSet/Obj/sword.png";
    std::string objBomb = "Ressources/VoxelDungeonSet/Obj/slime.obj";
    std::string imgBomb = "Ressources/VoxelDungeonSet/Obj/slime.png";
    std::string sand1 = "Ressources/first.png";
    std::string sand2 = "Ressources/second.png";
    std::string sand3 = "Ressources/third.png";

    std::string objHeart = "Ressources/VoxelDungeonSet/Obj/heart.obj";
    std::string imgHeart = "Ressources/VoxelDungeonSet/Obj/heart.png";
    if (path.isRoot() == false) {
        std::string backOne = path.getRoot();
        map.insert(0, backOne);
        background.insert(0, backOne);
        objBuilding03.insert(0, backOne);
        imgBuilding03.insert(0, backOne);
        objBuilding01.insert(0, backOne);
        imgBuilding01.insert(0, backOne);
        objBuilding02.insert(0, backOne);
        imgBuilding02.insert(0, backOne);
        objPatchouli.insert(0, backOne);
        imgPatchouli.insert(0, backOne);
        objTorch.insert(0, backOne);
        imgTorch.insert(0, backOne);
        objSlime.insert(0, backOne);
        imgSlime.insert(0, backOne);
        objBonus01.insert(0, backOne);
        imgBonus01.insert(0, backOne);
        objBonus02.insert(0, backOne);
        imgBonus02.insert(0, backOne);
        objBonus03.insert(0, backOne);
        imgBonus03.insert(0, backOne);
        objBomb.insert(0, backOne);
        imgBomb.insert(0, backOne);
        floor.insert(0, backOne);
        destroy_b.insert(0, backOne);
        sand1.insert(0, backOne);
        sand2.insert(0, backOne);
        sand3.insert(0, backOne);
        objHeart.insert(0, backOne);
        imgHeart.insert(0, backOne);
    }
    this->setMap(map);
    this->setMapBackground(background);
    this->addModel("TallBuilding", Model_enc(objBuilding03, imgBuilding03));
    this->addModel("SmallBuilding1", Model_enc(objBuilding01, imgBuilding01));
    this->addModel("SmallBuilding2", Model_enc(objBuilding02, imgBuilding02));
    this->addModel("Player1", Model_enc(objPatchouli, imgPatchouli));
    this->addModel("Bomb", Model_enc(objTorch, imgTorch));
    this->addModel("Boom", Model_enc(objSlime, imgSlime));
    this->addTexture("Claybricks", LoadTexture(floor.c_str()));
    this->addTexture("destru_bloc", LoadTexture(destroy_b.c_str()));
    this->addModel("bonus1", Model_enc(objBonus01, imgBonus01));
    this->addModel("bonus2", Model_enc(objBonus02, imgBonus02));
    this->addModel("bonus3", Model_enc(objBonus03, imgBonus03));
    this->addModel("heart", Model_enc(objHeart, imgHeart));
    this->addModel("Bomb", Model_enc(objBomb, imgBomb));
    this->addTexture("sand1", LoadTexture(sand1.c_str()));
    this->addTexture("sand2", LoadTexture(sand2.c_str()));
    this->addTexture("water1", LoadTexture(sand3.c_str()));
    this->fillPlayers(nbPlayers);
    this->setMoves();
    start_timer_bonus1();
    start_timer_bonus2();
    start_timer_bonus3();
    looser_winner = 0;
    SetTargetFPS(60);
    SetCameraMode(_cam, CAMERA_FREE);
}


void Raylib::setMapBackground(const std::string& path)
{
    std::ifstream file(path.c_str());
    std::string str;
    while (std::getline(file, str))
        _backgroundMap.push_back(str);
}

void Raylib::print_the_heart(){
    int i = 0;
    std::vector<float> pos = {50.0f, 0.5f + 10, 0.0f};

    for(;i <_players.size(); i++){
        for(int y = 0; y < _players[i].return_life_player(); y++){
            this->drawModel(_models["heart"].getModel(), {pos[0], pos[1], pos[2]}, 3);
            pos[0] += 5;
        }
        pos[2] += 10;
        pos[0] = 50;
    }
}

Raylib::~Raylib()
{
    CloseWindow();
}

void Raylib::setMoves()
{
    _moves.push_back({{"UP", KEY_UP}, {"DOWN", KEY_DOWN}, {"LEFT", KEY_LEFT}, {"RIGHT", KEY_RIGHT}, {"BOMB", KEY_RIGHT_SHIFT}});
    _moves.push_back({{"UP", KEY_E}, {"DOWN", KEY_D}, {"LEFT", KEY_S}, {"RIGHT", KEY_F}, {"BOMB", KEY_G}});
    _moves.push_back({{"UP", KEY_I}, {"DOWN", KEY_K}, {"LEFT", KEY_J}, {"RIGHT", KEY_L}, {"BOMB", KEY_M}});
    _moves.push_back({{"UP", KEY_F1}, {"DOWN", KEY_F2}, {"LEFT", KEY_F3}, {"RIGHT", KEY_F4}, {"BOMB", KEY_F5}});
}

void Raylib::update()
{
    ClearBackground(DARKGREEN);
}

void Raylib::upCam()
{
    UpdateCamera(&_cam);
}

void Raylib::upMap()
{
    for (auto & player : _players) {
        auto bombs = player.getBombs();
        for (auto & bomb : bombs) {
            auto pos = bomb.getPos();
            if (_map[pos.first][pos.second] != 'O')
                _map[pos.first][pos.second] = 'O';
        }
    }
}

void Raylib::setMap(const std::string& path)
{
    std::ifstream file(path.c_str());
    std::string str;
    while (std::getline(file, str))
        _map.push_back(str);
}

void Raylib::changeMap(int x, int y, char to_change){
    _map[x][y] = to_change;
}

void Raylib::disMap()
{
    std::vector<float> pos = {0.0f, 0.5f, 0.0f};
    for(int x = 0; x < _map.size(); x++){
        for(int y = 0; _map[x][y] != '\0'; y++){
            if(_map[x][y] == 'X')
                this->drawModel(_models["SmallBuilding1"].getModel(), {pos[0], pos[1], pos[2] + 0.25f}, 1);
            if(_map[x][y] == 'G')
                this->drawModel(_models["SmallBuilding2"].getModel(), {pos[0], pos[1], pos[2] + 0.25f}, 1);
            if(_map[x][y] == 'J')
                this->drawModel(_models["TallBuilding"].getModel(), {pos[0] + 1.0f, pos[1], pos[2]}, 1);
            if (_map[x][y] == 'O')
                this->drawModel(_models["Bomb"].getModel(), {pos[0], pos[1], pos[2]}, 1);
            if (_map[x][y] == 'E')
                this->drawModel(_models["Boom"].getModel(), {pos[0], pos[1], pos[2]}, 1);
            if (_map[x][y] == 'd')
                this->drawCube("destru_bloc", {pos[0], pos[1] + 2, pos[2]});
            if (_map[x][y] == '1' && _pow)
                this->drawModel(_models["bonus1"].getModel(), {pos[0], pos[1] + 1, pos[2]}, 3);
            if (_map[x][y] == '2' && _pow)
                this->drawModel(_models["bonus2"].getModel(), {pos[0] - 0.5f, pos[1] + 1, pos[2] - 1.0f}, 3);
            if (_map[x][y] == '3' && _pow)
                this->drawModel(_models["bonus3"].getModel(), {pos[0], pos[1] + 1, pos[2]}, 3);
            this->drawCube("Claybricks", {pos[0], pos[1], pos[2]});
            pos[2] += 2;
        }
        pos[0] += 2;
        pos[2] = 0;
    }
}

void Raylib::print_backgroud(int choiceOfTheTexture){
    std::vector<float> pos = {-30.0f, 0.5f, -45.0f};
    if(choiceOfTheTexture == 1)
        for(int x = 0; x < _backgroundMap.size(); x++){
            for(int y = 0; _backgroundMap[x][y] != '\0'; y++){
                if(_backgroundMap[x][y] == '1')
                    this->drawCube("sand1", {pos[0], pos[1] - 2, pos[2]});
                if(_backgroundMap[x][y] == '2')
                    this->drawCube("sand2", {pos[0], pos[1] - 4, pos[2]});
                if(_backgroundMap[x][y] == '3')
                    this->drawCube("water1", {pos[0], pos[1] - 6, pos[2]});
                pos[2] += 2;
            }
            pos[0] += 2;
            pos[2] = -45;
        }

}


void Raylib::disPlayers()
{
    for (auto & it : _players){
        if(it.return_life_player() > 0)
            it.display(_models[it.getType()].getModel());
    }
}

void Raylib::addModel(const std::string& type, const Model_enc& model)
{
    _models.insert({type, model});
}

void Raylib::addTexture(const std::string& type, const Texture2D& texture)
{
    _texts.insert({type, texture});
}

void Raylib::fillPlayers(const int& nbPlayers)
{
    this->addPlayer("Player1", 'P');
    if (nbPlayers > 1) this->addPlayer("Player1", 'L');
    if (nbPlayers > 2) this->addPlayer("Player1", 'A');
    if (nbPlayers > 3) this->addPlayer("Player1", 'Y');
}

void Raylib::addPlayer(const std::string& type, const char& mark)
{
    _players.push_back(Player(_map, type, mark));
}

Camera3D Raylib::getCam() const
{
    return _cam;
}

std::vector<std::string> Raylib::getMap() const
{
    return _map;
}

Model Raylib::getModel(const std::string& type)
{
    return _models[type].getModel();
}

void Raylib::drawModel(const Model& model, const Vector3& pos, float len)
{
    DrawModelEx(model, pos, {0.0f, 0.0f, 0.0f}, 1.0, {len, len, len}, WHITE);
}

void Raylib::drawCube(const std::string& type, const Vector3& pos)
{
    DrawCubeTexture(_texts[type], pos, 2.0f, 2.0, 2.0f, WHITE);
}

void Raylib::move()
{
    for (int i = 0; i != _players.size(); i++){
        if(_players[i].return_life_player() > 0){
            if (IsKeyDown(_moves[i]["LEFT"]) && _players[i].return_cant_moove() != 5){
                if (_players[i].canMove(1, 1, _map)){
                    _players[i].move("LEFT");
                    if(_players[i].return_had_bonus() == 1){
                        _players[i].set_bonus(4);
                        _map[_players[i].return_x()/2][(_players[i].return_y() -1)/2] = '*';
                        start_timer_bonus1();
                    }
                    if(_players[i].return_had_bonus() == 2){
                        _players[i].set_bonus(5);
                        _map[_players[i].return_x()/2][(_players[i].return_y() -1)/2] = '*';
                        start_timer_bonus2();
                    }
                    if(_players[i].return_had_bonus() == 3){
                        _players[i].set_bonus(6);
                        _map[_players[i].return_x()/2][(_players[i].return_y() -1)/2] = '*';
                        start_timer_bonus3();
                    }
                    _players[i].set_cant_moove(0);
                }
                else {
                        _players[i].boing_collision_y(1);
                    _players[i].set_cant_moove(5);
                    }
                _players[i].rotate("LEFT");
            }
            if (IsKeyDown(_moves[i]["RIGHT"]) && _players[i].return_cant_moove() != 2) {
                if (_players[i].canMove(1, 1, _map)){
                    if(_players[i].return_had_bonus() == 1){
                        _players[i].set_bonus(4);
                        _map[_players[i].return_x()/2][(_players[i].return_y() + 1)/2] = '*';
                        start_timer_bonus1();
                    }
                    if(_players[i].return_had_bonus() == 2){
                        _players[i].set_bonus(5);
                        _map[_players[i].return_x()/2][(_players[i].return_y() + 1)/2] = '*';
                        start_timer_bonus2();
                    }
                    if(_players[i].return_had_bonus() == 3){
                        _players[i].set_bonus(6);
                        _map[_players[i].return_x()/2][(_players[i].return_y() + 1)/2] = '*';
                        start_timer_bonus3();
                    }
                    _players[i].move("RIGHT");
                    _players[i].set_cant_moove(0);
                }
                else {
                        _players[i].boing_collision_y(-1);
                    _players[i].set_cant_moove(2);
                }
                _players[i].rotate("RIGHT");
            }
            if (IsKeyDown(_moves[i]["DOWN"]) && _players[i].return_cant_moove() != 3) {
                if (_players[i].canMove(1, 1, _map)){
                    if(_players[i].return_had_bonus() == 1){
                        _players[i].set_bonus(4);
                        _map[(_players[i].return_x()-1)/2][(_players[i].return_y())/2] = '*';
                        start_timer_bonus1();
                    }
                    if(_players[i].return_had_bonus() == 2){
                        _players[i].set_bonus(5);
                        _map[(_players[i].return_x()-1)/2][(_players[i].return_y())/2] = '*';
                        start_timer_bonus2();
                    }
                    if(_players[i].return_had_bonus() == 3){
                        _players[i].set_bonus(6);
                        _map[(_players[i].return_x()-1)/2][(_players[i].return_y())/2] = '*';
                        start_timer_bonus3();
                    }
                    _players[i].move("DOWN");
                    _players[i].set_cant_moove(0);
                }
                else{ _players[i].boing_collision_x(1);
                        _players[i].set_cant_moove(3);}
                _players[i].rotate("DOWN");
            }
            if (IsKeyDown(_moves[i]["UP"]) && _players[i].return_cant_moove() != 4) {
                if (_players[i].canMove(1, 1, _map)){
                    if(_players[i].return_had_bonus() == 1){
                        _players[i].set_bonus(0);
                        _map[(_players[i].return_x() + 1)/2][(_players[i].return_y())/2] = '*';
                        start_timer_bonus1();
                    }
                    if(_players[i].return_had_bonus() == 2){
                        _players[i].set_bonus(0);
                        _map[(_players[i].return_x() + 1)/2][(_players[i].return_y())/2] = '*';
                        start_timer_bonus2();
                    }
                    if(_players[i].return_had_bonus() == 3){
                        _players[i].set_bonus(0);
                        _map[(_players[i].return_x() + 1)/2][(_players[i].return_y())/2] = '*';
                        start_timer_bonus3();
                    }
                    _players[i].move("UP");
                    _players[i].set_cant_moove(0);
                }
                else{  _players[i].boing_collision_x(-1);
                    _players[i].set_cant_moove(4);}
                _players[i].rotate("UP");
            }
        }
    }
}

void Raylib::explosion_gestion(){
    for (int i = 0; i != _players.size(); i++)
        _players[i].is_it_in_fire(getMap());
}

void Raylib::placeBomb()
{
    for (int i = 0; i != _players.size(); i++)
        if (IsKeyPressed(_moves[i]["BOMB"]))
            _players[i].placeBomb(_map);
}

void Raylib::disBoom(const std::pair<int, int>& pos, int range)
{
    int x = pos.first, y = pos.second;
    for(int i = 0; i <= range && _map[x][i + y] != '\0'; i++)
        if( _map[x][y + i] != 'X' && _map[x][y + 1] != 'J' && _map[x][y + 1] != 'G')
            _map[x][y + i] = 'E';
    for(int i = 0; i <= range && y - i != 0; i++)
        if( _map[x][y - i] != 'X' && _map[x][y - i] != 'J' && _map[x][y - i] != 'G')
            _map[x][y - i] = 'E';
    for(int i = 0; i <= range && x + i < _map.size(); i++)
        if( _map[x + i][y] != 'X' && _map[x + i][y] != 'J' && _map[x + i][y] != 'G')
            _map[x + i][y] = 'E';
    for(int i = 0; i <= range && x - i != 0; i++)
        if( _map[x - i][y] != 'X' && _map[x - i][y] != 'J' && _map[x - i][y] != 'G')
            _map[x - i][y] = 'E';
    _map[x][y] = '*';
}

void Raylib::delBoom(const std::pair<int, int>& pos, int range)
{
    int x = pos.first, y = pos.second;
    for(int i = 0; i <= range && _map[x][i + y] != '\0'; i++)
        if( _map[x][y + i] == 'E')
            _map[x][y + i] = '*';
    for(int i = 0; i <= range && y - i != 0; i++)
        if( _map[x][y - i] == 'E')
            _map[x][y - i] = '*';
    for(int i = 0; i <= range && x + i < _map.size(); i++)
        if( _map[x + i][y] == 'E')
            _map[x + i][y] = '*';
    for(int i = 0; i <= range && x - i != 0; i++)
        if( _map[x - i][y] == 'E')
            _map[x - i][y] = '*';
    _map[x][y] = '*';
}

void Raylib::explode()
{
    int len;
    for (auto & player : _players) {
        std::vector<Bomb> bombs = player.getBombs();
        len = player.return_bomber_len();
        for (int it = 0; it != bombs.size(); it++) {
            std::chrono::duration<double> timer = std::chrono::system_clock::now() - bombs[it].getStart();
            if (timer.count() > 3)
                this->disBoom(bombs[it].getPos(), len);
            if (timer.count() > 3.5) {
                this->delBoom(bombs[it].getPos(), len);
                player.delBomb(it);
            }
        }
    }
}

/*-----------------------gestion des bonus---------------------*/

void Raylib::put_random_1(){
    int pos1 = 0;
    int pos2 = 0;
    int len_map_1 = _map.size();
    int len_map_2 = 0;

    for(; _map[1][len_map_2] != '\0'; len_map_2++);
    srand (time(NULL) + 4684);
    pos1 = (rand() % len_map_1);
    if(pos1 == _map.size())  /*if(ray.getLooserWinner() == 1){
            DrawText(TextFormat("GAME ENDED"), 200, 80, 20, RED);
        }*/
        pos1 -= 1;
    srand (time(NULL) + 44);
    std::cout << len_map_2 << "&&" << len_map_1 << std::endl;
    pos2 = rand() % len_map_2;
    for(;pos1 < _map.size(); pos1++){
        for(; _map[pos1][pos2] != '\0'; pos2++)
            if(_map[pos1][pos2] == '*'){
                    _map[pos1][pos2] = '1';
                    return;
            }
        pos2 = 0;
    }
    _map[1][1] = '1';
}

void Raylib::put_random_2(){
    int pos1 = 0;
    int pos2 = 0;
    int len_map_1 = _map.size();
    int len_map_2 = 0;

    for(; _map[1][len_map_2]; len_map_2++);
    srand (time(NULL) + 44848);
    pos1 = rand() % len_map_1;
    srand (time(NULL) + 48484);
    pos2 = rand() % len_map_2;
    for(;pos1 < _map.size(); pos1++){
        for(; _map[pos1][pos2]; pos2++)
            if(_map[pos1][pos2] == '*'){
                    _map[pos1][pos2] = '2';
                    return;
            }
        pos2 = 0;
    }
    _map[1][1] = '2';
}

void Raylib::put_random_3(){
    int pos1 = 0;
    int pos2 = 0;
    int len_map_1 = _map.size();
    int len_map_2 = 0;

    for(; _map[1][len_map_2]; len_map_2++)
    srand (time(NULL));
    pos1 = rand() % len_map_1;
    srand (time(NULL));
    pos2 = rand() % len_map_2;
    for(;pos1 < _map.size(); pos1++){
        for(; _map[pos1][pos2]; pos2++)
            if(_map[pos1][pos2] == '*'){
                    _map[pos1][pos2] = '3';
                    for(len_map_2 = 0; len_map_2 < _map.size(); len_map_2++)
                        std::cout<< _map[len_map_2] << std::endl;
                    return;
            }
        pos2 = 0;
    }
    _map[1][1] = '3';
}

void Raylib::start_timer_bonus1(){
   _timer_bonus1_beg = std::chrono::system_clock::now();
}

void Raylib::start_timer_bonus2(){
   _timer_bonus2_beg = std::chrono::system_clock::now();
}
void Raylib::start_timer_bonus3(){
   _timer_bonus3_beg = std::chrono::system_clock::now();
}

void Raylib::bonus_gestion()
{
    if (!_pow) return;
    int nbr_b1 = 0;
    int nbr_b2 = 0;
    int nbr_b3 = 0;
    std::chrono::duration<double> diff;

    for(int i = 0; i < _map.size(); i++)
        for(int y = 0; _map[i][y] != '\0'; y++){
            if (_map[i][y] == '1')
                nbr_b1++;
            if (_map[i][y] == '2')
                nbr_b2++;
            if (_map[i][y] == '3')
                nbr_b3++;
        }
    if(nbr_b1 == 0){
        _timer_bonus1_end = std::chrono::system_clock::now();
        diff = _timer_bonus1_end - _timer_bonus1_beg;
        if(diff.count() > 5.0)
            put_random_1();
    }
    if(nbr_b2 == 0){
        _timer_bonus2_end = std::chrono::system_clock::now();
        diff = _timer_bonus2_end - _timer_bonus2_beg;
        if(diff.count() > 5.0)
            put_random_2();
    }
    if(nbr_b3 == 0){
        _timer_bonus3_end = std::chrono::system_clock::now();
        diff = _timer_bonus3_end - _timer_bonus3_beg;
        if(diff.count() > 5.0)
            put_random_3();
    }
}


/*gestioon defaite*/

void Raylib::loosing(){
    int howMany = 0;

    for (int i = 0; i != _players.size(); i++)
        if(_players[i].return_life_player() <= 0)
            howMany++;
    
    if(howMany < 2)
        looser_winner = 1;
}

int Raylib::getLooserWinner()
{
    return looser_winner;
}