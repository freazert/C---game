/*
 * Stopwatch.h
 *
 *  Created on: 15-mei-2016
 *      Author: Kris
 */

#ifndef FROGGER_STOPWATCH_H_
#define FROGGER_STOPWATCH_H_
namespace Frogger
{
	class Stopwatch {
	public:
		Stopwatch();
		virtual ~Stopwatch();

		//milliseconden krijgen
		virtual int GetMili() = 0;
		//seconden van gameplay laten stijgen.
		virtual void doEvent() = 0;

		//getter maken
		//seconden van de gameplay krijgen.
		int time;

	protected:

	private:
	};
}
#endif /* FROGGER_STOPWATCH_H_ */
