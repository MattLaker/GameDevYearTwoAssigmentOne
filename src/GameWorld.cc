#include "GameWorld.h"

/*
* 
*/
GameWorld::GameWorld (ApplicationMode mode) : asset_manager(std::make_shared<GameAssetManager>(mode)) {
	int world_x = 10;
	int world_y = 10;
	int world_z = 10;

	bool cubes [world_x][world_y][world_z]; //creates a room with the roof open.
	for(int i=0; i<world_x; i++) {		
		for(int j=0; j<world_y; j++) {
			for(int k=0; k<world_z; k++) {
				if(j == 0 || k == 9 || k ==0 || i == 0 || i == 9) {
					cubes[i][j][k] = true;
				} else {
					cubes[i][j][k] = false;
				}
			}
		}
	}

	for(int x=0; x<world_x; x++) {		//adds all active cubes to the draw list and sets their colour to a chequered pattern.
		for(int y=0; y<world_y; y++) {
			for(int z=0; z<world_z; z++) {
				if(cubes[x][y][z] == true) {
					auto cube = std::make_shared<CubeAsset>(x, y-1, z);
					
					if(x % 2 == 0 && y % 2 == 0 ){
						cube->setColour(0.7,0.0,0.0);		//red
					} else if (x % 2 == 1 && y % 2 == 1){
						cube->setColour(0.7,0.0,0.0);		//red
					} else if(x % 2 == 0 && z % 2 == 0 ){
						cube->setColour(0.7,0.0,0.0);		//red
					} else if (x % 2 == 1 && z % 2 == 1){
						cube->setColour(0.7,0.0,0.0);
					} else {
						cube->setColour(0.0,0.0,0.7);		//blue
					}
					asset_manager->AddAsset(cube);
				}
			}
		}
	}
		
}	

/*
* calls draw on the asset manager to iterate through the draw list drawing
* all assets to the screen  
*/
void GameWorld::Draw() {
  asset_manager->Draw();
}

/*
* passes the move forward call to the asset manager  
*/
void GameWorld::move_forward() {
  asset_manager->move_forward();
}
/*
* passes the move backward call to the asset manager  
*/
void GameWorld::move_backward() {
  asset_manager->move_backward();
}
/*
* passes the move left call to the asset manager  
*/
void GameWorld::move_left() {
  asset_manager->move_left();
}
/*
* passes the move right call to the asset manager  
*/
void GameWorld::move_right() {
  asset_manager->move_right();
}
/*
* passes the rotate up call to the asset manager  
*/
void GameWorld::rotate_up() {
  asset_manager->rotate_up();
}
/*
* passes the rotate down call to the asset manager  
*/void GameWorld::rotate_down() {
  asset_manager->rotate_down();
}
/*
* passes the move rotate left to the asset manager  
*/
void GameWorld::rotate_left() {
  asset_manager->rotate_left();
}
/*
* passes the rotate right call to the asset manager  
*/
void GameWorld::rotate_right() {
  asset_manager->rotate_right();
}




