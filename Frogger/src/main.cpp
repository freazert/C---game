/*This source code copyrighted by Lazy Foo' Productions (2004-2015)
and may not be redistributed without written permission.*/

//Using SDL and standard IO

#include<Factory.h>
#include<Game.h>
#include<SDLFact.h>
#include<stdio.h>
#include <iostream>
using namespace Frogger;
using namespace SDL;
int main( int argc, char* args[] )
{

	//game starten met SDL
   Frogger::Factory* fac = new SDLFact();
   Game::GetGameInstance(fac)->Start();

   //opruimen
   delete fac;

   return 0;
}
