# g++ -o main main.cpp -lsfml-graphics -lsfml-window -lsfml-system 
CPP_FLAGS =  -o main -std=c++14 -lsfml-graphics -lsfml-window -lsfml-system -lsfml-network -lsfml-audio


output: main.o Game.o StateMachine.o State.o AssetManager.o InputManager.o SplashState.o GameState.o MainMenuState.o GameOver.o Pipe.o Land.o Bird.o Collision.o Flash.o HUD.o
	g++ main.o Game.o StateMachine.o State.o AssetManager.o InputManager.o SplashState.o GameState.o GameOver.o Pipe.o Land.o Bird.o MainMenuState.o Collision.o Flash.o HUD.o $(CPP_FLAGS)

main.o: main.cpp 
	g++ -c main.cpp -std=c++14

StateMachine.o: StateMachine.cpp StateMachine.h
	g++ -c StateMachine.cpp -std=c++14

State.o: State.cpp State.h
	g++ -c State.cpp -std=c++14

AssetManager.o: AssetManager.cpp AssetManager.h
	g++ -c AssetManager.cpp -std=c++14

InputManager.o: InputManager.cpp InputManager.h
	g++ -c InputManager.cpp -std=c++14

Game.o: Game.cpp Game.h
	g++ -c Game.cpp -std=c++14

SplashState.o: SplashState.cpp SplashState.h DEFINITIONS.h
	g++ -c SplashState.cpp -std=c++14

MainMenuState.o: MainMenuState.cpp MainMenuState.h DEFINITIONS.h
	g++ -c MainMenuState.cpp -std=c++14

GameState.o: GameState.cpp GameState.h DEFINITIONS.h
	g++ -c GameState.cpp -std=c++14

GameOver.o: GameOver.cpp GameOver.h DEFINITIONS.h
	g++ -c GameOver.cpp -std=c++14

Pipe.o: Pipe.cpp Pipe.h DEFINITIONS.h
	g++ -c Pipe.cpp -std=c++14

Land.o: Land.cpp Land.h DEFINITIONS.h
	g++ -c Land.cpp -std=c++14

Bird.o: Bird.cpp Bird.h DEFINITIONS.h
	g++ -c Bird.cpp -std=c++14

Collision.o: Collision.cpp Collision.h DEFINITIONS.h
	g++ -c Collision.cpp -std=c++14

Flash.o: Flash.cpp Flash.h DEFINITIONS.h
	g++ -c Flash.cpp -std=c++14

HUD.o: HUD.cpp HUD.h DEFINITIONS.h
	g++ -c HUD.cpp -std=c++11

clean:
	rm *.o  main
