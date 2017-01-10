#include "GameWorld.h"

GameWorld::GameWorld (ApplicationMode mode) : asset_manager(std::make_shared<GameAssetManager>(mode)) {
	//Floor of the voxel world
	for(int j=0; j<100; j++) {
		for(int i=0; i<100; i++) {
			auto cube = std::make_shared<CubeAsset>(i,0, j);

			if(i % 2 == 0 && j % 2 == 0){
				cube->setColour(1,0,0);		//red

			} else if (i % 2 == 1 && j % 2 == 1){
				cube->setColour(1,0,0);		//red

			} else {
				cube->setColour(0,0,1);		//blue
			}

			asset_manager->AddAsset(cube);			
		}

	/*//Front wall
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
}
}
void GameWorld::Draw() {
  asset_manager->Draw();
}


