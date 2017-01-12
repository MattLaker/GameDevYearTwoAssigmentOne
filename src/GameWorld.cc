#include "GameWorld.h"
#include "octree.h"
GameWorld::GameWorld (ApplicationMode mode) : asset_manager(std::make_shared<GameAssetManager>(mode)) {
	
	
	for(int i=0; i<16; i++) {		
		for(int j=0; j<16; j++) {
			for(int k=0; k<16; k++) {
				//if( cubes.at(i,j,k) != NULL) {
					//auto cube = std::make_shared<CubeAsset>(i, j, k);
					//asset_manager->AddAsset(cube);
				//}
			}
		}
	}
}

	/*int world_x = 10;
	int world_y = 10;
	int world_z = 10;

	bool cubes [world_x][world_y][world_z]; 
	for(int i=0; i<world_x; i++) {		
		for(int j=0; j<world_y; j++) {
			for(int k=0; k<world_z; k++) {
				if(j == 0 || k == 9) {
					cubes[i][j][k] = true;
				} else {
					cubes[i][j][k] = false;
				}
			}
		}
	}

	for(int i=0; i<world_x; i++) {		//adds all active cubes to the draw list
		for(int j=0; j<world_y; j++) {
			for(int k=0; k<world_z; k++) {
				if(cubes[i][j][k] == true) {
					auto cube = std::make_shared<CubeAsset>(i, j-1, k);
					if(i % 2 == 0 && j % 2 == 0 && k % 2 == 0){
						cube->setColour(0.7,0.0,0.0);		//red
					} else if (i % 2 == 1 && j % 2 == 1 && k % 2 == 1){
						cube->setColour(0.7,0.0,0.0);		//red
					} else {
						cube->setColour(0.0,0.0,0.7);		//blue
					}
					asset_manager->AddAsset(cube);
				}
			}
		}
	}
		
}	*/
/*//Floor of the voxel world
	for(int j=2; j>0; j--) {
		for(int i=2; i>0; i--) {
			auto cube = std::make_shared<CubeAsset>(i*2,0, j*2);

			if(i % 2 == 0 && j % 2 == 0){
				cube->setColour(1,0,0);		//red

			} else if (i % 2 == 1 && j % 2 == 1){
				cube->setColour(1,0,0);		//red

			} else {
				cube->setColour(0,0,1);		//blue
			}

			asset_manager->AddAsset(cube);			
		}

	//Front wall
	for(int j=0; j<10; j++) {
		for(int i=0; i<10; i++) {
			auto cube = std::make_shared<CubeAsset>(i,j,10);
			asset_manager->AddAsset(cube);	
	}
	}
	//Back wall
	for(int j=0; j<10; j++) {
		for(int i=0; i<10; i++) {
			auto cube = std::make_shared<CubeAsset>(i,j,0);
			asset_manager->AddAsset(cube);	
	}
	}

	//Left wall
	for(int j=0; j<10; j++) {
		for(int i=0; i<10; i++) {
			auto cube = std::make_shared<CubeAsset>(0,j,i);
			asset_manager->AddAsset(cube);	
	}
	}

	//Right wall
	for(int j=0; j<10; j++) {
		for(int i=0; i<10; i++) {
			auto cube = std::make_shared<CubeAsset>(10,j,i);
			asset_manager->AddAsset(cube);	
	}
	}*/
//}
//}
void GameWorld::Draw() {
 // asset_manager->Draw();
}






